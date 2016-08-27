#include "ofxTobiiEyeX.h"
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <assert.h>


static const string smAddonName = "EyeX";

TX_GAZEPOINTDATAEVENTPARAMS ofxTobiiEyeX::smGazePointDataEventParams;
TX_EYEPOSITIONDATAEVENTPARAMS ofxTobiiEyeX::smEyePositionEventParams;
TX_FIXATIONDATAEVENTPARAMS ofxTobiiEyeX::smFixationEventParams;

ofxTobiiEyeX::ofxTobiiEyeX()
{
}

ofxTobiiEyeX::~ofxTobiiEyeX()
{
	if (isInitialized())
	{
		if (isRegisteredGazePointEventHandler())
			unregisterGazePointEventHandler();

		if (isRegisteredEyePositionEventHandler())
			unregisterEyePositionEventHandler();

		if (isRegisteredFixationEventHandler())
			unregisterFixationEventHandler();

		close();
	}
}

void TX_CALLCONVENTION ofxTobiiEyeX::OnSnapshotCommitted(TX_CONSTHANDLE hAsyncData, TX_USERPARAM param)
{
	TX_RESULT result = TX_RESULT_UNKNOWN;
	txGetAsyncDataResultCode(hAsyncData, &result);
	assert(result == TX_RESULT_OK || result == TX_RESULT_CANCELLED);
}

void TX_CALLCONVENTION ofxTobiiEyeX::OnEngineConnectionStateChanged(TX_CONNECTIONSTATE connectionState, TX_USERPARAM param)
{
	switch (connectionState) {
	case TX_CONNECTIONSTATE_CONNECTED: {
		bool success;
		ofLogNotice(smAddonName, "The connection state is now CONNECTED (We are connected to the EyeX Engine)");

		success = txCommitSnapshotAsync((TX_HANDLE)param, OnSnapshotCommitted, nullptr) == TX_RESULT_OK;
		if (!success) {
			ofLogError(smAddonName, "Failed to initialize the data stream.");
		}
		else {
			ofLogNotice(smAddonName, "Waiting for eye position data to start streaming...");
		}
	}
		 break;

	case TX_CONNECTIONSTATE_DISCONNECTED:
		ofLogNotice(smAddonName, "The connection state is now DISCONNECTED (We are disconnected from the EyeX Engine)");
		break;

	case TX_CONNECTIONSTATE_TRYINGTOCONNECT:
		ofLogNotice(smAddonName, "The connection state is now TRYINGTOCONNECT (We are trying to connect to the EyeX Engine)");
		break;

	case TX_CONNECTIONSTATE_SERVERVERSIONTOOLOW:
		ofLogWarning(smAddonName, "The connection state is now SERVER_VERSION_TOO_LOW: this application requires a more recent version of the EyeX Engine to run.");
		break;

	case TX_CONNECTIONSTATE_SERVERVERSIONTOOHIGH:
		ofLogWarning(smAddonName, "The connection state is now SERVER_VERSION_TOO_HIGH: this application requires an older version of the EyeX Engine to run.");
		break;
	}
}

void TX_CALLCONVENTION ofxTobiiEyeX::HandleEvent(TX_CONSTHANDLE hAsyncData, TX_USERPARAM param)
{
	TX_HANDLE hEvent = TX_EMPTY_HANDLE;
	TX_HANDLE hBehavior = TX_EMPTY_HANDLE;

	txGetAsyncDataContent(hAsyncData, &hEvent);
	
	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_GAZEPOINTDATA) == TX_RESULT_OK)
	{
		if (txGetGazePointDataEventParams(hBehavior, &smGazePointDataEventParams) != TX_RESULT_OK)
		{
			ofLogError(smAddonName, "Failed to interpret gaze data event packet.");
		}
	}
	
	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_EYEPOSITIONDATA) == TX_RESULT_OK)
	{
		if (txGetEyePositionDataEventParams(hBehavior, &smEyePositionEventParams) != TX_RESULT_OK)
		{
			ofLogError(smAddonName, "Failed to interpret eye position event packet.");
		}
	}

	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_FIXATIONDATA) == TX_RESULT_OK)
	{
		if (txGetFixationDataEventParams(hBehavior, &smFixationEventParams) != TX_RESULT_OK)
		{
			ofLogError(smAddonName, "Failed to interpret fixation event packet.");
		}
	}

	txReleaseObject(&hBehavior);
	txReleaseObject(&hEvent);
}

bool ofxTobiiEyeX::setup()
{
	if (txInitializeEyeX(TX_EYEXCOMPONENTOVERRIDEFLAG_NONE, nullptr, nullptr, nullptr, nullptr) != TX_RESULT_OK)
	{
		ofLogError(smAddonName, "Initialization failed.");
		return false;
	}
	return true;
}

bool ofxTobiiEyeX::close()
{
	if (txUninitializeEyeX() != TX_RESULT_OK)
	{
		ofLogError(smAddonName, "EyeX could not be shut down cleanly. Did you remember to release all handles?");
		return false;
	}
	return true;
}

void ofxTobiiEyeX::update()
{
	if (isRegisteredGazePointEventHandler())
		mGazePointDataEventParams = smGazePointDataEventParams;
	
	if (isRegisteredEyePositionEventHandler())
		mEyePositionEventParams = smEyePositionEventParams;

	if (isRegisteredFixationEventHandler())
		mFixationEventParams = smFixationEventParams;
}

bool ofxTobiiEyeX::unregisterEventHandler(Handle& handle)
{
	bool success = true;

	success &= txUnregisterConnectionStateChangedHandler(handle.hContext, handle.hConnectionStateChangedTicket) == TX_RESULT_OK;
	success &= txUnregisterEventHandler(handle.hContext, handle.hEventHandlerTicket) == TX_RESULT_OK;
	success &= txDisableConnection(handle.hContext) == TX_RESULT_OK;
	success &= txReleaseObject(&handle.hGlobalInteractorSnapshot) == TX_RESULT_OK;
	//success &= txShutdownContext(handle.hContext, TX_CLEANUPTIMEOUT_DEFAULT, TX_FALSE) == TX_RESULT_OK;
	TX_RESULT res = txShutdownContext(handle.hContext, TX_CLEANUPTIMEOUT_DEFAULT, TX_FALSE);
	success &= txReleaseContext(&handle.hContext) == TX_RESULT_OK;

	if (!success)
	{
		ofLogError(smAddonName, "EyeX could not be shut down cleanly.");
	}
	return success;
}

bool ofxTobiiEyeX::registerGazePointEventHandler(const string& InteractorId, TX_GAZEPOINTDATAMODE mode)
{
	auto& handle = mGazePointHandle;
	handle.hConnectionStateChangedTicket = TX_INVALID_TICKET;
	handle.hEventHandlerTicket = TX_INVALID_TICKET;
	TX_CONSTSTRING ID = InteractorId.c_str();
	TX_GAZEPOINTDATAPARAMS params = { mode };
	TX_HANDLE hInteractor = TX_EMPTY_HANDLE;
	bool success = true;

	success &= txCreateContext(&handle.hContext, TX_FALSE) == TX_RESULT_OK;
	success &= txCreateGlobalInteractorSnapshot(handle.hContext, ID, &handle.hGlobalInteractorSnapshot, &hInteractor) == TX_RESULT_OK;
		
	success &= txCreateGazePointDataBehavior(hInteractor, &params) == TX_RESULT_OK;

	success &= txReleaseObject(&hInteractor) == TX_RESULT_OK;
	success &= txRegisterConnectionStateChangedHandler(handle.hContext, &handle.hConnectionStateChangedTicket, OnEngineConnectionStateChanged, handle.hGlobalInteractorSnapshot) == TX_RESULT_OK;
	success &= txRegisterEventHandler(handle.hContext, &handle.hEventHandlerTicket, HandleEvent, nullptr) == TX_RESULT_OK;
	success &= txEnableConnection(handle.hContext) == TX_RESULT_OK;
	
	if (!success)
	{
		ofLogError(smAddonName, "Registing gaze point data event handler was failed.");
	}
	return success;
}

bool ofxTobiiEyeX::registerEyePositionEventHandler(const string& InteractorId)
{
	auto& handle = mEyePositionHandle;
	handle.hConnectionStateChangedTicket = TX_INVALID_TICKET;
	handle.hEventHandlerTicket = TX_INVALID_TICKET;
	TX_CONSTSTRING ID = InteractorId.c_str();
	TX_HANDLE params = TX_EMPTY_HANDLE;
	TX_HANDLE hInteractor = TX_EMPTY_HANDLE;
	bool success = true;

	success &= txCreateContext(&handle.hContext, TX_FALSE) == TX_RESULT_OK;
	success &= txCreateGlobalInteractorSnapshot(handle.hContext, ID, &handle.hGlobalInteractorSnapshot, &hInteractor) == TX_RESULT_OK;

	success &= txCreateInteractorBehavior(hInteractor, &params, TX_BEHAVIORTYPE_EYEPOSITIONDATA) == TX_RESULT_OK;

	success &= txReleaseObject(&hInteractor) == TX_RESULT_OK;
	success &= txReleaseObject(&params) == TX_RESULT_OK;
	success &= txRegisterConnectionStateChangedHandler(handle.hContext, &handle.hConnectionStateChangedTicket, OnEngineConnectionStateChanged, handle.hGlobalInteractorSnapshot) == TX_RESULT_OK;
	success &= txRegisterEventHandler(handle.hContext, &handle.hEventHandlerTicket, HandleEvent, nullptr) == TX_RESULT_OK;
	success &= txEnableConnection(handle.hContext) == TX_RESULT_OK;

	if (!success)
	{
		ofLogError(smAddonName, "Registing eye position data event handler was failed.");
	}
	return success;
}

bool ofxTobiiEyeX::registerFixationEventHandler(const string& InteractorId, TX_FIXATIONDATAMODE mode)
{
	auto& handle = mFixationHandle;
	handle.hConnectionStateChangedTicket = TX_INVALID_TICKET;
	handle.hEventHandlerTicket = TX_INVALID_TICKET;
	TX_CONSTSTRING ID = InteractorId.c_str();
	TX_FIXATIONDATAPARAMS params = { mode };
	TX_HANDLE hInteractor = TX_EMPTY_HANDLE;
	bool success = true;

	success &= txCreateContext(&handle.hContext, TX_FALSE) == TX_RESULT_OK;
	success &= txCreateGlobalInteractorSnapshot(handle.hContext, ID, &handle.hGlobalInteractorSnapshot, &hInteractor) == TX_RESULT_OK;

	success &= txCreateFixationDataBehavior(hInteractor, &params) == TX_RESULT_OK;

	success &= txReleaseObject(&hInteractor) == TX_RESULT_OK;
	success &= txRegisterConnectionStateChangedHandler(handle.hContext, &handle.hConnectionStateChangedTicket, OnEngineConnectionStateChanged, handle.hGlobalInteractorSnapshot) == TX_RESULT_OK;
	success &= txRegisterEventHandler(handle.hContext, &handle.hEventHandlerTicket, HandleEvent, nullptr) == TX_RESULT_OK;
	success &= txEnableConnection(handle.hContext) == TX_RESULT_OK;

	if (!success)
	{
		ofLogError(smAddonName, "Registing fixation data event handler was failed.");
	}
	return success;
}

bool ofxTobiiEyeX::unregisterGazePointEventHandler()
{
	return unregisterEventHandler(mGazePointHandle);
}

bool ofxTobiiEyeX::unregisterEyePositionEventHandler()
{
	return unregisterEventHandler(mEyePositionHandle);
}

bool ofxTobiiEyeX::unregisterFixationEventHandler()
{
	return unregisterEventHandler(mFixationHandle);
}

bool ofxTobiiEyeX::isInitialized()
{
	BOOL bInitialized;
	txIsEyeXInitialized(&bInitialized);
	return bInitialized != 0;
}

bool ofxTobiiEyeX::isRegisteredGazePointEventHandler()
{
	return mGazePointHandle.hContext != TX_EMPTY_HANDLE;
}

bool ofxTobiiEyeX::isRegisteredEyePositionEventHandler()
{
	return mEyePositionHandle.hContext != TX_EMPTY_HANDLE;
}

bool ofxTobiiEyeX::isRegisteredFixationEventHandler()
{
	return mFixationHandle.hContext != TX_EMPTY_HANDLE;
}

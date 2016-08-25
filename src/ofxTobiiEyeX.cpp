#include "ofxTobiiEyeX.h"
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <assert.h>


// ID of the global interactor that provides our data stream; must be unique within the application.
static const string smAddonName = "ofxTogiiEyeX";

/*
 * Callback function invoked when a snapshot has been committed.
 */
void TX_CALLCONVENTION OnSnapshotCommitted(TX_CONSTHANDLE hAsyncData, TX_USERPARAM param)
{
	// check the result code using an assertion.
	// this will catch validation errors and runtime errors in debug builds. in release builds it won't do anything.

	TX_RESULT result = TX_RESULT_UNKNOWN;
	txGetAsyncDataResultCode(hAsyncData, &result);
	assert(result == TX_RESULT_OK || result == TX_RESULT_CANCELLED);
}

/*
 * Callback function invoked when the status of the connection to the EyeX Engine has changed.
 */
void TX_CALLCONVENTION OnEngineConnectionStateChanged(TX_CONNECTIONSTATE connectionState, TX_USERPARAM userParam)
{
	switch (connectionState) {
	case TX_CONNECTIONSTATE_CONNECTED: {
			BOOL success;
			ofLogNotice(smAddonName, "The connection state is now CONNECTED (We are connected to the EyeX Engine)");
			// commit the snapshot with the global interactor as soon as the connection to the engine is established.
			// (it cannot be done earlier because committing means "send to the engine".)
			success = txCommitSnapshotAsync((TX_HANDLE)userParam, OnSnapshotCommitted, NULL) == TX_RESULT_OK;
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

/*
 * Callback function invoked when an event has been received from the EyeX Engine.
 */
void TX_CALLCONVENTION HandleEvent(TX_CONSTHANDLE hAsyncData, TX_USERPARAM userParam)
{
	TX_HANDLE hEvent = TX_EMPTY_HANDLE;
	TX_HANDLE hBehavior = TX_EMPTY_HANDLE;

	txGetAsyncDataContent(hAsyncData, &hEvent);

	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_GAZEPOINTDATA) == TX_RESULT_OK)
	{
		if (txGetGazePointDataEventParams(hBehavior, (TX_GAZEPOINTDATAEVENTPARAMS*)userParam) != TX_RESULT_OK)
		{
			ofLogError(smAddonName, "Failed to interpret gaze data event packet.");
		}
		txReleaseObject(&hBehavior);
	}

	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_EYEPOSITIONDATA) == TX_RESULT_OK)
	{
		if (txGetEyePositionDataEventParams(hBehavior, (TX_EYEPOSITIONDATAEVENTPARAMS*)userParam) != TX_RESULT_OK)
		{
			ofLogError(smAddonName, "Failed to interpret eye position data event packet.");
		}
		txReleaseObject(&hBehavior);
	}

	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_FIXATIONDATA) == TX_RESULT_OK) {
		if (txGetFixationDataEventParams(hBehavior, (TX_FIXATIONDATAEVENTPARAMS*)userParam) != TX_RESULT_OK)
		{
			ofLogWarning(smAddonName, "Failed to interpret fixation data event packet.");
		}
		txReleaseObject(&hBehavior);
	}

	txReleaseObject(&hEvent);
}

ofxTobiiEyeX::ofxTobiiEyeX()
{
}

ofxTobiiEyeX::~ofxTobiiEyeX()
{
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

bool ofxTobiiEyeX::registerGazePointEventHandler(const string& InteractorId, TX_GAZEPOINTDATAMODE mode)
{
	GPContext.hContext = TX_EMPTY_HANDLE;
	GPContext.hConnectionStateChangedTicket = TX_INVALID_TICKET;
	GPContext.hEventHandlerTicket = TX_INVALID_TICKET;
	TX_HANDLE hInteractor = TX_EMPTY_HANDLE;
	TX_GAZEPOINTDATAPARAMS params = { mode };
	bool success = true;

	success &= txCreateContext(&GPContext.hContext, TX_FALSE) == TX_RESULT_OK;

	success &= txCreateGlobalInteractorSnapshot(
		GPContext.hContext,
		InteractorId.c_str(),
		&GPContext.hGlobalInteractorSnapshot,
		&hInteractor) == TX_RESULT_OK;
	success &= txCreateGazePointDataBehavior(hInteractor, &params) == TX_RESULT_OK;
	
	success &= txRegisterConnectionStateChangedHandler(GPContext.hContext, &GPContext.hConnectionStateChangedTicket, OnEngineConnectionStateChanged, GPContext.hGlobalInteractorSnapshot) == TX_RESULT_OK;
	success &= txRegisterEventHandler(GPContext.hContext, &GPContext.hEventHandlerTicket, HandleEvent, &GPContext.eventParams) == TX_RESULT_OK;
	success &= txEnableConnection(GPContext.hContext) == TX_RESULT_OK;

	if (!success)
	{
		ofLogError(smAddonName, "Registing gaze point data event handler failed.");
	}
	return success;
}

bool ofxTobiiEyeX::unregisterGazePointEventHandler()
{
	bool success = true;
	
	success &= txUnregisterConnectionStateChangedHandler(GPContext.hContext, GPContext.hConnectionStateChangedTicket) == TX_RESULT_OK;
	success &= txUnregisterEventHandler(GPContext.hContext, GPContext.hEventHandlerTicket) == TX_RESULT_OK;
	success &= txDisableConnection(GPContext.hContext) == TX_RESULT_OK;
	success &= txReleaseObject(&GPContext.hGlobalInteractorSnapshot) == TX_RESULT_OK;
	success &= txShutdownContext(GPContext.hContext, TX_CLEANUPTIMEOUT_DEFAULT, TX_FALSE) == TX_RESULT_OK;
	success &= txReleaseContext(&GPContext.hContext) == TX_RESULT_OK;

	if (!success)
	{
		ofLogError(smAddonName, "EyeX could not be shut down cleanly.");
	}
	return success;
}

bool ofxTobiiEyeX::registerEyePositionEventHandler(const string& InteractorId)
{
	EPContext.hContext = TX_EMPTY_HANDLE;
	EPContext.hConnectionStateChangedTicket = TX_INVALID_TICKET;
	EPContext.hEventHandlerTicket = TX_INVALID_TICKET;
	TX_HANDLE hInteractor = TX_EMPTY_HANDLE;
	TX_HANDLE hBehaviorWithoutParameters = TX_EMPTY_HANDLE;
	bool success = true;

	success &= txCreateContext(&EPContext.hContext, TX_FALSE) == TX_RESULT_OK;

	success &= txCreateGlobalInteractorSnapshot(
		EPContext.hContext,
		InteractorId.c_str(),
		&EPContext.hGlobalInteractorSnapshot,
		&hInteractor) == TX_RESULT_OK;
	success &= txCreateInteractorBehavior(hInteractor, &hBehaviorWithoutParameters, TX_BEHAVIORTYPE_EYEPOSITIONDATA) == TX_RESULT_OK;

	success &= txRegisterConnectionStateChangedHandler(EPContext.hContext, &EPContext.hConnectionStateChangedTicket, OnEngineConnectionStateChanged, EPContext.hGlobalInteractorSnapshot) == TX_RESULT_OK;
	success &= txRegisterEventHandler(EPContext.hContext, &EPContext.hEventHandlerTicket, HandleEvent, &EPContext.eventParams) == TX_RESULT_OK;
	success &= txEnableConnection(EPContext.hContext) == TX_RESULT_OK;

	if (!success)
	{
		ofLogError(smAddonName, "Registing gaze point data event handler failed.");
	}
	return success;
}

bool ofxTobiiEyeX::unregisterEyePositionEventHandler()
{
	bool success = true;
	success &= txUnregisterConnectionStateChangedHandler(EPContext.hContext, EPContext.hConnectionStateChangedTicket) == TX_RESULT_OK;
	success &= txUnregisterEventHandler(EPContext.hContext, EPContext.hEventHandlerTicket) == TX_RESULT_OK;
	success &= txDisableConnection(EPContext.hContext) == TX_RESULT_OK;
	success &= txReleaseObject(&EPContext.hGlobalInteractorSnapshot) == TX_RESULT_OK;
	success &= txShutdownContext(EPContext.hContext, TX_CLEANUPTIMEOUT_DEFAULT, TX_FALSE) == TX_RESULT_OK;
	success &= txReleaseContext(&EPContext.hContext) == TX_RESULT_OK;

	if (!success)
	{
		ofLogError(smAddonName, "EyeX could not be shut down cleanly.");
	}
	return success;
}


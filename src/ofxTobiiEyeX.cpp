#include "ofxTobiiEyeX.h"
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <assert.h>


// ID of the global interactor that provides our data stream; must be unique within the application.
static const string smAddonName = "ofxTogiiEyeX";

// global variables
TX_GAZEPOINTDATAEVENTPARAMS g_GazePointDataEventParams;
TX_EYEPOSITIONDATAEVENTPARAMS g_EyePositionDataEventParams;
TX_FIXATIONDATAEVENTPARAMS g_FixationDataEventParams;


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
* Handles an event from the Gaze Point data stream.
*/
void OnGazeDataEvent(TX_HANDLE hGazeDataBehavior)
{
	if (txGetGazePointDataEventParams(hGazeDataBehavior, &g_GazePointDataEventParams) != TX_RESULT_OK)
	{
		ofLogError(smAddonName, "Failed to interpret gaze data event packet.");
	}
}

/*
 * Handles an event from the Eye Position data stream.
 */
void OnEyePositionDataEvent(TX_HANDLE hEyePositionDataBehavior)
{
	if (txGetEyePositionDataEventParams(hEyePositionDataBehavior, &g_EyePositionDataEventParams) != TX_RESULT_OK)
	{ 
		ofLogError(smAddonName, "Failed to interpret eye position data event packet.");
	}
}

/*
* Handles an event from the fixation data stream.
*/
void OnFixationDataEvent(TX_HANDLE hFixationDataBehavior)
{
	if (txGetFixationDataEventParams(hFixationDataBehavior, &g_FixationDataEventParams) != TX_RESULT_OK)
	{
		ofLogWarning(smAddonName, "Failed to interpret fixation data event packet.");
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

	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_GAZEPOINTDATA) == TX_RESULT_OK) {
		OnGazeDataEvent(hBehavior);
		txReleaseObject(&hBehavior);
	}

	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_EYEPOSITIONDATA) == TX_RESULT_OK) {
		OnEyePositionDataEvent(hBehavior);
		txReleaseObject(&hBehavior);
	}

	txReleaseObject(&hEvent);
}

namespace ofxTobiiEyeX
{
	BaseTobiiEyeXApi::BaseTobiiEyeXApi()
		: hContext(TX_EMPTY_HANDLE)
		, hGlobalInteractorSnapshot(TX_EMPTY_HANDLE)
	{
	}

	BaseTobiiEyeXApi::~BaseTobiiEyeXApi()
	{
	}

	GazePoint::GazePoint()
	{
	}
	
	GazePoint::~GazePoint()
	{
		if (hContext != TX_EMPTY_HANDLE) close();
	}

	void GazePoint::update()
	{
		// copy event params to memver values.
		m_GazePointDataEventParams = g_GazePointDataEventParams;
	}

	bool GazePoint::open(TX_CONSTSTRING InteractorId, TX_GAZEPOINTDATAPARAMS params)
	{
		hContext = TX_EMPTY_HANDLE;
		TX_TICKET hConnectionStateChangedTicket = TX_INVALID_TICKET;
		TX_TICKET hEventHandlerTicket = TX_INVALID_TICKET;
		BOOL success;

		// initialize and enable the context that is our link to the EyeX Engine.
		success = txInitializeEyeX(TX_EYEXCOMPONENTOVERRIDEFLAG_NONE, NULL, NULL, NULL, NULL) == TX_RESULT_OK;
		success &= txCreateContext(&hContext, TX_FALSE) == TX_RESULT_OK;
		
		// Initializes hInteractorSnapshot with an interactor that has the Gaze Point Data behavior.
		TX_HANDLE hInteractor = TX_EMPTY_HANDLE;
		success = txCreateGlobalInteractorSnapshot(
			hContext,
			InteractorId,
			&hGlobalInteractorSnapshot,
			&hInteractor) == TX_RESULT_OK;
		success &= txCreateGazePointDataBehavior(hInteractor, &params) == TX_RESULT_OK;
		txReleaseObject(&hInteractor);

		success &= txRegisterConnectionStateChangedHandler(hContext, &hConnectionStateChangedTicket, OnEngineConnectionStateChanged, hGlobalInteractorSnapshot) == TX_RESULT_OK;
		success &= txRegisterEventHandler(hContext, &hEventHandlerTicket, HandleEvent, NULL) == TX_RESULT_OK;
		success &= txEnableConnection(hContext) == TX_RESULT_OK;

		if (success) {
			ofLogNotice(smAddonName, "Initialization was successful.");
		}
		else {
			ofLogError(smAddonName, "Initialization failed.");
		}
		return success;
	}

	bool GazePoint::open()
	{
		// open device with default parameters.
		TX_STRING id = "ofxTobiiEyeX_GazePoint";
		TX_GAZEPOINTDATAPARAMS params = { TX_GAZEPOINTDATAMODE_LIGHTLYFILTERED };
		return open(id, params);
	}

	bool GazePoint::close()
	{
		BOOL success;

		// disable and delete the context.
		txDisableConnection(hContext);
		txReleaseObject(&hGlobalInteractorSnapshot);
		success = txShutdownContext(hContext, TX_CLEANUPTIMEOUT_DEFAULT, TX_FALSE) == TX_RESULT_OK;
		success &= txReleaseContext(&hContext) == TX_RESULT_OK;
		success &= txUninitializeEyeX() == TX_RESULT_OK;
		if (!success) {
			ofLogError(smAddonName, "EyeX could not be shut down cleanly. Did you remember to release all handles?");
		}
		return success;
	}

	EyePosition::EyePosition()
	{
	}

	EyePosition::~EyePosition()
	{
		if (hContext != TX_EMPTY_HANDLE) close();
	}

	void EyePosition::update()
	{
		// copy event params to memver values.
		m_EyePositionDataEventParams = g_EyePositionDataEventParams;
	}

	bool EyePosition::open(TX_CONSTSTRING InteractorId)
	{
		hContext = TX_EMPTY_HANDLE;
		TX_TICKET hConnectionStateChangedTicket = TX_INVALID_TICKET;
		TX_TICKET hEventHandlerTicket = TX_INVALID_TICKET;
		BOOL success;

		// initialize and enable the context that is our link to the EyeX Engine.
		success = txInitializeEyeX(TX_EYEXCOMPONENTOVERRIDEFLAG_NONE, NULL, NULL, NULL, NULL) == TX_RESULT_OK;
		success &= txCreateContext(&hContext, TX_FALSE) == TX_RESULT_OK;

		// Initializes hInteractorSnapshot with an interactor that has the Eye Position behavior.
		TX_HANDLE hInteractor = TX_EMPTY_HANDLE;
		TX_HANDLE hBehaviorWithoutParameters = TX_EMPTY_HANDLE;
		success = txCreateGlobalInteractorSnapshot(
			hContext,
			InteractorId,
			&hGlobalInteractorSnapshot,
			&hInteractor) == TX_RESULT_OK;
		success &= txCreateInteractorBehavior(hInteractor, &hBehaviorWithoutParameters, TX_BEHAVIORTYPE_EYEPOSITIONDATA) == TX_RESULT_OK;
		txReleaseObject(&hInteractor);

		success &= txRegisterConnectionStateChangedHandler(hContext, &hConnectionStateChangedTicket, OnEngineConnectionStateChanged, hGlobalInteractorSnapshot) == TX_RESULT_OK;
		success &= txRegisterEventHandler(hContext, &hEventHandlerTicket, HandleEvent, NULL) == TX_RESULT_OK;
		success &= txEnableConnection(hContext) == TX_RESULT_OK;

		if (success) {
			ofLogNotice(smAddonName, "Initialization was successful.");
		}
		else {
			ofLogError(smAddonName, "Initialization failed.");
		}
		return success;
	}

	bool EyePosition::open()
	{
		// open device with default parameters.
		TX_STRING id = "ofxTobiiEyeX_EyePosition";
		return open(id);
	}

	bool EyePosition::close()
	{
		BOOL success;

		// disable and delete the context.
		txDisableConnection(hContext);
		txReleaseObject(&hGlobalInteractorSnapshot);
		success = txShutdownContext(hContext, TX_CLEANUPTIMEOUT_DEFAULT, TX_FALSE) == TX_RESULT_OK;
		success &= txReleaseContext(&hContext) == TX_RESULT_OK;
		success &= txUninitializeEyeX() == TX_RESULT_OK;
		if (!success) {
			ofLogError(smAddonName, "EyeX could not be shut down cleanly. Did you remember to release all handles?");
		}
		return success;
	}
}

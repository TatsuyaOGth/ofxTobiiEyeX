#include "ofxTobiiEyeX.h"


// ID of the global interactor that provides our data stream; must be unique within the application.
static const TX_STRING InteractorId = "ofxTobiiEyeX";

// global variables
static TX_HANDLE g_hGlobalInteractorSnapshot = TX_EMPTY_HANDLE;

// get values
static TX_REAL smGazeX = 0.0f;
static TX_REAL smGazeY = 0.0f;
static TX_REAL smEyeXTimestamp = 0;
static bool smPresent = false;

/*
* Initializes g_hGlobalInteractorSnapshot with an interactor that has the Gaze Point behavior.
*/
BOOL InitializeGlobalInteractorSnapshot(TX_CONTEXTHANDLE hContext)
{
	TX_HANDLE hInteractor = TX_EMPTY_HANDLE;
	TX_HANDLE hBehavior = TX_EMPTY_HANDLE;
	TX_GAZEPOINTDATAPARAMS params = { TX_GAZEPOINTDATAMODE_LIGHTLYFILTERED };
	BOOL success;

	success = txCreateGlobalInteractorSnapshot(
		hContext,
		InteractorId,
		&g_hGlobalInteractorSnapshot,
		&hInteractor) == TX_RESULT_OK;
	success &= txCreateInteractorBehavior(hInteractor, &hBehavior, TX_INTERACTIONBEHAVIORTYPE_GAZEPOINTDATA) == TX_RESULT_OK;
	success &= txSetGazePointDataBehaviorParams(hBehavior, &params) == TX_RESULT_OK;

	txReleaseObject(&hBehavior);
	txReleaseObject(&hInteractor);

	return success;
}

/*
* Callback function invoked when a snapshot has been committed.
*/
void TX_CALLCONVENTION OnSnapshotCommitted(TX_CONSTHANDLE hAsyncData, TX_USERPARAM param)
{
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
	case TX_CONNECTIONSTATE_CONNECTED: {   BOOL success;
										   ofLogNotice("The connection state is now CONNECTED");
										   success = txCommitSnapshotAsync(g_hGlobalInteractorSnapshot, OnSnapshotCommitted, NULL) == TX_RESULT_OK;
										   if (!success) {
											   ofLogError("Failed to initialize the data stream");
										   }
	}
		break;

	case TX_CONNECTIONSTATE_DISCONNECTED:
		ofLogNotice("The connection state is now DISCONNECTED");
		break;

	case TX_CONNECTIONSTATE_TRYINGTOCONNECT:
		ofLogNotice("The connection state is now TRYINGTOCONNECT");
		break;

	case TX_CONNECTIONSTATE_SERVERVERSIONTOOLOW:
		ofLogNotice("The connection state is now SERVER_VERSION_TOO_LOW: this application requires a more recent version of the EyeX Engine to run");
		break;

	case TX_CONNECTIONSTATE_SERVERVERSIONTOOHIGH:
		ofLogNotice("The connection state is now SERVER_VERSION_TOO_HIGH: this application requires an older version of the EyeX Engine to run");
		break;
	}
}

/*
* Handles an event from the Gaze Point data stream.
*/
void OnGazeDataEvent(TX_HANDLE hGazeDataBehavior)
{
	TX_GAZEPOINTDATAEVENTPARAMS eventParams;
	if (txGetGazePointDataEventParams(hGazeDataBehavior, &eventParams) == TX_RESULT_OK) {
		smGazeX = eventParams.X;
		smGazeY = eventParams.Y;
		smEyeXTimestamp = eventParams.Timestamp;
	}
	else {
		smGazeX = -1.0f;
		smGazeY = -1.0f;
		smEyeXTimestamp = -1;
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

	if (txGetEventBehavior(hEvent, &hBehavior, TX_INTERACTIONBEHAVIORTYPE_GAZEPOINTDATA) == TX_RESULT_OK) {
		OnGazeDataEvent(hBehavior);
		txReleaseObject(&hBehavior);
	}

	txReleaseObject(&hEvent);
}

/*
 * Handles a state-changed notification, or the response from a get-state operation.
 */
void OnStateReceived(TX_HANDLE hStateBag)
{
	TX_INTEGER status;
	TX_BOOL success;
	TX_SIZE2 displaySize;
	TX_SIZE2 screenBounds;

	success = (txGetStateValueAsInteger(hStateBag, TX_STATEPATH_STATE, &status) == TX_RESULT_OK);
	if (success) {
		switch (status) {
		case TX_EYETRACKINGDEVICESTATUS_TRACKING:
			printf("Eye Tracking Device Status: 'TRACKING'. That means that the eye tracker is up and running and trying to \ntrack your eyes.\n");
			break;

		default:
			printf("The eye tracking device is not tracking. Could be a that the eye tracker is not connected, or that a screen \nsetup or user calibration is missing. The status code is %d.\n", status);
		}
	}

	success = (txGetStateValueAsSize2(hStateBag, TX_STATEPATH_DISPLAYSIZE, &displaySize) == TX_RESULT_OK);
	if (success)
	{
		printf("Display Size: %5.2f x %5.2f mm\n", displaySize.Width, displaySize.Height);
	}

	success = (txGetStateValueAsSize2(hStateBag, TX_STATEPATH_SCREENBOUNDS, &screenBounds) == TX_RESULT_OK);
	if (success)
	{
		printf("Screen Bounds: %5.0f x %5.0f pixels\n\n", screenBounds.Width, screenBounds.Height);
	}

	// NOTE. The following line can be uncommented to catch errors during development. In production use there isn't much 
	// we can do if we receive a malformed event, run out of memory, or for some other reason fail to read the contents of an event.
	//assert(success);

	txReleaseObject(&hStateBag);
}

/*
 * Handles state changed notifications.
 */
void TX_CALLCONVENTION OnPresenceStateChanged(TX_CONSTHANDLE hAsyncData, TX_USERPARAM userParam)
{
	TX_RESULT result = TX_RESULT_UNKNOWN;
	TX_HANDLE hStateBag = TX_EMPTY_HANDLE;
	TX_BOOL success;
	TX_INTEGER presenceData;

	if (txGetAsyncDataResultCode(hAsyncData, &result) == TX_RESULT_OK && txGetAsyncDataContent(hAsyncData, &hStateBag) == TX_RESULT_OK)
	{		
		success = (txGetStateValueAsInteger(hStateBag, TX_STATEPATH_PRESENCEDATA, &presenceData) == TX_RESULT_OK);
		if (success)
		{
			if (presenceData == TX_PRESENCEDATA_PRESENT) {
				ofLogNotice("User is present");
				smPresent = true;
			} else {
				ofLogNotice("User is NOT present");
				smPresent = false;
			}
		}
	}
}


ofxTobiiEyeX::ofxTobiiEyeX():
mHContext(TX_EMPTY_HANDLE)
{
}

ofxTobiiEyeX::~ofxTobiiEyeX()
{
	// disable and delete the context.
	txDisableConnection(mHContext);
	txReleaseObject(&g_hGlobalInteractorSnapshot);
	txShutdownContext(mHContext, TX_CLEANUPTIMEOUT_DEFAULT, TX_FALSE);
	txReleaseContext(&mHContext);
}

bool ofxTobiiEyeX::setup()
{
	TX_TICKET hConnectionStateChangedTicket = TX_INVALID_TICKET;
	TX_TICKET hEventHandlerTicket = TX_INVALID_TICKET;
	TX_TICKET hPresenceStateChangedTicket = TX_INVALID_TICKET;
	BOOL success;

	// initialize and enable the context that is our link to the EyeX Engine.
	success = txInitializeSystem(TX_SYSTEMCOMPONENTOVERRIDEFLAG_NONE, NULL, NULL, NULL) == TX_RESULT_OK;
	success &= txCreateContext(&mHContext, TX_FALSE) == TX_RESULT_OK;
	success &= InitializeGlobalInteractorSnapshot(mHContext);
	success &= txRegisterConnectionStateChangedHandler(mHContext, &hConnectionStateChangedTicket, OnEngineConnectionStateChanged, NULL) == TX_RESULT_OK;
	success &= txRegisterEventHandler(mHContext, &hEventHandlerTicket, HandleEvent, NULL) == TX_RESULT_OK;
	success &= txRegisterStateChangedHandler(mHContext, &hPresenceStateChangedTicket, TX_STATEPATH_PRESENCEDATA, OnPresenceStateChanged, NULL) == TX_RESULT_OK;
	success &= txEnableConnection(mHContext) == TX_RESULT_OK;

	return success;
}

TX_REAL ofxTobiiEyeX::getGazeX()
{
	return smGazeX;
}

TX_REAL ofxTobiiEyeX::getGazeY()
{
	return smGazeY;
}

TX_REAL ofxTobiiEyeX::getEyeXTimestamp()
{
	return smEyeXTimestamp;
}

bool ofxTobiiEyeX::getPresent()
{
	return smPresent;
}
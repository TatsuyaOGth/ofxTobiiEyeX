#include "ofxTobiiEyeX.h"
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <assert.h>


// ID of the global interactor that provides our data stream; must be unique within the application.
static const TX_STRING InteractorId = "ofxTobiiEyeX";

// global variables
static TX_CONTEXTHANDLE hContext = TX_EMPTY_HANDLE;
static TX_HANDLE g_hGlobalInteractorSnapshot  = TX_EMPTY_HANDLE;

static string smAddonName = "ofxTogiiEyeX";

ofPoint ofxTobiiEyeX::smLeftEye(0, 0, 0);
ofPoint ofxTobiiEyeX::smRightEye(0, 0, 0);
ofPoint ofxTobiiEyeX::smLeftEyeNorm(0, 0, 0);
ofPoint ofxTobiiEyeX::smRightEyeNorm(0, 0, 0);
ofPoint ofxTobiiEyeX::smGaze(0, 0);
float	ofxTobiiEyeX::smEyeXTimestamp = 0;
bool	ofxTobiiEyeX::smPresent = false;


/*
 * Initializes g_hGlobalInteractorSnapshot with an interactor that has the Eye Position behavior.
 */
BOOL InitializeGlobalInteractorSnapshotEyePosition(TX_CONTEXTHANDLE hContext)
{
	TX_HANDLE hInteractor = TX_EMPTY_HANDLE;
	TX_HANDLE hBehaviorWithoutParameters = TX_EMPTY_HANDLE;

	BOOL success;

	success = txCreateGlobalInteractorSnapshot(
		hContext,
		InteractorId,
		&g_hGlobalInteractorSnapshot,
		&hInteractor) == TX_RESULT_OK;
	success &= txCreateInteractorBehavior(hInteractor, &hBehaviorWithoutParameters, TX_BEHAVIORTYPE_EYEPOSITIONDATA) == TX_RESULT_OK;

	txReleaseObject(&hInteractor);

	return success;
}

/*
 * Initializes g_hGlobalInteractorSnapshot with an interactor that has the Gaze Point behavior.
 */
BOOL InitializeGlobalInteractorSnapshotGazePoint(TX_CONTEXTHANDLE hContext)
{
	TX_HANDLE hInteractor = TX_EMPTY_HANDLE;
	TX_GAZEPOINTDATAPARAMS params = { TX_GAZEPOINTDATAMODE_LIGHTLYFILTERED };
	BOOL success;

	success = txCreateGlobalInteractorSnapshot(
		hContext,
		InteractorId,
		&g_hGlobalInteractorSnapshot,
		&hInteractor) == TX_RESULT_OK;
	success &= txCreateGazePointDataBehavior(hInteractor, &params) == TX_RESULT_OK;

	txReleaseObject(&hInteractor);

	return success;
}

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
			success = txCommitSnapshotAsync(g_hGlobalInteractorSnapshot, OnSnapshotCommitted, NULL) == TX_RESULT_OK;
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
	TX_GAZEPOINTDATAEVENTPARAMS eventParams;
	if (txGetGazePointDataEventParams(hGazeDataBehavior, &eventParams) == TX_RESULT_OK)
	{
		ofxTobiiEyeX::smGaze.set((float)eventParams.X, (float)eventParams.Y);
		ofxTobiiEyeX::smEyeXTimestamp = (float)eventParams.Timestamp;
	}
	else {
		ofxTobiiEyeX::smGaze.set(-1.0f, -1.0f);
		ofxTobiiEyeX::smEyeXTimestamp = -1;
	}
}

/*
 * Handles an event from the Eye Position data stream.
 */
void OnEyePositionDataEvent(TX_HANDLE hEyePositionDataBehavior)
{
	COORD position = {0,8};
	TX_EYEPOSITIONDATAEVENTPARAMS eventParams;
	if (txGetEyePositionDataEventParams(hEyePositionDataBehavior, &eventParams) == TX_RESULT_OK) { 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position); 

		// update eyes position
		ofxTobiiEyeX::smLeftEye.set(eventParams.LeftEyeX, eventParams.LeftEyeY, eventParams.LeftEyeZ);
		ofxTobiiEyeX::smRightEye.set(eventParams.RightEyeX, eventParams.RightEyeY, eventParams.RightEyeZ);
		ofxTobiiEyeX::smLeftEyeNorm.set(eventParams.LeftEyeXNormalized, eventParams.LeftEyeYNormalized, eventParams.LeftEyeZNormalized);
		ofxTobiiEyeX::smRightEyeNorm.set(eventParams.RightEyeXNormalized, eventParams.RightEyeYNormalized, eventParams.RightEyeZNormalized);

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

	// NOTE. Uncomment the following line of code to view the event object. The same function can be used with any interaction object.
	//OutputDebugStringA(txDebugObject(hEvent));

	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_EYEPOSITIONDATA) == TX_RESULT_OK) {
		OnEyePositionDataEvent(hBehavior);
		txReleaseObject(&hBehavior);
	}
	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_GAZEPOINTDATA) == TX_RESULT_OK) {
		OnGazeDataEvent(hBehavior);
		txReleaseObject(&hBehavior);
	}

	// NOTE since this is a very simple application with a single interactor and a single data stream, 
	// our event handling code can be very simple too. A more complex application would typically have to 
	// check for multiple behaviors and route events based on interactor IDs.

	txReleaseObject(&hEvent);
}

//-------------------------------------------------------------------------------------------------------------------
ofxTobiiEyeX::ofxTobiiEyeX(bool start)
{
	if (start) this->open();
}

ofxTobiiEyeX::~ofxTobiiEyeX()
{
	if (hContext != NULL) this->close();
}


bool ofxTobiiEyeX::open()
{	
	TX_TICKET hConnectionStateChangedTicket = TX_INVALID_TICKET;
	TX_TICKET hEventHandlerTicket = TX_INVALID_TICKET;
	BOOL success;

	// initialize and enable the context that is our link to the EyeX Engine.
	success = txInitializeEyeX(TX_EYEXCOMPONENTOVERRIDEFLAG_NONE, NULL, NULL, NULL, NULL) == TX_RESULT_OK;
	success &= txCreateContext(&hContext, TX_FALSE) == TX_RESULT_OK;
	//success &= InitializeGlobalInteractorSnapshotEyePosition(hContext);
	success &= InitializeGlobalInteractorSnapshotGazePoint(hContext);
	success &= txRegisterConnectionStateChangedHandler(hContext, &hConnectionStateChangedTicket, OnEngineConnectionStateChanged, NULL) == TX_RESULT_OK;
	success &= txRegisterEventHandler(hContext, &hEventHandlerTicket, HandleEvent, NULL) == TX_RESULT_OK;
	success &= txEnableConnection(hContext) == TX_RESULT_OK;

	if (success) {
		ofLogNotice(smAddonName, "Initialization was successful.");
	} else {
		ofLogError(smAddonName, "Initialization failed.");
	}
	return success;
}

bool ofxTobiiEyeX::close()
{
	BOOL success;

	// disable and delete the context.
	txDisableConnection(hContext);
	txReleaseObject(&g_hGlobalInteractorSnapshot);
	success = txShutdownContext(hContext, TX_CLEANUPTIMEOUT_DEFAULT, TX_FALSE) == TX_RESULT_OK;
	success &= txReleaseContext(&hContext) == TX_RESULT_OK;
	success &= txUninitializeEyeX() == TX_RESULT_OK;
	if (!success) {
		ofLogError(smAddonName, "EyeX could not be shut down cleanly. Did you remember to release all handles?\n");
	}
	return success;
}

#ifndef __OFX_TOBII_EYEX__
#define __OFX_TOBII_EYEX__

#include "ofMain.h"
#include "EyeX.h"

#pragma comment (lib, "Tobii.EyeX.Client.lib")

class ofxTobiiEyeX
{
	// private copy constructor and operator making the class non-copyable (declared but not implemented).
	ofxTobiiEyeX(const ofxTobiiEyeX&);
	ofxTobiiEyeX& operator = (const ofxTobiiEyeX&);

	// callback
	static void TX_CALLCONVENTION OnSnapshotCommitted(TX_CONSTHANDLE hAsyncData, TX_USERPARAM param);
	static void TX_CALLCONVENTION OnEngineConnectionStateChanged(TX_CONNECTIONSTATE connectionState, TX_USERPARAM param);
	static void TX_CALLCONVENTION HandleEvent(TX_CONSTHANDLE hAsyncData, TX_USERPARAM param);

protected:
	/// structur for context handles, global interactor snapshot and handle tickets.
	struct Handle
	{
		TX_BEHAVIORTYPE behaviorType;
		TX_CONTEXTHANDLE hContext;
		TX_HANDLE hGlobalInteractorSnapshot;
		TX_TICKET hConnectionStateChangedTicket;
		TX_TICKET hEventHandlerTicket;

		Handle()
			: hContext(TX_EMPTY_HANDLE), hGlobalInteractorSnapshot(TX_EMPTY_HANDLE)
			, hConnectionStateChangedTicket(TX_INVALID_TICKET), hEventHandlerTicket(TX_INVALID_TICKET) {}
	};
	Handle	mGazePointHandle;
	Handle	mEyePositionHandle;
	Handle	mFixationHandle;

	// EyeX begavior event parameters.
	TX_GAZEPOINTDATAEVENTPARAMS		mGazePointDataEventParams;
	TX_EYEPOSITIONDATAEVENTPARAMS	mEyePositionEventParams;
	TX_FIXATIONDATAEVENTPARAMS		mFixationEventParams;

	bool unregisterEventHandler(Handle& handle);

public:
	// static mamber values for data of EyeX behavior event parameters.
	// NOTE: these values are updated dynamically by other threads, you should get a copy in local scope if you want use.
	static TX_GAZEPOINTDATAEVENTPARAMS		smGazePointDataEventParams;
	static TX_EYEPOSITIONDATAEVENTPARAMS	smEyePositionEventParams;
	static TX_FIXATIONDATAEVENTPARAMS		smFixationEventParams;

public:
	ofxTobiiEyeX();
	virtual ~ofxTobiiEyeX();

	bool setup();
	bool close();

	void update();

	bool registerGazePointEventHandler(const string& InteractorId = "ofxTobiiEyeX_GazePointInteractor", TX_GAZEPOINTDATAMODE mode = TX_GAZEPOINTDATAMODE_LIGHTLYFILTERED);
	bool registerEyePositionEventHandler(const string& InteractorId = "ofxTobiiEyeX_EyePositionInteractor");
	bool registerFixationEventHandler(const string& InteractorId = "ofxTobiiEyeX_FixationInteractor", TX_FIXATIONDATAMODE mode = TX_FIXATIONDATAMODE_SENSITIVE);
	
	bool unregisterGazePointEventHandler();
	bool unregisterEyePositionEventHandler();
	bool unregisterFixationEventHandler();

	bool isRegisteredGazePointEventHandler();
	bool isRegisteredEyePositionEventHandler();
	bool isRegisteredFixationEventHandler();
	
	bool isInitialized();

	inline const TX_GAZEPOINTDATAEVENTPARAMS& getGazePointData() const { return mGazePointDataEventParams; }
	inline const TX_EYEPOSITIONDATAEVENTPARAMS& getEyePositionData() const { return mEyePositionEventParams; }
	inline const TX_FIXATIONDATAEVENTPARAMS& getFixationData() const { return mFixationEventParams; }

	inline ofPoint getGazePoint() const { return ofPoint(mGazePointDataEventParams.X, mGazePointDataEventParams.Y); }

	inline ofPoint getLeftEye() {
		return ofPoint(
			mEyePositionEventParams.LeftEyeX,
			mEyePositionEventParams.LeftEyeY,
			mEyePositionEventParams.LeftEyeZ);
	}
	inline ofPoint getLeftEyeNormalized() {
		return ofPoint(
			mEyePositionEventParams.LeftEyeXNormalized,
			mEyePositionEventParams.LeftEyeYNormalized,
			mEyePositionEventParams.LeftEyeZNormalized);
	}
	inline ofPoint getRightEye() {
		return ofPoint(
			mEyePositionEventParams.RightEyeX,
			mEyePositionEventParams.RightEyeY,
			mEyePositionEventParams.RightEyeZ);
	}
	inline ofPoint getRightEyeNormalized() {
		return ofPoint(
			mEyePositionEventParams.RightEyeXNormalized,
			mEyePositionEventParams.RightEyeYNormalized,
			mEyePositionEventParams.RightEyeZNormalized);
	}
	inline bool hasLeftEye() { return mEyePositionEventParams.HasLeftEyePosition; }
	inline bool hasRightEye() { return mEyePositionEventParams.HasRightEyePosition; }
	inline double getEyePositionTimestamp() { return mEyePositionEventParams.Timestamp; }

	inline ofPoint getFixationPoint() const { return ofPoint(mFixationEventParams.X, mFixationEventParams.Y); }

};

#endif

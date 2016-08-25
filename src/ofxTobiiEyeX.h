#ifndef __OFX_TOBII_EYEX__
#define __OFX_TOBII_EYEX__

#include "ofMain.h"
#include "EyeX.h"

class ofxTobiiEyeX
{
protected:
	typedef struct {
		TX_CONTEXTHANDLE hContext;
		TX_HANDLE hGlobalInteractorSnapshot;
		TX_TICKET hConnectionStateChangedTicket;
		TX_TICKET hEventHandlerTicket;
		TX_GAZEPOINTDATAEVENTPARAMS eventParams;
	} GazePositionContext;

	typedef struct {
		TX_CONTEXTHANDLE hContext;
		TX_HANDLE hGlobalInteractorSnapshot;
		TX_TICKET hConnectionStateChangedTicket;
		TX_TICKET hEventHandlerTicket;
		TX_EYEPOSITIONDATAEVENTPARAMS eventParams;
	} EyePositionContext;

	typedef struct {
		TX_CONTEXTHANDLE hContext;
		TX_HANDLE hGlobalInteractorSnapshot;
		TX_TICKET hConnectionStateChangedTicket;
		TX_TICKET hEventHandlerTicket;
		TX_FIXATIONDATAEVENTPARAMS eventParams;
	} FixationContext;

	GazePositionContext GPContext;
	EyePositionContext EPContext;
	FixationContext FContext;

public:
	ofxTobiiEyeX();
	virtual ~ofxTobiiEyeX();

	bool setup();
	bool close();


	bool registerGazePointEventHandler(const string& InteractorId, TX_GAZEPOINTDATAMODE params);
	bool unregisterGazePointEventHandler();
	bool registerEyePositionEventHandler(const string& InteractorId);
	bool unregisterEyePositionEventHandler();
	//bool registerFixationEventHandler(const string& InteractorId, TX_FIXATIONDATAMODE params);
	//bool unregisterFixationEventHandler();
	
	inline const TX_GAZEPOINTDATAEVENTPARAMS& getGazePointData() const { return GPContext.eventParams; }
	inline const TX_EYEPOSITIONDATAEVENTPARAMS& getEyePositionData() const { return EPContext.eventParams; }

	// get as other types
	inline ofPoint getLeftEye() {
		return ofPoint(
			EPContext.eventParams.LeftEyeX,
			EPContext.eventParams.LeftEyeY,
			EPContext.eventParams.LeftEyeZ);
	}
	inline ofPoint getLeftEyeNormalized() {
		return ofPoint(
			EPContext.eventParams.LeftEyeXNormalized,
			EPContext.eventParams.LeftEyeYNormalized,
			EPContext.eventParams.LeftEyeZNormalized);
	}
	inline ofPoint getRightEye() {
		return ofPoint(
			EPContext.eventParams.RightEyeX,
			EPContext.eventParams.RightEyeY,
			EPContext.eventParams.RightEyeZ);
	}
	inline ofPoint getRightEyeNormalized() {
		return ofPoint(
			EPContext.eventParams.RightEyeXNormalized,
			EPContext.eventParams.RightEyeYNormalized,
			EPContext.eventParams.RightEyeZNormalized);
	}
	inline bool hasLeftEye() { return EPContext.eventParams.HasLeftEyePosition; }
	inline bool hasRightEye() { return EPContext.eventParams.HasRightEyePosition; }
	inline double getTimestamp() { return EPContext.eventParams.Timestamp; }
};

#endif

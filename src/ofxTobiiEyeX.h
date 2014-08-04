#ifndef __OFX_TOBII_EYEX__
#define __OFX_TOBII_EYEX__

//#include <Windows.h>
#include "ofMain.h"
#include <assert.h>

#include "eyex\EyeX.h"

#define TOBII_TX_DETAIL

class ofxTobiiEyeX
{
	TX_CONTEXTHANDLE mHContext;

public:

	ofxTobiiEyeX();
	virtual ~ofxTobiiEyeX();

	bool setup();
	
	TX_REAL getGazeX();
	TX_REAL getGazeY();
	TX_REAL getEyeXTimestamp();
	bool getPresent();
};

#endif

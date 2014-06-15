#ifndef __OFX_TOBII_EYEX__
#define __OFX_TOBII_EYEX__

//#include <Windows.h>
#include "ofMain.h"
#include <assert.h>

#include "eyex\EyeX.h"

class ofxTobiiEyeX
{
	TX_CONTEXTHANDLE mHContext;

public:

	ofxTobiiEyeX();
	virtual ~ofxTobiiEyeX();

	bool setup();
	
	float getGazeX();
	float getGazeY();
	TX_REAL getEyeXTimestamp();
};

#endif

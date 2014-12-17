#ifndef __OFX_TOBII_EYEX__
#define __OFX_TOBII_EYEX__

//#include <Windows.h>
#include "ofMain.h"

#include "eyex/EyeX.h"
#pragma comment (lib, "Tobii.EyeX.Client.lib")

class ofxTobiiEyeX
{
public:
	static ofPoint smLeftEye;
	static ofPoint smRightEye;
	static ofPoint smLeftEyeNorm;
	static ofPoint smRightEyeNorm;
	static ofPoint smGaze;
	static float smEyeXTimestamp;
	static bool smPresent;

public:
	ofxTobiiEyeX(bool start = false);
	virtual ~ofxTobiiEyeX();

	bool open();
	bool close();

	ofPoint	& getLeftEyePosition()	{ return smLeftEye; }
	ofPoint & getRightEyePosition()	{ return smRightEye; }
	float getLeftEyePositionX()		{ return smLeftEye.x; }
	float getLeftEyePositionY()		{ return smLeftEye.y; }
	float getLeftEyePositionZ()		{ return smLeftEye.z; }
	float getRightEyePositionX()	{ return smRightEye.x; }
	float getRightEyePositionY()	{ return smRightEye.y; }
	float getRightEyePositionZ()	{ return smRightEye.z; }

	ofPoint	& getLeftEyePosNorm()	{ return smLeftEyeNorm; }
	ofPoint & getRightEyePosNorm()	{ return smRightEyeNorm; }
	float getLeftEyePositionXNorm()		{ return smLeftEyeNorm.x; }
	float getLeftEyePositionYNorm()		{ return smLeftEyeNorm.y; }
	float getLeftEyePositionZNorm()		{ return smLeftEyeNorm.z; }
	float getRightEyePositionXNorm()	{ return smRightEyeNorm.x; }
	float getRightEyePositionYNorm()	{ return smRightEyeNorm.y; }
	float getRightEyePositionZNorm()	{ return smRightEyeNorm.z; }

	ofPoint & getGaze()	{ return smGaze; }
	float	getGazeX()	{ return smGaze.x; }
	float	getGazeY()	{ return smGaze.y; }

	float	getEyeXTimestamp()	{ return smEyeXTimestamp; }
	bool	getPresent()		{ return smPresent; }
};

#endif

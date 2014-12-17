#pragma once

#include "ofMain.h"
#include "ofxTobiiEyeX.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

	ofxTobiiEyeX tx;
};

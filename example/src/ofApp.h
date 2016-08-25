#pragma once

#include "ofMain.h"
#include "ofxTobiiEyeX.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void exit();

		/*ofxTobiiEyeX::GazePoint mGazePoint;
		ofxTobiiEyeX::EyePosition mEyePosition;
		ofxTobiiEyeX::Fixations mFixation;*/
		ofxTobiiEyeX mEyeX;
};

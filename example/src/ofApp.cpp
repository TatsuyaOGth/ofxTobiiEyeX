#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(60);

	//mGazePoint.open();
	//mEyePosition.open();
	//mFixation.open();

	mEyeX.setup();
	mEyeX.registerGazePointEventHandler("TestGazePoint", TX_GAZEPOINTDATAMODE_LIGHTLYFILTERED);
	mEyeX.registerEyePositionEventHandler("TestEyePosition");
}

//--------------------------------------------------------------
void ofApp::update(){

	//mGazePoint.update();
	//mEyePosition.update();
	//mFixation.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(30);

	// Draw eye position
	ofSetColor(0, 255, 0);
	if (mEyeX.hasLeftEye())
	{
		ofPoint p = mEyeX.getLeftEyeNormalized();
		ofDrawCircle(
			p.x * ofGetWidth(),
			p.y * ofGetHeight(),
			(1. - p.z) * 80);
	}
	if (mEyeX.hasRightEye())
	{
		ofPoint p = mEyeX.getRightEyeNormalized();
		ofDrawCircle(
			p.x * ofGetWidth(),
			p.y * ofGetHeight(),
			(1. - p.z) * 80);
	}

	// Draw gaze point
	ofSetColor(255, 255, 255);
	ofDrawCircle(mEyeX.getGazePointData().X, mEyeX.getGazePointData().Y, 20);

	// Draw fixation
	/*ofSetColor(0, 0, 255);
	ofDrawCircle(mFixation.getPoint(), 10);*/

	/*
	stringstream ss;
	ss << "Output information about your eyes" << endl;
	ss << "- Left Eye Position  : " << tx.getLeftEyePosition() << endl;
	ss << "- Right Eye Position : " << tx.getRightEyePosition() << endl;
	ss << "Output information about your eyes (Normalized)" << endl;
	ss << "- Left Eye Position  : " << tx.getLeftEyePosNorm() << endl;
	ss << "- Right Eye Position : " << tx.getRightEyePosNorm() << endl;
	ss << "Output information aboud your gaze position" << endl;
	ss << "- Gaze position: " << tx.getGaze() << endl;
	ofSetColor(255);
	ofDrawBitmapString(ss.str(), 20, 20);
	*/
}

void ofApp::keyPressed(int key)
{
	if (key == 'f') ofToggleFullscreen();

	if (key == 'o')
	{
		mEyeX.setup();
	}

	if (key == 'c')
	{
		mEyeX.unregisterGazePointEventHandler();
		mEyeX.close();
	}
}

void ofApp::exit(){
	//mGazePoint.close();
	//mEyePosition.close();
	//mFixation.close();
	mEyeX.unregisterGazePointEventHandler();
	mEyeX.unregisterEyePositionEventHandler();
	mEyeX.close();
}

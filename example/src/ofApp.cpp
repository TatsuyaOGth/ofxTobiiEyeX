#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(60);

	mGazePoint.open();
	mEyePosition.open();
}

//--------------------------------------------------------------
void ofApp::update(){

	mGazePoint.update();
	mEyePosition.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(30);

	// Draw eye position
	ofSetColor(0, 255, 0);
	if (mEyePosition.getEyePosition().HasLeftEyePosition)
	{
		ofDrawCircle(
			mEyePosition.getEyePosition().LeftEyeXNormalized * ofGetWidth(),
			mEyePosition.getEyePosition().LeftEyeYNormalized * ofGetHeight(),
			abs(mEyePosition.getEyePosition().LeftEyeZNormalized - 1) * 80);
	}
	if (mEyePosition.getEyePosition().HasRightEyePosition)
	{
		ofDrawCircle(
			mEyePosition.getEyePosition().RightEyeXNormalized * ofGetWidth(),
			mEyePosition.getEyePosition().RightEyeYNormalized * ofGetHeight(),
			abs(mEyePosition.getEyePosition().RightEyeZNormalized - 1) * 80);
	}

	// Draw gaze point
	ofSetColor(255, 255, 255);
	ofDrawCircle(mGazePoint.getGazePoint(), 20);

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
}

void ofApp::exit(){
	mGazePoint.close();
}

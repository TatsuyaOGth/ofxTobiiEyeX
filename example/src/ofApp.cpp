#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(60);

	bool res = mGazePoint.open();
}

//--------------------------------------------------------------
void ofApp::update(){

	mGazePoint.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(30);

	ofDrawCircle(mGazePoint.getGazePoint(), 20);

	/*ofSetColor(255);
	ofCircle(
		tx.getLeftEyePositionXNorm() * ofGetWidth(),
		tx.getLeftEyePositionYNorm() * ofGetHeight(),
		abs(tx.getLeftEyePositionZNorm()-1) * 80);
	ofCircle(
		tx.getRightEyePositionXNorm() * ofGetWidth(),
		tx.getRightEyePositionYNorm() * ofGetHeight(),
		abs(tx.getRightEyePositionZNorm()-1) * 80);

	ofSetColor(ofColor::green);
	ofCircle(tx.getGaze(), 10);

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
	ofDrawBitmapString(ss.str(), 20, 20);*/
}

void ofApp::keyPressed(int key)
{
	if (key == 'f') ofToggleFullscreen();
}

void ofApp::exit(){
	mGazePoint.close();
}

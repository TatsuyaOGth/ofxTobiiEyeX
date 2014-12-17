#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(60);

	bool res = tx.open();
	if (!res) OF_EXIT_APP(-1);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(30);

	//cout << "x: " << x << " y: " << y << endl;
	//printf("\r [x %f] [y %f]", x, y);

	ofSetColor(255);
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
	ofDrawBitmapString(ss.str(), 20, 20);
}

void ofApp::exit(){
	tx.close();
}

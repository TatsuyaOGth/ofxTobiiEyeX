#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(60);

	mEyeX.setup();

	mEyeX.registerGazePointEventHandler();
	mEyeX.registerEyePositionEventHandler();
	mEyeX.registerFixationEventHandler();
}

//--------------------------------------------------------------
void ofApp::update(){

	mEyeX.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(30);

	// Draw eye position
	ofSetColor(0, 255, 0);
	ofFill();
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
	switch (mEyeX.getFixationData().FixationDataMode)
	{
	case TX_FIXATIONDATAEVENTTYPE_BEGIN:
		ofSetColor(255, 0, 0);
		break;
	case TX_FIXATIONDATAEVENTTYPE_END:
		ofSetColor(0, 0, 255);
		break;
	case TX_FIXATIONDATAEVENTTYPE_DATA:
		ofSetColor(255, 0, 255);
		break;
	}
	ofNoFill();
	ofDrawCircle(mEyeX.getFixationPoint(), 25);

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
	
	mEyeX.unregisterGazePointEventHandler();
	mEyeX.unregisterEyePositionEventHandler();
	mEyeX.unregisterFixationEventHandler();
	mEyeX.close();
}

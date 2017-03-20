#include "ofApp.h"

int flip = 0;

//--------------------------------------------------------------
void ofApp::setup(){

	ofLog(OF_LOG_NOTICE, "\n\tsetting up app\n");

	shader.load("shadersGL3/shader");
	img.loadImage("images/img.jpg");
	plane.set(275, 228, 10, 10);
	plane.mapTexCoords(0, 0, img.getWidth(), img.getHeight());

	ofSetWindowShape(275, 228);
	ofSetWindowPosition(1091, 100);
	ofSetWindowTitle("app");
	
	ofSetFrameRate(30);
	ofSetVerticalSync(true);
	
	startTime = ofGetElapsedTimeMillis();
	initTime = 0;
	elapsedTime = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	//tweenValue = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);
	flip++;
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	img.getTextureReference().bind();
	shader.begin();
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	plane.draw();
	ofPopMatrix();
	shader.end();
	img.getTextureReference().unbind();
	
	//ofLog(OF_LOG_NOTICE, ofToString(flip % 4));

	ofSetColor(255, 51, 0);
	ofDrawBitmapString( ofGetFrameRate(), 20,30 );
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

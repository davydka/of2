#include "ofApp.h"

int gifCounter = 0;

//--------------------------------------------------------------
void ofApp::setup(){

	ofLog(OF_LOG_NOTICE, "\n\tsetting up app\n");

	shader.load("shadersGL3/shader");

	ofSetWindowShape(275, 228);
	ofSetWindowPosition(1091, 100);
	ofSetWindowTitle("app");
	
	//system ("(sleep 1; wmctrl -r \"app\" -b toggle,above; wmctrl -a \"/bin/bash\") &");

	ofSetFrameRate(60);
	//ofSetVerticalSync(true);
	
	startTime = ofGetElapsedTimeMillis();
	elapsedTime = 0;

	ofBackground(0, 0, 255);
	ofSetCircleResolution(100);
	fbo.allocate(275,228,GL_RGBA);
	fbo.begin();{
		ofDrawEllipse(137, 114, 200, 200);
    }
	fbo.end();
	gifloader.load("images/beatles.gif");
	
	for (int i = 0; (unsigned)i < gifloader.pages.size(); ++i){
		 gifloader.pages[i].getTexture().setAlphaMask(fbo.getTexture());
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	elapsedTime = ofGetElapsedTimeMillis() - startTime;
	if(elapsedTime >= 1000){
		//ofLog(OF_LOG_NOTICE, ofToString(OF_WINDOW));
		//ofLog(OF_LOG_NOTICE, "the number is" + ofToString(ofGetElapsedTimeMillis()));
		startTime += elapsedTime;
	}


	//ofLog( OF_LOG_NOTICE, ofToString(ofGetElapsedTimeMillis()%2) );
	if(ofGetElapsedTimeMillis() % 4 == 0){
		gifCounter++;
		if ((unsigned)gifCounter > gifloader.pages.size()-1) gifCounter = 0;
		gifloader.pages[gifCounter].getTexture().setAlphaMask(fbo.getTexture());
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofClear(255, 0, 0, 128);
	//ofBackground(0, 0, 255);
	ofSetColor(255);
	shader.begin();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	shader.end();

	ofSetColor(255, 51, 0);
	ofDrawBitmapString( ofGetFrameRate(), 20,30 );
	ofSetColor(255);
		
	gifloader.pages[gifCounter].draw(0, 0);

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

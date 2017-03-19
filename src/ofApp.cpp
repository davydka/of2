#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	ofLog(OF_LOG_NOTICE, "\n\tsetting up app\n");

	ofSetWindowShape(100, 566);
	ofSetWindowPosition(0, 100);
	ofSetWindowTitle("app");
	
	bool topmost;
	//topmost = true;
	topmost = false;
	if(topmost){
		
		int i;
		i=system ("which wmctrl");
		if(i == 0){ //0 is ok, 256 means command isn't found
			int ii;
			printf ("Setting window to topmost...\n");
			ii=system ("(sleep 1; wmctrl -r \"app\" -b toggle,above; wmctrl -a \"/bin/bash\") &");
			printf ("wmctrl value returned was: %d.\n",ii);
		}
	}


	ofSetFrameRate(60);
	//ofSetVerticalSync(true);
	
	startTime = ofGetElapsedTimeMillis();
	elapsedTime = 0;

}

//--------------------------------------------------------------
void ofApp::update(){
	elapsedTime = ofGetElapsedTimeMillis() - startTime;
	if(elapsedTime >= 1000){
		//ofLog(OF_LOG_NOTICE, ofToString(OF_WINDOW));
		//ofLog(OF_LOG_NOTICE, "the number is" + ofToString(ofGetElapsedTimeMillis()));
		startTime += elapsedTime;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

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

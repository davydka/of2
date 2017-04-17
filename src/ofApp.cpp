#include "ofApp.h"

int flip = 0;

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetLogLevel(OF_LOG_VERBOSE);

	ofLog(OF_LOG_NOTICE, "\n\tsetting up app\n");
	//ofBackground(0,0,0);

	


	movieMovie.setPixelFormat(OF_PIXELS_NATIVE);
	//movieMovie.setPixelFormat(OF_PIXELS_I420);
	movieMovie.load("trailer_1080p.mp4");
	movieMovie.setLoopState(OF_LOOP_NORMAL);
	movieMovie.play();

	ofPixels & pixels = movieMovie.getPixels();
	int vidWidth = pixels.getWidth();
	int vidHeight = pixels.getHeight();

	shader.load("shadersGL3/shader");
	img.load("images/img.jpg");
	plane.set(480, 270, 10, 10);
	plane.mapTexCoords(0, 0, vidWidth, vidHeight);
	fbo.allocate(vidWidth, vidHeight);





	/*
	movieMovie2.setPixelFormat(OF_PIXELS_NATIVE);
	//movieMovie.setPixelFormat(OF_PIXELS_I420);
	movieMovie2.load("trailer_1080p_inverted.mp4");
	movieMovie2.setLoopState(OF_LOOP_NORMAL);
	movieMovie2.play();

	shader2.load("shadersGL3/shader");
	plane2.set(480, 270, 10, 10);
	plane2.mapTexCoords(0, 0, vidWidth, vidHeight);
	fbo2.allocate(vidWidth, vidHeight);
	*/





	float value = vidWidth;
	ofLogNotice() << "value: " << value;
	ofLog(OF_LOG_NOTICE, ofToString(OF_PIXELS_NATIVE));
	//ofLog(OF_LOG_NOTICE, "%s", pixels.getPixelFormat());

	ofSetWindowShape(1920, 1080);
	ofSetWindowPosition(0, 0);
	ofSetWindowTitle("app");
	
	//ofSetFrameRate(60);
	ofSetFrameRate(30);
	ofSetVerticalSync(true);
	
	startTime = ofGetElapsedTimeMillis();
	initTime = 0;
	elapsedTime = 0;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	//tweenValue = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);
	//flip++;
	movieMovie.update();
	//movieMovie2.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	fbo.begin();
		if(movieMovie.isFrameNew()){
			ofClear(0, 0, 0,255);
			movieMovie.draw(0,0);
		}
	fbo.end();
	
	ofTexture tex;
	shader.begin();
	tex = fbo.getTexture();
	shader.setUniformTexture("tex0", tex, 1);
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	plane.draw();
	shader.end();
	



	/*
	fbo2.begin();
		if(movieMovie2.isFrameNew()){
			ofClear(0, 0, 0,255);
			movieMovie2.draw(0,0);
		}
	fbo2.end();
	
	ofTexture tex2;
	shader2.begin();
	tex2 = fbo2.getTexture();
	shader2.setUniformTexture("tex0", tex2, 1);
	ofTranslate(ofGetWidth(), ofGetHeight());
	plane2.draw();
	shader2.end();
	*/
	
	//ofSetColor(255, 51, 0);
	//ofDrawBitmapString( ofGetFrameRate(), 20,30 );
	
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

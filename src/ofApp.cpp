#include "ofApp.h"

int flip = 0;
float bkR = 0;
float bkG = 0;
float bkB = 0;

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetLogLevel(OF_LOG_VERBOSE);

	ofLog(OF_LOG_NOTICE, "\n\tsetting up app\n");
	ofBackground(0,0,0);

	


	movieMovie.setPixelFormat(OF_PIXELS_NATIVE);
	//movieMovie.setPixelFormat(OF_PIXELS_I420);
	movieMovie.load("trailer_320.mp4");
	movieMovie.setLoopState(OF_LOOP_NORMAL);
	//movieMovie.play();

	ofPixels & pixels = movieMovie.getPixels();
	int vidWidth = pixels.getWidth();
	int vidHeight = pixels.getHeight();

	shader.load("shadersGL3/shader");
	img.load("images/green.png");
	//plane.set(480, 270, 10, 10);
	plane.set(1920, 1080, 80, 60);
	//plane.mapTexCoords(0, 0, 1920, 1080);
	plane.mapTexCoords(0, 0, 1920, 1080);
	//plane.mapTexCoords(0, 0, vidWidth, vidHeight);
	//fbo.allocate(vidWidth, vidHeight);
	fbo.allocate(1920, 1080);
	//fbo.allocate(480, 270);

	noiseImg.allocate(80, 60, OF_IMAGE_GRAYSCALE);




	movieMovie2.setPixelFormat(OF_PIXELS_NATIVE);
	//movieMovie.setPixelFormat(OF_PIXELS_I420);
	movieMovie2.load("trailer_320_inverted.mp4");
	movieMovie2.setLoopState(OF_LOOP_NORMAL);
	movieMovie.play();
	movieMovie2.play();
	/*

	shader2.load("shadersGL3/shader");
	*/
	plane2.set(480, 270, 10, 10);
	plane2.mapTexCoords(0, 0, vidWidth, vidHeight);
	fbo2.allocate(1920, 1080);





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
	bkR = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 255);
	bkG = ofMap(cos(ofGetElapsedTimef()), -1, 1, 0, 255);
	bkB = ofMap(sin(ofGetElapsedTimef()), -1, 1, 255, 0);
	//tweenValue = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);
	//flip++;

	//ofLog(OF_LOG_NOTICE, ofToString(mouseX));

	float noiseScale = ofMap(mouseX, 0, ofGetWidth(), 0, 0.1);
    float noiseVel = ofGetElapsedTimef();

    ofPixels & npixels = noiseImg.getPixels();
    int w = noiseImg.getWidth();
    int h = noiseImg.getHeight();
    for(int y=0; y<h; y++) {
        for(int x=0; x<w; x++) {
            int i = y * w + x;
            float noiseVelue = ofNoise(x * noiseScale, y * noiseScale, noiseVel);
            npixels[i] = 255 * noiseVelue;
        }
    }
    noiseImg.update();

	movieMovie.update();
	movieMovie2.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(bkR,bkG,bkB);
	
	fbo.begin();
		if(movieMovie.isFrameNew()){

			ofClear(bkR, bkG, bkB, 255);

			movieMovie.draw(0,0);
			movieMovie2.draw(200,100);

			movieMovie.draw(500,500);
			movieMovie2.draw(700,600);

			movieMovie.draw(1500,500);
			movieMovie2.draw(1700,600);

			img.draw(860, 440);
		}
		/*
		if(movieMovie2.isFrameNew()){
			ofClear(0, 0, 0,255);
			movieMovie2.draw(100,100);
		}
		*/
	fbo.end();

	
	fbo2.begin();
		noiseImg.draw(0,0,1920,1080);
	fbo2.end();
	
	
	ofTexture tex0;
	ofTexture tex1;
	shader.begin();
	tex0 = fbo.getTexture();
	//tex1 = fbo2.getTexture();
	tex1 = fbo2.getTexture();
	shader.setUniformTexture("tex0", tex0, 1);
	shader.setUniformTexture("tex1", tex1, 2);
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	plane.draw();
	shader.end();
	
	ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
	ofSetColor(ofColor::white);
	noiseImg.draw(0, 0);




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

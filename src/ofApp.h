#pragma once

#include "ofMain.h"
#include "ofxGif.h"
#include "ofxEasing.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		int startTime;
		int elapsedTime;
		int initTime;
		float tweenValue;

		ofFbo fbo;
		ofShader shader;
		ofPlanePrimitive plane;
		ofImage img;
		ofImage noiseImg;
		ofxGIF::fiGifLoader gifloader;
		//ofxEasing ofxeasing;

		ofVideoPlayer movieMovie;
		bool frameByframe;

		ofFbo fbo2;
		ofShader shader2;
		ofPlanePrimitive plane2;
		ofVideoPlayer movieMovie2;

};

#include "ofMain.h"
#include "ofApp.h"
//#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	//ofAppGLFWWindow window;

	//ofSetupOpenGL(&window, 640,480,OF_WINDOW);
	ofSetupOpenGL(640,480,OF_WINDOW);			// <-------- setup the GL context

	ofRunApp(new ofApp());

}

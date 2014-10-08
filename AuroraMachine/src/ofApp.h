#pragma once

#include "ofMain.h"
#include "ofxAppUtils.h"
#include "ofxOsc.h"



class ActOne;


class ofApp : public ofxApp{

	public:
        ofApp(){};
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVec3f inline getAccel(){return accel;};
    ofVec2f inline getXY(){return XY;};
    float inline getSlide1(){return slide1;};
    float inline getSlide2(){return slide2;};
    
    
    
private:
    ofxSceneManager sceneManager;
    ofxOscReceiver oscIn;
    
    ActOne * actOne;
    
    ///Inputs
    ofxOscMessage msg;
    ofVec3f accel;
    ofVec2f XY;
    float slide1, slide2;

		
};


#include "ofApp.h"
#include "Scenes.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    ofSetLogLevel("ofxSceneManager", OF_LOG_VERBOSE);
    
    actOne = (ActOne*) sceneManager.add(new ActOne());
    sceneManager.setup(true);
    sceneManager.gotoScene("ActOne",true);
    setSceneManager(&sceneManager);
    
    
    oscIn.setup(6666);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    while (oscIn.hasWaitingMessages()){
        oscIn.getNextMessage(&msg);
        cout<<msg.getAddress()<<endl;
        if (msg.getAddress() == "/accxyz"){
            accel = ofVec3f(msg.getArgAsFloat(0), msg.getArgAsFloat(1), msg.getArgAsFloat(2));
        } else if ( msg.getAddress() == "/1/fader2"){
            slide1 = msg.getArgAsFloat(0);
            
        }
        
        cout<< "acc "<<accel.x<<endl;
    }
    
    actOne->setRecLoc(accel);
    actOne->setAlt(slide1);

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0,10);
    ofRectMode(OF_RECTMODE_CORNER);
    ofRect(0,0,ofGetWidth(), ofGetHeight());
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

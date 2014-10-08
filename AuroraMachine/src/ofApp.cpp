#include "ofApp.h"
#include "Scenes.h"

//--------------------------------------------------------------
void ofApp::setup(){
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
        }
        
        cout<< "acc "<<accel.x<<endl;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

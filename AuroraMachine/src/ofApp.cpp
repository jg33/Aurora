#include "ofApp.h"
#include "Scenes.h"

//--------------------------------------------------------------
void ofApp::setup(){
    setDrawFramerate(true);
    
    ofSetBackgroundAuto(false);
    ofSetLogLevel("ofxSceneManager", OF_LOG_VERBOSE);
    
    actOne = (ActOne*) sceneManager.add(new ActOne());
    sceneManager.setup(true);
    sceneManager.gotoScene("ActOne",true);
    setSceneManager(&sceneManager);
    
    
    oscIn.setup(6666);
    
    bDebug = true;
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
            actOne->setAlt(slide1);

            
        } else if (msg.getAddress() == "/cap"){
            actOne->setFlow(msg.getArgAsFloat(0));
        } else if (msg.getAddress() == "/wave"){
            float waveNum = msg.getArgAsFloat(0);
            
            if (waveNum>0.6) {
                waveNum = ofMap(waveNum,0.6,1,0,0.1);
            } else if (waveNum<0.6){
                waveNum = ofMap(waveNum, 0.6, -1, 0, -0.1);
            }
            
            
            actOne->setWave(ofVec2f(waveNum,0));
        }
        //cout<< "acc "<<accel.x<<endl;
    }
    actOne->setLoc(accel);



}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0,10);
    ofSetRectMode(OF_RECTMODE_CORNER);
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

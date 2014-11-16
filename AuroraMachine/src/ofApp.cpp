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
        
        vector<string> address = ofSplitString(msg.getAddress(),"/");
        //cout<<address[1]<<endl;
        
        if (address[2]=="mag"  ){
            
            switch (ofToInt(address[1])) {
                case 2:
                    rock1 = ofVec3f(msg.getArgAsFloat(0), msg.getArgAsFloat(1), 0);
                    actOne->setLoc(1,rock1);

                    break;
                case 3:
                    rock2 = ofVec3f(msg.getArgAsFloat(0), msg.getArgAsFloat(1), 0);
                    actOne->setLoc(2,rock2);

                    break;
                case 4:
                    rock3 = ofVec3f(msg.getArgAsFloat(0), msg.getArgAsFloat(1), 0);
                    actOne->setLoc(3,rock3);

                    break;
                    
                default:
                    break;
            }

        } else if (address[2] == "flow"){
            switch (ofToInt(address[1])) {
                case 1:
                    flow1 = msg.getArgAsFloat(0);
                    break;
                case 2:
                    flow2 = msg.getArgAsFloat(0);

                    break;
                case 3:
                    flow3 = msg.getArgAsFloat(0);

                    break;
                    
                default:
                    break;
            }
            
        }
        
    }
    if(oscOn){
        actOne->setFlow(1, flow1);
        actOne->setFlow(2, flow2);
        actOne->setFlow(3, flow3);
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0,10);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        ofToggleFullscreen();
    }
    if(key =='o'){
        oscOn = !oscOn;
    }

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

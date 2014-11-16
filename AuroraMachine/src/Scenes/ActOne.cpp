//
//  ActOne.cpp
//  AuroraMachine
//
//  Created by Jesse Garrison on 10/7/14.
//
//

#include "ActOne.h"


void ActOne::setup(){
    setSingleSetup(false);
    
    app = ofxGetAppPtr();
    
    lowColor = ofColor::limeGreen;
    midColor = ofColor::blueSteel;
    highColor = ofColor::mediumVioletRed;
    
    if (MOCK_INPUT){
        for (int i=0;i< NUM_CURTAIN_POINTS;i++){
            mockPoints.push_back(ofVec3f(500-ofRandom(1000),500-ofRandom(1000),500-ofRandom(1000)));
        }
        
    }
    
    curtain1.color = lowColor;
    curtain1.startThread();
    
    curtain2.color = midColor;
    curtain2.startThread();
    
    curtain3.color = highColor;
    curtain3.startThread();
    
}

void ActOne::update(){
    /*
    curtain1.update();
    curtain2.update();
    curtain3.update();
     */

    }

void ActOne::draw(){
    //ofBackground(0);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    ofSetLineWidth(10);
  
    //curtain1.lock();
    //curtain2.lock();
    //curtain3.lock();

    curtain1.draw();
    curtain2.draw();
    curtain3.draw();

    //curtain1.unlock();
    //curtain2.unlock();
    //curtain3.unlock();

    ofPopMatrix();
    

    
    
}

void ActOne::setLoc(int i, ofVec3f l){
    l*=10;
    switch (i) {
        case 1:
            curtain1.lock();
            curtain1.setLoc(l);
            curtain1.resetIdleTimer();
            curtain1.unlock();
            break;
        case 2:
            curtain2.lock();
            curtain2.setLoc(l);
            curtain2.resetIdleTimer();
            curtain2.unlock();
            break;
        case 3:
            curtain2.lock();
            curtain3.setLoc(l);
            curtain3.resetIdleTimer();
            curtain2.unlock();
            break;
            
        default:
            break;
    }
    
}

void ActOne::setFlow(int i, float f){
    switch (i) {
        case 1:
            curtain1.setFlow(f);
            break;
        case 2:
            curtain2.setFlow(f);
            break;
        case 3:
            curtain3.setFlow(f);
            break;
            
        default:
            break;
    }
    
}
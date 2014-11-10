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
    midColor = ofColor::blue;
    highColor = ofColor::mediumVioletRed;
    
    if (MOCK_INPUT){
        for (int i=0;i< NUM_CURTAIN_POINTS;i++){
            mockPoints.push_back(ofVec3f(500-ofRandom(1000),500-ofRandom(1000),500-ofRandom(1000)));
        }
        
    }
    
    curtain1.startThread();
    curtain1.color = lowColor;
    
    curtain2.startThread();
    curtain2.color = midColor;
    
    curtain3.startThread();
    curtain3.color = highColor;
    
}

void ActOne::update(){
    curtain1.update();
    curtain2.update();
    curtain3.update();

    }

void ActOne::draw(){
    //ofBackground(0);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    ofSetLineWidth(10);
  
    curtain1.draw();
    curtain2.draw();
    curtain3.draw();


    ofPopMatrix();
    

    
    
}

void ActOne::setLoc(ofVec3f l){

    curtain1.setLoc(l);
    
}
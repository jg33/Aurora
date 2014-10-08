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
    
    lowColor = ofColor::royalBlue;
    highColor = ofColor::mediumVioletRed;
    
}

void ActOne::update(){
    primaryColor = lowColor.getLerped(highColor, altitude);
    
    
}

void ActOne::draw(){
    //ofBackground(0);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(primaryColor);
    ofRectMode(OF_RECTMODE_CENTER);
    ofRect(recLoc,50,50);
    ofPopMatrix();
    
}
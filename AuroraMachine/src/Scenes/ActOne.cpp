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
    midColor = ofColor::green;
    highColor = ofColor::mediumVioletRed;
    
}

void ActOne::update(){
    if(altitude<0.5){
        primaryColor = lowColor.getLerped(midColor, altitude*2);
    } else if (altitude>=0.5){
        primaryColor = midColor.getLerped(highColor, ofMap(altitude,0.5,1,0,1));
    }
    
    curtain.clear();
    for(int i=0;i<curtainPoints.size();i++){
        //curtain.addVertex(curtainPoints[i]);
        cout<<curtainPoints[i]<<endl;;
    }
    
}

void ActOne::draw(){
    //ofBackground(0);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(primaryColor);
    ofRectMode(OF_RECTMODE_CENTER);
    //ofRect(recLoc,50,50);

    ofSetLineWidth(10);
    curtain.setFilled(false);
    curtain.setStrokeColor(primaryColor);
    curtain.setStrokeWidth(10);
    curtain.setCurveResolution(100);
    if(curtainPoints.size()>4){
        for (int i=0;i<curtainPoints.size();i++){
            curtain.setStrokeColor(curtainColors[i]);
            curtain.curveTo(curtainPoints[i]);
        }
    }else{
    }
    curtain.draw();
    ofPopMatrix();
    
}

void ActOne::setLoc(ofVec3f l){
    ofVec3f newLoc = l*500;
    //recLoc += (newLoc-recLoc)*0.5;
    
    curtainPoints.push_front(newLoc);
    curtainColors.push_front(primaryColor);
    if(curtainPoints.size()>NUM_CURTAIN_POINTS){
        curtainColors.pop_back();
        curtainPoints.pop_back();
    }
    
}
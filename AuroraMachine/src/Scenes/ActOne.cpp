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
    midColor = ofColor::green;
    highColor = ofColor::mediumVioletRed;
    
    if (MOCK_INPUT){
        for (int i=0;i< NUM_CURTAIN_POINTS;i++){
            mockPoints.push_back(ofVec3f(500-ofRandom(1000),500-ofRandom(1000),500-ofRandom(1000)));
        }
        
    }
    
    pBoss.setAutoRemove(true);
}

void ActOne::update(){
    if(altitude<0.5){
        primaryColor = lowColor.getLerped(midColor, altitude*2);
    } else if (altitude>=0.5){
        primaryColor = midColor.getLerped(highColor, ofMap(altitude,0.5,1,0,1));
    }
    
    curtain.clear();
    
    if(MOCK_INPUT) curtainPoints = mockPoints;
    for(int i=0;i<curtainPoints.size();i++){
       curtain.addVertex(curtainPoints[i]);
        ofVec3f noiseVert = ofVec3f(ofSignedNoise(i+ofGetElapsedTimef()), ofSignedNoise(i+50+ofGetElapsedTimef()),ofSignedNoise(i+76+ofGetElapsedTimef()));
        //noiseVert;
        //curtainPoints[i]+=noiseVert;//
        //cout<<curtainPoints[i]<<endl;;
    }
    
        for (float i= 0; i< LINE_RESOLUTION_FOR_PARTICLES;i++){
            ofPoint thisPoint = curtain.getPointAtPercent((i/LINE_RESOLUTION_FOR_PARTICLES) + ofSignedNoise(ofGetElapsedTimef()+(i*5.66)));
            thisPoint += ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
            if(ofRandom(1) < flow){
                pBoss.addParticle(new Dust(thisPoint));
            }
            //cout<<thisPoint<<endl;
        }
    
    
    
    for(int i=0;i< curtainPoints.size();i++){
        ofPoint thisPoint = curtainPoints[i];
        thisPoint += ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
        thisPoint += ofVec2f(ofSignedNoise(ofGetElapsedTimef()+(i*5.66))*50, 0);
       // pBoss.addParticle(new Dust(thisPoint));
    }
    
    theWave.setSize(waveWidth);
    theWave.update();
    
    pBoss.update();
    
    //cout<<pBoss.getParticlesPtr()->size()<<endl;
}

void ActOne::draw(){
    //ofBackground(0);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(primaryColor);
    ofRectMode(OF_RECTMODE_CENTER);
    //ofRect(recLoc,50,50);

    ofSetLineWidth(10);
    //curtain.setFilled(false);
    //curtain.setStrokeColor(primaryColor);
    //curtain.setStrokeWidth(10);
    //curtain.setCurveResolution(1000);
//
//    if(curtainPoints.size()>4){
//        for (int i=0;i<curtainPoints.size();i++){
//            curtain.curveTo(curtainPoints[i]);
//        }
//    }else{
//    }
    curtain.draw();
    ofPopMatrix();
    
    theWave.draw();
    
    pBoss.draw();
    
    
    
}

void ActOne::setLoc(ofVec3f l){
    newLoc = l*800;
    recLoc += (newLoc-recLoc)*0.1;
    
    curtainPoints.push_front(recLoc);
    if(curtainPoints.size()>NUM_CURTAIN_POINTS){
        curtainPoints.pop_back();
    }
    
}
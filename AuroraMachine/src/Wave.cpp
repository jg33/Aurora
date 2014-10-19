//
//  Wave.cpp
//  AuroraMachine
//
//  Created by Jesse Garrison on 10/18/14.
//
//

#include <stdio.h>
#include "Wave.h"

void Wave::setup(){
    size = 100;
    color = ofColor::magenta;
    pos = ofVec2f(300,300);
    

};

void Wave::update(){

    acc.x = ofClamp(acc.x, -3., 3.);
    vel+= acc;
    vel.x = ofClamp(vel.x, -3., 3.);
    pos+= vel;
    
    customUpdate();
    
    wrap();

    
};

void Wave::draw(){
    ofSetColor(color);
    //ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetLineWidth(1);
    //ofRect(pos.x, ofGetHeight()/2,size/10, ofGetHeight());
    
    for (int i = 0; i<size;i++ ){
        ofSetColor(color, (((size-i)/size)*100 ) );
        ofLine(pos.x+i, 0, pos.x+i, ofGetHeight());
        ofLine(pos.x-i, 0, pos.x-i, ofGetHeight());
        
    }
    
    customDraw();
    
    
};
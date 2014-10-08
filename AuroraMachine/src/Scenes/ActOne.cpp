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
    
}

void ActOne::update(){
    
    cout<< "updating"<<endl;
    
}

void ActOne::draw(){
    ofBackground(0);
    ofSetColor(255);
    ofRect(0,0,50,50);

    
}
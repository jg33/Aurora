//
//  Particle.h
//  StringMachine
//
//  Created by Jesse Garrison on 10/9/14.
//
//

#ifndef __StringMachine__Particle__
#define __StringMachine__Particle__

#include <stdio.h>
#include "ofMain.h"
#include "ofxAppUtils.h"

class Particle: public ofxParticle{
    
public:
    Particle(): ofxParticle(){setup();};
    
    virtual void setup(){
        seed = ofRandom(1000);
    };
    void update(){
        updateAge();
        vel+= acc;
        pos+=vel;
        customUpdate();
    };
    virtual void draw(){};
    
    virtual void customUpdate(){};
    virtual void customDraw(){};
    
protected:
    ofVec3f pos, vel, acc;
    int seed;
    
};


class Dust: public Particle{
    
    
public:
    Dust(ofVec3f l): Particle(){pos=l; setLifespan(ofRandom(6000));};
    
    void customUpdate(){
        ofVec3f lift = ofVec3f(
            ofSignedNoise(ofGetElapsedTimef()+seed)*2,
            ofSignedNoise(ofGetElapsedTimef()*1.22+seed+66)-1,
            ofSignedNoise(ofGetElapsedTimef()*1.3829+seed+270)
        
        );
        lift*=0.01;
        
        vel+= lift;
        
        if(pos.y<0) bAlive=false;
    }
    
    void draw(){
        ofPushStyle();
        ofSetColor(ofColor::limeGreen);
        ofCircle(pos, 1);
        ofPopStyle();
    }
    
};

#endif /* defined(__StringMachine__Particle__) */

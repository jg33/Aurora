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
    ofColor myColor;
    
};


class Dust: public Particle{
    
    
public:
    Dust(ofVec3f l): Particle(){
        Dust(l,ofColor::limeGreen);
    };
    
    Dust(ofVec3f l, ofColor c): Particle(){
        pos=l;
        setLifespan(ofRandom(6000));
        setup();
        myColor = c;
    };
    
    void customUpdate(){
        ofVec3f lift = ofVec3f(
            ofSignedNoise(ofGetElapsedTimef()+seed)*2,
            ofSignedNoise(ofGetElapsedTimef()*1.22+seed+66)-1,
            ofSignedNoise(ofGetElapsedTimef()*1.3829+seed+270)
        
        );
        lift*=0.02;
        
        vel+= lift;
        
        //if(pos.y<0) bAlive=false;
        
        myColor.setBrightness(ofMap(sin((pos.x*0.01)+(ofGetElapsedTimef()*3 ) ),-1,1,50,255));
        
        position = pos;
    }
    
    void draw(){
        ofPushStyle();
        ofSetColor(myColor);
        ofDrawCircle(pos, 1);
        ofPopStyle();
    }
    
};

#endif /* defined(__StringMachine__Particle__) */

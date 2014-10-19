//
//  SubWave.h
//  AuroraMachine
//
//  Created by Jesse Garrison on 10/18/14.
//
//

#ifndef AuroraMachine_SubWave_h
#define AuroraMachine_SubWave_h

#include "Wave.h"

class SubWave : public Wave {
    
public:
    SubWave(): Wave(){setup();};
    
    void setup(){
        color = ofColor(0,255,0);
        //seed = ofRandom(666);
    };
    
    void customUpdate(){
        acc = ofVec2f(ofSignedNoise((ofGetElapsedTimef())*1000)*0.1,0);
        
    };
    
    void customDraw(){
        
    };
    
private:
    int seed;
    
    
};
#endif

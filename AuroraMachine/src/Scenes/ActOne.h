//
//  ActOne.h
//  AuroraMachine
//
//  Created by Jesse Garrison on 10/7/14.
//
//

#ifndef __AuroraMachine__ActOne__
#define __AuroraMachine__ActOne__

#define NUM_CURTAIN_POINTS 50

#include <iostream>


#include "ofMain.h"
#include "ofxAppUtils.h"
#include "Particle.h"

class ActOne : public ofxScene{
public:
    ActOne():ofxScene("ActOne"){}
    void setup();
    void update();
    void draw();
    void exit(){};
    void updateEnter(){};
    void updateExit(){};
    
    void setLoc (ofVec3f l);
    void inline setAlt (float f){altitude = f;};
    
private:
    ofxApp * app;
    
    ofVec3f recLoc;
    
    ofColor lowColor, midColor, highColor;
    
    ofColor primaryColor;
    float altitude;
    
    deque<ofVec3f> curtainPoints;
    deque<ofColor> curtainColors;
    ofPath curtain;
    
};

#endif /* defined(__AuroraMachine__ActOne__) */

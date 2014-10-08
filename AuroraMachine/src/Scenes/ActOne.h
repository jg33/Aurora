//
//  ActOne.h
//  AuroraMachine
//
//  Created by Jesse Garrison on 10/7/14.
//
//

#ifndef __AuroraMachine__ActOne__
#define __AuroraMachine__ActOne__

#include <iostream>


#include "ofMain.h"
#include "ofxAppUtils.h"

class ActOne : public ofxScene{
public:
    ActOne():ofxScene("ActOne"){}
    void setup();
    void update();
    void draw();
    void exit(){};
    void updateEnter(){};
    void updateExit(){};
    
    void inline setRecLoc (ofVec3f l){recLoc = l*500;};
    void inline setAlt (float f){altitude = f;};
    
private:
    ofxApp * app;
    
    ofVec3f recLoc;
    
    ofColor lowColor, highColor;
    
    ofColor primaryColor;
    float altitude;
};

#endif /* defined(__AuroraMachine__ActOne__) */

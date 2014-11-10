//
//  ActOne.h
//  AuroraMachine
//
//  Created by Jesse Garrison on 10/7/14.
//
//

#ifndef __AuroraMachine__ActOne__
#define __AuroraMachine__ActOne__

#define NUM_CURTAIN_POINTS 500
#define LINE_RESOLUTION_FOR_PARTICLES 25
#define MOCK_INPUT false

#include <iostream>


#include "ofMain.h"
#include "ofxAppUtils.h"
#include "Particle.h"
#include "Wave.h"
#include "BigWave.h"

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
    
    void setWaveDir(ofVec2f v){theWave.setAcc(v);};
    void setWaveWidth(float width){waveWidth = width; };
    void setFlow(float f){flow=f;};
    
private:
    ofxApp * app;
    
    ofVec3f recLoc, newLoc;
    
    ofColor lowColor, midColor, highColor;
    
    ofColor primaryColor;
    float altitude;
    
    deque<ofVec3f> curtainPoints, mockPoints;
    ofPolyline curtain;
    
    BigWave theWave;
    
    float flow;
    float waveWidth;
    
    ofxParticleManager pBoss;
    
};

#endif /* defined(__AuroraMachine__ActOne__) */

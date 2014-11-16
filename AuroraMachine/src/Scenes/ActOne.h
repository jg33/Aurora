//
//  ActOne.h
//  AuroraMachine
//
//  Created by Jesse Garrison on 10/7/14.
//
//

#ifndef __AuroraMachine__ActOne__
#define __AuroraMachine__ActOne__

#define NUM_CURTAIN_POINTS 1000
#define LINE_RESOLUTION_FOR_PARTICLES 25
#define MOCK_INPUT false

#include <iostream>


#include "ofMain.h"
#include "ofxAppUtils.h"
#include "Particle.h"
#include "Wave.h"
#include "BigWave.h"
#include "Curtain.h"


class ActOne : public ofxScene{
public:
    ActOne():ofxScene("ActOne"){}
    void setup();
    void update();
    void draw();
    void updateEnter(){};
    void updateExit(){};
    void exit(){
        curtain1.waitForThread();
        curtain2.waitForThread();
        curtain3.waitForThread();
    };
    
    void setLoc (int i, ofVec3f l);
    void inline setAlt (float f){altitude = f;};
    
    //void setWaveDir(ofVec2f v){theWave.setAcc(v);};
    void setWaveWidth(float width){waveWidth = width; };
    void setFlow(int i, float f);
    
private:
    ofxApp * app;
    
    ofVec3f recLoc, newLoc;
    
    ofColor lowColor, midColor, highColor;
    
    ofColor primaryColor;
    float altitude;
    
    Curtain curtain1, curtain2, curtain3;
    
    
    deque<ofVec3f> curtainPoints, mockPoints;
    ofPolyline curtain;
    
    //BigWave theWave;
    
    bool bIsIdle1, bIsIdle2, bIsIdle3;
    float waveWidth;
    
    ofxParticleManager pBoss;
    
};

#endif /* defined(__AuroraMachine__ActOne__) */

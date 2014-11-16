//
//  Curtain.h
//  AuroraMachine
//
//  Created by Jesse Garrison on 11/9/14.
//
//

#ifndef __AuroraMachine__Curtain__
#define __AuroraMachine__Curtain__

#include <stdio.h>
#include "ofMain.h"
#include "Particle.h"
#include "ofxAppUtils.h"

#define MAX_LINE_POINTS 300
#define LINE_RESOLUTION_FOR_PARTICLES 25
#define MAX_IDLE 6000

class Curtain : public ofThread{
    
    
public:
    ofColor color;
    
    void threadedFunction();
    void update();
    void draw();
    
    void setLoc(ofVec3f l);
    void setFlow(float f){flow=f;};
    
    void resetIdleTimer(){idleTimer =0;};
    
private:
    void idle();
    bool bIsIdle;
    int idleTimer;

    
    float flow;

    ofVec3f currentLoc, targetLoc;

    deque<ofVec3f> points;
    ofPolyline line;
    
    ofxParticleManager pBoss;
    vector<ofVec3f> particleQueue;
    bool bAreParticlesQueued;
    vector<ofxParticle*>* tempParticles;
    ofMesh particleMesh;
    
    
};


#endif /* defined(__AuroraMachine__Curtain__) */

//
//  Curtain.cpp
//  AuroraMachine
//
//  Created by Jesse Garrison on 11/9/14.
//
//

#include "Curtain.h"

void Curtain::threadedFunction(){
    pBoss.setAutoRemove(true);
    particleMesh.setMode(OF_PRIMITIVE_POINTS);


    while(isThreadRunning()){
        setFlow(0.5);

        update();
        

        if(bAreParticlesQueued){
            for (int i=0; i< particleQueue.size(); i++){
                pBoss.addParticle(new Dust(particleQueue[i], color ));
            }
        }
        
        pBoss.update();
    }
    
}

void Curtain::update(){
    
    currentLoc += (targetLoc-currentLoc)*0.04;
    
    points.push_front(currentLoc);
    if (points.size() > MAX_LINE_POINTS ){
        points.pop_back();
    }
    
    if(idleTimer>MAX_IDLE){
        ofVec3f noiseVert = ofVec3f(ofSignedNoise((ofGetSystemTime()*0.00000000001) ), ofSignedNoise(340+(ofGetSystemTime()*0.000000000033)),ofSignedNoise(826+(ofGetSystemTime()*0.00000000000078)));
        currentLoc+=noiseVert*500;
        
        setLoc(currentLoc);
        
        idleTimer = 0;
        
    } else{
        idleTimer++;
    }
    
    
    ofPolyline tempLine;
    for(int i=0;i<points.size();i++){
        ofVec3f noiseVert = ofVec3f(ofSignedNoise(i+(ofGetSystemTime()*0.00000000001) ), ofSignedNoise(i+50+(ofGetSystemTime()*0.000000000033)),ofSignedNoise(i+76+(ofGetSystemTime()*0.00000000000078)));
        noiseVert*=1000;
        points[i]+=noiseVert;//

        tempLine.curveTo(points[i]);

    }
    
    bAreParticlesQueued = false;
    particleQueue.clear();
    
    for (float i= 0; i< LINE_RESOLUTION_FOR_PARTICLES;i++){
        ofPoint thisPoint = tempLine.getPointAtPercent((i/LINE_RESOLUTION_FOR_PARTICLES) + ofSignedNoise(ofGetElapsedTimef()+(i*5.66)));
        //thisPoint += ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
        if(ofRandom(1) < flow){
            particleQueue.push_back(ofVec3f(thisPoint));
        }
    }

    tempParticles = pBoss.getParticlesPtr();

    lock();
    line=tempLine;
    
    bAreParticlesQueued = true;
    
    for( int i = 0; i< tempParticles->size();i++){
        particleMesh.addVertex( tempParticles->at(i)->position );
        particleMesh.addColor(color);
    }
    unlock();

}

void Curtain::draw(){
    ofPushStyle();
    ofSetColor(color);
    //ofDrawRectangle(currentLoc, 10, 10);
    
    line.draw();
    
    //lock();
    //pBoss.draw();
    //unlock();
    glPointSize(3);
    
    lock();
    particleMesh.draw();
    particleMesh.clear();
    unlock();
    
    ofPopStyle();
    
}

void Curtain::setLoc(ofVec3f l){
    
    targetLoc = l;
    

    
}
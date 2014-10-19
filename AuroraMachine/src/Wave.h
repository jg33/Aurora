//
//  Wave.h
//  AuroraMachine
//
//  Created by Jesse Garrison on 10/18/14.
//
//

#ifndef __AuroraMachine__Wave__
#define __AuroraMachine__Wave__

#include <stdio.h>
#include "ofMain.h"

class Wave{
    
public:
    Wave(){setup();};
    ~Wave(){};
    void setup();
    
    void update();
    
    void draw();
    
    virtual void customDraw(){};
    virtual void customUpdate(){};
    
    void setAcc(ofVec2f a){
        acc = a;
    };
    ofVec2f getPos(){
        return pos;
    };
    void setPos(int x, int y){
        pos= ofVec2f(x,y);
    }
    
    void setSize(float s){
        size = s;
    }
    
    void wrap(){
        if (pos.x< 0-size){
            pos.x = ofGetWidth()+size;
        } else if (pos.x > ofGetWidth()+size){
            pos.x = 0-size;
        }
    }
    
protected:
    ofVec2f pos, vel, acc;
    
    float size;
    
    ofColor color;
    
};






#endif /* defined(__AuroraMachine__Wave__) */

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
    
private:
    ofxApp * app;
    
};

#endif /* defined(__AuroraMachine__ActOne__) */

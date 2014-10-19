//
//  BigWave.h
//  AuroraMachine
//
//  Created by Jesse Garrison on 10/18/14.
//
//

#ifndef AuroraMachine_BigWave_h
#define AuroraMachine_BigWave_h

#include "SubWave.h"
#define NUM_KIDS 50

class BigWave :public Wave{
    
public:
    BigWave():Wave(){setup();};
    
    void setup(){
        /*
        for(int i = 0; i< NUM_KIDS-1;i++){
            children.push_back(SubWave());
            children[children.size()].setSize(ofRandom(size/10));
            children[children.size()].setPos(pos.x+ 2-ofRandom(2) ,pos.y);
        }
         */
    }
    
    void customUpdate(){
        for (int i=0;i<children.size();i++){
          //  children[i].update();
            
        }
    };
    
    
    void customDraw(){
        
        for (int i=0;i<children.size();i++){
            //children[i].draw();
        }
    }
    
private:
    vector<SubWave> children;
    
};



#endif

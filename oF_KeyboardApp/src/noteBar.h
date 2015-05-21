//
//  noteBar.h
//  oF_KeyboardApp
//
//  Created by 櫻木善将 on 2015/05/21.
//
//

#ifndef __oF_KeyboardApp__noteBar__
#define __oF_KeyboardApp__noteBar__

#include <stdio.h>
#include "ofMain.h"

#define DOWN_SPEED 10
#define MAX_HEIGHT 300
#define MIN_HEIGHT 50
#define SPEED_RATE 10
#define MIN_SPEED  5 //use this atatch minus
#define MAX_SPEED 20

class noteBar {
private:
    
    double height;
    double speed;
    int note;
    //bool increasing;
    
public:
    noteBar(int note){
        
        this -> note = note;
        height = 0.0;
        speed = 0.0;
       // increasing = false;
    
    }
    
    ~noteBar(){}
    
    void up(double velocity){
        if(speed > MAX_SPEED){
            return;
        }
        speed += (double)velocity;
    }
    
    void update(){
        
        
        if(speed >= -(MIN_SPEED)){
            speed -= DOWN_SPEED ;
        }else{
            speed = - (MIN_SPEED) ;
        }
        
        
        if(height >= MIN_HEIGHT && height <= MAX_HEIGHT ){
            height += speed;
        }
        if(height < MIN_HEIGHT){
            height = MIN_HEIGHT ;
            
        }
        if(height >= MAX_HEIGHT){
            height = MAX_HEIGHT ;
            speed = - (MIN_SPEED);
            
        }
    
    }
    
    double getHeight(){
        return this -> height;
    }
};



#endif /* defined(__oF_KeyboardApp__noteBar__) */

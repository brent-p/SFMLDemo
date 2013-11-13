/* 
 * File:   InputStateController.h
 * Author: Brent Parish
 *
 * Created on November 13, 2013, 6:10 PM
 */


#ifndef InputStateController_H
#define InputStateController_H

#include "Input.h"
#include "Gamepad.h"
#include "Keyboard.h"

class InputStateController{
private:
	//private member variables
        bool pressLeft;
        bool pressRight;
        
public: 
        InputStateController();
        void getInput();
        bool isPressingRight();
        bool isPressingLeft();
        
};
#endif





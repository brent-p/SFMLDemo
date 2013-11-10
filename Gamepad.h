/* 
 * File:   Gamepad.h
 * Author: Brent Parish
 *
 * Created on November 10, 2013, 10:22 PM
 */


#ifndef Gamepad_H
#define Gamepad_H
#include "Input.h"
#include <SFML/Window.hpp>
class Gamepad : public Input
{
protected:
	//private member variables
        
public: 
        Gamepad();
        bool left();
        bool right();
};
#endif





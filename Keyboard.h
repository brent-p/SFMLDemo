/* 
 * File:   Keyboard.h
 * Author: Brent Parish
 *
 * Created on November 10, 2013, 10:22 PM
 */


#ifndef Keyboard_H
#define Keyboard_H
#include "Input.h"
#include <SFML/Window.hpp>
class Keyboard : public Input
{
protected:
	//private member variables
        
public: 
        Keyboard();
        bool left();
        bool right();
};
#endif





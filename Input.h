/* 
 * File:   Input.h
 * Author: Brent Parish
 *
 * Created on November 10, 2013, 10:22 PM
 */


#ifndef Input_H
#define Input_H
#include <SFML/Window.hpp>

class Input
{
protected:
	//private member variables
        bool isConnected;
        
public: 
        Input();
        bool getIsConnected();
        virtual bool left() = 0;
        virtual bool right() = 0;
};
#endif





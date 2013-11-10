/* 
 * File:   Gamepad.h
 * Author: Brent Parish
 *
 * Created on November 10, 2013, 10:28 PM
 */


#include "Gamepad.h"
#include <SFML/Window.hpp>

Gamepad::Gamepad(): Input()
{
        if (sf::Joystick::isConnected(0))
        {
                isConnected = true;
                sf::Joystick::update();
        }
}

bool Gamepad::left()
{
        float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
        if(x < -25)
        {
            return true;
        }
        else
        {
            return false;
        }
}

bool Gamepad::right()
{
        float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
        if(x > 25)
        {
                return true;
        }
        else
        {
                return false;
        }
}






/* 
 * File:   Keyboard.h
 * Author: Brent Parish
 *
 * Created on November 10, 2013, 10:28 PM
 */


#include "Keyboard.h"
#include <SFML/Window.hpp>

Keyboard::Keyboard(): Input()
{
    isConnected = true;
}

bool Keyboard::left()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Keyboard::right()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        return true;
    }
    else
    {
        return false;
    }
}






/* 
 * File:   InputStateController.cpp
 * Author: Brent Parish
 *
 * Created on November 13, 2013, 6:14 PM
 */

#include "InputStateController.h"

#define MAX_INPUTS 2
 Input* inputs[MAX_INPUTS];
 


InputStateController::InputStateController()
{
    pressLeft = false;
    pressRight = false;
    inputs[0] = new Keyboard();
    inputs[1] = new Gamepad();
}

void InputStateController::getInput()
{
    pressLeft = false;
    pressRight = false;
    for(int i = 0; i < MAX_INPUTS; i++) // loop through different input devices
    {
        if(inputs[i]->getIsConnected())
        {
            if(inputs[i]->left())
            {
                pressLeft = true;
            }
            if(inputs[i]->right())
            {
                pressRight = true;
            }
        }
    }
}

bool InputStateController::isPressingRight()
{
    return pressRight;
}

bool InputStateController::isPressingLeft()
{
    return pressLeft;
}

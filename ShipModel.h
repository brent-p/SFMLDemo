/* 
 * File:   ShipModel.h
 * Author: Brent Parish
 *
 * Created on November 6, 2013, 7:32 PM
 */


#ifndef ShipModel_H
#define ShipModel_H

#include "Model.h"

class ShipModel : public Model
{
private:
	//private member variables
        GLfloat rotateShip;
        
public: 
        //Overide Methods
        ShipModel(std::string name);
        void draw();
        void updateLogic(InputStateController *inputState);
        
        GLfloat getRotateShip();
        void setRotateShip(GLfloat rotate);
};
#endif





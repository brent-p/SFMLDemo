/* 
 * File:   GameManager.h
 * Author: Brent Parish
 *
 * Created on November 6, 2013, 7:32 PM
 */


#ifndef ShipModel_H
#define ShipModel_H

#include "Model.h"
//#include <string>

class ShipModel : public Model
{
private:
	//private member variables
        GLfloat rotateShip;
        
public: 
        ShipModel(std::string name);
        //ShipModel();
        void draw();
};
#endif





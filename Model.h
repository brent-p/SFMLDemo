/* 
 * File:   GameManager.h
 * Author: Brent Parish
 *
 * Created on November 6, 2013, 7:32 PM
 */


#ifndef Model_H
#define Model_H

#include <string>
#include "Ply/PlyModel.h"
#include "InputStateController.h"
#include <SFML/OpenGL.hpp>

class Model
{
protected:
	//private member variables
        std::string modelName;
        PlyModel* model;
        GLfloat posX;
        GLfloat posY;
        GLfloat posZ;
        
public: 
        Model(std::string name);
        virtual void draw() = 0;
        virtual void updateLogic(InputStateController *inputState) = 0;
};
#endif





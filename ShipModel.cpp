/* 
 * File:   GameManager.h
 * Author: Brent Parish
 *
 * Created on November 6, 2013, 7:32 PM
 */



#include <string>
#include <SFML/OpenGL.hpp>
#include "ShipModel.h"
//#include "Ply/PlyModel.h"

/*ShipModel::ShipModel()
{
}*/

/*void ShipModel::draw()
{
    //stuff
}*/

ShipModel::ShipModel(std::string name): Model(name) 
{
        rotateShip = 0.0f;
}


void ShipModel::draw()
{
    GLfloat scale = 0.08f;
    glColor3f(1.0f,1.0f,1.0f);
    //rotateShip = rotateShip + .5f;
    glTranslatef(0.0f, 0.0f, -1.5f);
    glRotatef(rotateShip,0,1.0f,0.0f);
    glRotatef(-90.0f,1.0f,0,0);
	
    //Set up the correct orientation of the ship
    glScalef(scale,scale,scale);
	
    model->draw();				// Draw the ship model
	
    //Reverse Transformations
    glScalef(1/scale,1/scale,1/scale);
    glRotatef(-90.0f,1.0f,0,0);
    glRotatef(-rotateShip,0,1.0f,0.0f);
    glTranslatef(0.0f,0.0f, 1.5f);
}

GLfloat ShipModel::getRotateShip()
{
    return rotateShip;
}

void ShipModel::setRotateShip(GLfloat rotate)
{
    rotateShip = rotate;
}
    



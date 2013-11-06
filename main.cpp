/* 
 * File:   main.cpp
 * Author: Brent Parish
 *
 * Created on November 2, 2013, 7:32 PM
 */

#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Ply/PlyModel.h"
#include "gameManager.h"

using namespace std;

/*
 * 
 */
GLfloat rotateMenuShip = 0.0f;
PlyModel* shipModel;
GameManager* gameManager;

void drawMenuShip()
{
	GLfloat scale = 0.08f;
        glColor3f(1.0f,1.0f,1.0f);
	rotateMenuShip = rotateMenuShip + .5f;
	glTranslatef(0.0f, 0.0f, -1.5f);
	glRotatef(rotateMenuShip,0,1.0f,0.0f);
	glRotatef(-90.0f,1.0f,0,0);
	
	//Set up the correct orientation of the ship
	glScalef(scale,scale,scale);
	
	shipModel->draw();				// Draw the ship model
	
	//Reverse Transformations
	glScalef(1/scale,1/scale,1/scale);
	glRotatef(-90.0f,1.0f,0,0);
	glRotatef(-rotateMenuShip,0,1.0f,0.0f);
	glTranslatef(0.0f,0.0f, 1.5f);
}

int main(int argc, char** argv) 
{
        // Initialise Game Manager
        gameManager = new GameManager(800,600);
        
        //Create the window
        gameManager->createWindow();
        
        // load resources, initialize the OpenGL states
        shipModel = new PlyModel("./data/ship.ply",false);

        // run the main game loop
        bool running = true;
        while (running)
        {
            // handle events
            running = gameManager->handleEvents();

            // clear the buffers
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();        
            
            // draw...
            drawMenuShip();
            
            gameManager->drawToScreen();
        }

        // release resources...

        return 0;
}






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

using namespace std;

/*
 * 
 */
GLfloat rotateMenuShip = 0.0f;
PlyModel* shipModel;

void setupGl()
{
        glEnable(GL_TEXTURE_2D);                                                // Enable texture mapping
        glBlendFunc(GL_SRC_ALPHA,GL_ONE);                                       // Set the blending function for translucency
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                                   // This will clear the background color to black
        glClearDepth(1.0);                                                      // Enables clearing of the depth buffer
        glDepthFunc(GL_LESS);                                                   // The type of depth test to do
        glEnable(GL_DEPTH_TEST);                                                // Enables depth testing
        glShadeModel(GL_SMOOTH);                                                // Enables smooth color shading
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);                      // Really nice perspective calculations
        glDisable(GL_BLEND);      // Turn blending off
        glEnable(GL_DEPTH_TEST);  // Turn depth testing on
        shipModel = new PlyModel("ship.ply",false);
        //printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
    
}

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

//Setup View Frustum
GLvoid resizeGLScene(GLsizei width, GLsizei height)                             // Resize and initialize the GL window
{
        if (height==0)                                                          // Prevent a divide by zero by
        {
                height=1;                                                       // Making height equal one
        }

        glViewport(0,0,width,height);                                           // Reset the current viewport

        glMatrixMode(GL_PROJECTION);                                            // Select the projection matrix
        glLoadIdentity();                                                       // Reset the projection matrix

        // Calculate the aspect ratio of the window
        gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

        glMatrixMode(GL_MODELVIEW);                                             // Select the modelview matrix
        glLoadIdentity();                                                       // Reset the modelview matrix
}

int main(int argc, char** argv) 
{
         // create the window
    
        sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
        window.setVerticalSyncEnabled(true);
    
        // load resources, initialize the OpenGL states, ...
        setupGl();
        resizeGLScene(800, 600);

        // run the main loop
        bool running = true;
        while (running)
        {
                // handle events
                sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                        {
                                // end the program
                                running = false;
                        }
                        else if (event.type == sf::Event::Resized)
                        {
                                // adjust the viewport when the window is resized
                                //glViewport(0, 0, event.size.width, event.size.height);
                                resizeGLScene(event.size.width,event.size.height);
                        }
                }

                // clear the buffers
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glLoadIdentity();        
                // draw...
                drawMenuShip();
                // end the current frame (internally swaps the front and back buffers)
                window.display();
          }

        // release resources...

        return 0;
}






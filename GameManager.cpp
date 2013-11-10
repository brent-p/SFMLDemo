/* 
 * File:   GameManager.cpp
 * Author: Brent Parish
 *
 * Created on November 6, 2013, 7:32 PM
 */

#include "GameManager.h"

 Input* inputs[2];


GameManager::GameManager(GLsizei width, GLsizei height)
{
    windowWidth = width;
    windowHeight = height;
}

void GameManager::createWindow()
{
    window.create(sf::VideoMode(windowWidth, windowHeight), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    setupGl();
    resizeGLScene();
    inputs[0] = new Keyboard();
    inputs[1] = new Gamepad();
}

bool GameManager::handleEvents()
{
     sf::Event event;
     while (window.pollEvent(event))
     {
             if (event.type == sf::Event::Closed)
             {
                // end the program
                return false;
             }
             else if (event.type == sf::Event::Resized)
             {
                // adjust the viewport when the window is resized
                windowWidth = event.size.width;
                windowHeight = event.size.height;
                resizeGLScene();
             }
     }
     getInput();
     return true;
}

// end the current frame (internally swaps the front and back buffers)
void GameManager::drawToScreen()
{
    window.display();
}

void GameManager::resizeGLScene()
{
   if (windowHeight == 0)                                                       // Prevent a divide by zero by
   {
        windowHeight = 1;                                                 // Making height equal one
   }

        glViewport(0,0,windowWidth,windowHeight);                               // Reset the current viewport

        glMatrixMode(GL_PROJECTION);                                            // Select the projection matrix
        glLoadIdentity();                                                       // Reset the projection matrix

        // Calculate the aspect ratio of the window
        gluPerspective(45.0f,(GLfloat)windowWidth/(GLfloat)windowHeight,0.1f,100.0f);

        glMatrixMode(GL_MODELVIEW);                                             // Select the modelview matrix
        glLoadIdentity();                                                       // Reset the modelview matrix
}

void GameManager::setupGl()
{
    glEnable(GL_TEXTURE_2D);                                                    // Enable texture mapping
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);                                           // Set the blending function for translucency
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                                       // This will clear the background color to black
    glClearDepth(1.0);                                                          // Enables clearing of the depth buffer
    glDepthFunc(GL_LESS);                                                       // The type of depth test to do
    glEnable(GL_DEPTH_TEST);                                                    // Enables depth testing
    glShadeModel(GL_SMOOTH);                                                    // Enables smooth color shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);                          // Really nice perspective calculations
    glDisable(GL_BLEND);                                                        // Turn blending off
    glEnable(GL_DEPTH_TEST);                                                    // Turn depth testing on
    
    lighting = new Lighting();
    
    
}

void GameManager::clearBuffers()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
}

void GameManager::getInput()
{
    pressLeft = false;
    pressRight = false;
    for(int i = 0; i < 2; i++) // loop through different input devices
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

void GameManager::updateModels()
{
        if(pressRight)
        {
                rotateShip = rotateShip + 2.0f;
                shipModel->setRotateShip(rotateShip);
        }
        else
        {
                shipModel->setRotateShip(rotateShip);
        }
        
        if(pressLeft)
        {
            rotateShip = rotateShip - 2.0f;
            shipModel->setRotateShip(rotateShip);
        }
        else
        {
            shipModel->setRotateShip(rotateShip);
        }
}

void GameManager::setupModels()
{
    shipModel = new ShipModel("./data/ship.ply");
    rotateShip = 0;
}

void GameManager::drawModels()
{
    shipModel->draw();
}
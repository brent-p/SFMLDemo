/* 
 * File:   main.cpp
 * Author: Brent Parish
 *
 * Created on November 2, 2013, 7:32 PM
 */

#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include "gameManager.h"
#include "Model.h"
#include "shipModel.h"

using namespace std;


ShipModel* shipModel;
GameManager* gameManager;
bool running = true;
sf::Texture texture;
float lastx = 0; 
float rotateShip = 0;

void loadTexture()
{
        if (!texture.loadFromFile("data/logo.bmp"))
        {
                // error...
        }
}
 
 //Draw a cube at a specific position
void drawQuad(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat width, GLfloat height, GLfloat depth)
{
    
        //glBindTexture(GL_TEXTURE_2D, texture[filter]);
        sf::Texture::bind(&texture);
        glTranslatef(posX, posY, posZ);
        glBegin(GL_QUADS);
                // Back Face
                glNormal3f( 0.0f, 0.0f,-1.0f);
                glTexCoord2f(1.0f, 0.0f); glVertex3f(-width, -height, -depth);
                glTexCoord2f(1.0f, 1.0f); glVertex3f(-width,  height, -depth);
                glTexCoord2f(0.0f, 1.0f); glVertex3f( width,  height, -depth);
                glTexCoord2f(0.0f, 0.0f); glVertex3f( width, -height, -depth);
        glEnd();
        glTranslatef(-posX, -posY, -posZ);
        sf::Texture::bind(NULL);
}
 
 void drawtestSprite()
 {
     //Setup Diamond Run logo
        glColor3f(1.0f,1.0f,1.0f);
        drawQuad(0,0.4f,-1.0f,1.5f,1.5f,1.5f);
 }

 void updateShipRotation()
 {
     float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
     float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
     float newpos = x - lastx;
     cout << "Joy Stick Axes x:" << x <<" lastx:" << lastx << "newpos: " << newpos<< " y:" << y << endl;
     if(x > 0)
     {
        if(x > 25)
        {
                cout << "greater than 10" << endl;
                rotateShip = rotateShip + 2.0f;
                shipModel->setRotateShip(rotateShip);
        }
        else
        {
                //rotateShip = 0.0f;
                shipModel->setRotateShip(rotateShip);
        }
     }
     {
        if(x < -25)
        {
            cout << "less than 10" << endl;
            rotateShip = rotateShip - 2.0f;
            shipModel->setRotateShip(rotateShip);
        }
        else
        {
            //rotateShip = 0.0f;
            shipModel->setRotateShip(rotateShip);
        }
     }
     
 }
 
 
int main(int argc, char** argv) 
{
        // Initialise Game Manager
        gameManager = new GameManager(800,600);
        
        //Create the window
        gameManager->createWindow();
        
        // load resources, initialize the OpenGL states
        shipModel = new ShipModel("./data/ship.ply");
        loadTexture();
        
         if (sf::Joystick::isConnected(0))
         {
                cout << "Joy stick connected" << endl;
                sf::Joystick::update();
                lastx = sf::Joystick::getAxisPosition(0, sf::Joystick::X);        
                cout << "last x:" << lastx << endl;
         }

        // run the main game loop       
        while (running)
        {
            // handle events
            running = gameManager->handleEvents();
            if(!running) break; //exit
            
            // clear the buffers
            gameManager->clearBuffers();
            
            // Setup all entities to be drawn
            drawtestSprite();
            updateShipRotation();
            shipModel->draw();
            gameManager->drawToScreen();
            
           
            
        }

        // release resources...

        return 0;
}






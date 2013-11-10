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


GameManager* gameManager;
bool running = true;
sf::Texture texture;

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
        glDisable(GL_LIGHT1);
        glDisable(GL_LIGHTING);
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
        glEnable(GL_LIGHT1);                                        // Enable Light1
        glEnable(GL_LIGHTING);                                      // Enable Lighting
}
 
 void drawtestSprite()
 {
     //Setup Diamond Run logo
        glColor3f(1.0f,1.0f,1.0f);
        drawQuad(0,0.4f,-1.0f,1.5f,1.5f,1.5f);
 }
 
int main(int argc, char** argv) 
{
        // Initialise Game Manager
        gameManager = new GameManager(800,600);
        
        //Create the window
        gameManager->createWindow();
        gameManager->setupModels();
        // load resources, initialize the OpenGL states
        
        loadTexture();
        
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
            gameManager->updateModels();
            gameManager->drawModels();
            gameManager->drawToScreen();
            
        }

        // release resources...

        return 0;
}






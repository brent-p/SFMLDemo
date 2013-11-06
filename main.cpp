/* 
 * File:   main.cpp
 * Author: Brent Parish
 *
 * Created on November 2, 2013, 7:32 PM
 */

#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "gameManager.h"
#include "Model.h"
#include "shipModel.h"

using namespace std;


Model* shipModel;
GameManager* gameManager;
 bool running = true;

int main(int argc, char** argv) 
{
        // Initialise Game Manager
        gameManager = new GameManager(800,600);
        
        //Create the window
        gameManager->createWindow();
        
        // load resources, initialize the OpenGL states
        shipModel = new ShipModel("./data/ship.ply");

        // run the main game loop       
        while (running)
        {
            // handle events
            running = gameManager->handleEvents();
            if(!running) break; //exit
            
            // clear the buffers
            gameManager->clearBuffers();
            
            // Setup all entities to be drawn
            shipModel->draw();
            
            gameManager->drawToScreen();
        }

        // release resources...

        return 0;
}






/* 
 * File:   GameManager.h
 * Author: Brent Parish
 *
 * Created on November 6, 2013, 7:32 PM
 */


#ifndef GameManager_H
#define GameManager_H

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Lighting.h"
#include "InputStateController.h"
#include "Model.h"
#include "shipModel.h"
#include <list>

using namespace std;

class GameManager{
private:
	//private member variables
        sf::Window window;
        GLsizei windowWidth;
        GLsizei windowHeight;
        Lighting* lighting;
        InputStateController* inputState;
        list<Model*> model_list;
        
public: 
        GameManager(GLsizei width, GLsizei height);
        void createWindow();
        bool handleEvents();
        void drawToScreen();    // end the current frame (internally swaps the front and back buffers)
        void resizeGLScene();
        void setupGl();
        void clearBuffers();
        void setupModels();
        void updateModels();
        void drawModels();
        void getInput();
};
#endif





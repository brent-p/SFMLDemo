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

class GameManager{
private:
	//private member variables
        sf::Window window;
        GLsizei windowWidth;
        GLsizei windowHeight;
        
public: 
        GameManager(GLsizei width, GLsizei height);
        void createWindow();
        bool handleEvents();
        void drawToScreen();    // end the current frame (internally swaps the front and back buffers)
        void resizeGLScene();
        void setupGl();
};
#endif





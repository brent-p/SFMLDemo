/* 
 * File:   Lighting.cpp
 * Author: Brent Parish
 *
 * Created on November 10, 2013, 9:43 PM
 */

#include "Lighting.h"
#include <cstdlib>

Lighting::Lighting() 
{
        setupLighting();
}

void Lighting::setupLighting()
{
        float LightPos[] = { 0.0f, 5.0f,-4.0f, 1.0f};                       // Light Position
        float LightAmb[] = { 0.2f, 0.2f, 0.2f, 1.0f};                       // Ambient Light Values
        float LightDif[] = { 0.6f, 0.6f, 0.6f, 1.0f};                       // Diffuse Light Values
        float LightSpc[] = {-0.2f, -0.2f, -0.2f, 1.0f};                     // Specular Light Values

        float MatAmb[] = {0.4f, 0.4f, 0.4f, 1.0f};                          // Material - Ambient Values
        float MatDif[] = {0.2f, 0.6f, 0.9f, 1.0f};                          // Material - Diffuse Values
        float MatSpc[] = {0.0f, 0.0f, 0.0f, 1.0f};                          // Material - Specular Values
        float MatShn[] = {0.0f};                                            // Material - Shininess
    
        glLightfv(GL_LIGHT1, GL_POSITION, LightPos);                // Set Light1 Position
        glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);                 // Set Light1 Ambience
        glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDif);                 // Set Light1 Diffuse
        glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpc);                // Set Light1 Specular

        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmb);        // Set Material Ambience
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDif);        // Set Material Diffuse
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpc);       // Set Material Specular
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, MatShn);      // Set Material Shininess

        enableLighting();
}
void Lighting::enableLighting()
{
        glEnable(GL_LIGHT1);                                        // Enable Light1
        glEnable(GL_LIGHTING);                                      // Enable Lighting
}

void Lighting::disableLighting()
{
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHTING);
}

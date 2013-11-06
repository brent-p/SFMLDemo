/* 
 * File:   GameManager.h
 * Author: Brent Parish
 *
 * Created on November 6, 2013, 7:32 PM
 */


#ifndef Model_H
#define Model_H

#include <string>
#include "Ply/PlyModel.h"

class Model
{
protected:
	//private member variables
        std::string modelName;
        PlyModel* model;
        
public: 
        Model(std::string name);
        //Model();
        virtual void draw() = 0;
};
#endif





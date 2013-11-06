/* 
 * File:   Model.h
 * Author: Brent Parish
 *
 * Created on November 6, 2013, 7:32 PM
 */


#include "Model.h"
#include <string>

//Model::Model()
Model::Model(std::string name)
{
    modelName = name;
    model = new PlyModel(name,false);
}






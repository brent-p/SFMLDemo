/* 
 * File:   PlyModel.h
 * Author: Brent Parish
 *
 * Created on November 6, 2013, 7:32 PM
 */

#ifndef PlyModel_H
#define PlyModel_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <SFML/OpenGL.hpp>
#include "PlyReader.h"

using namespace std;

class PlyModel{
private:
	PlyReader*          modelReader;
        
	int                 plyModelList;
        double              plyModelScale;
	int                 plyModelTexID;
	vector< vector<int> > modelFaces;  //needed for mac ???
        //vector<int> modelFaces;          //was being used on windows
	vector<ModelPoint>  modelVertex;
public: 
	PlyModel(string path,bool hasUVMap); // Constructor
	~PlyModel(); // Destructor 
	void draw();
	void drawQuads();
	void buildModelList(bool hasUVMap);	
};

#endif
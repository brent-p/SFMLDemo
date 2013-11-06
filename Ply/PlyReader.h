/* 
 * File:   PlyReader.h
 * Author: Brent Parish
 *
 * Created on November 6, 2013, 7:32 PM
 */

#ifndef PlyReader_H
#define PlyReader_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;



struct ModelPoint{
	float x; 
	float y;
	float z;
	float nx; //Normals?
	float ny;
	float nz;
	float u; //UV Mapping Texture Cordinates
	float v;

};

class PlyReader{
private:
	std::string filename; 
	std::string format; 
	int vertexCount; 
	int faceCount;
	vector<ModelPoint> vertex;
	vector< vector<int> > faceList; 
        
	
public: 
	PlyReader(std::string filename); // Constructor
	~PlyReader(){}; // Destructor 
	void parseFile();
	void parseHeader(std::string line);
	void parseVertex(std::string line, int i);
	void parseFace(std::string line, int i);
	vector< vector<int> > getFaceList();
	vector<ModelPoint> getVertexList();
        void readstr(FILE *f,char *string);
        
};
#endif
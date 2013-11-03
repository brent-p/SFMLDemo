#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <SFML/OpenGL.hpp>
//#include "bmp.h"
//#include <gl\glut.h>		// Header File For The Glaux Library
#include "PlyReader.h"
using namespace std;


class PlyModel{
private:
	PlyReader*          modelReader;
	int                 plyModelList;
        double              plyModelScale;
	int                 plyModelTexID;
	vector< vector<int> > modelFaces;  //needed for windows ???
        //vector<int> modelFaces;
	vector<ModelPoint>  modelVertex;
public: 
	PlyModel(string path,bool hasUVMap); // Constructor
	~PlyModel(); // Destructor 
	void draw();
	void drawQuads();
	void buildModelList(bool hasUVMap);	
};

PlyModel::PlyModel(string path,bool hasUVMap){
	modelReader = new PlyReader(path);
	plyModelScale = 1;
        
	//plyModelTexID = new_plyModelTexID;
        
        
	modelVertex = modelReader->getVertexList();
	modelFaces = modelReader->getFaceList();
	buildModelList(hasUVMap);
}

PlyModel::~PlyModel(){
	delete modelReader;
}

void PlyModel::draw(){     
    //Draw
    glPushMatrix();
	glTranslatef((float)0.0, (float)0.0, (float)0.0); 			//move around floor
	glRotatef(0.0f, 1.0f, 0.0f, 0.0f); 	//spin on the spot
	glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
	drawQuads();
	glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(0.0f, 1.0f, 0.0f, 0.0f); 	
	glTranslatef((float)-0.0, (float)-(0.0+1), (float)-0.0);
    glPopMatrix();
}

void PlyModel::drawQuads(){
	//glBindTexture(GL_TEXTURE_2D, plyModelTexID);		
	glCallList(plyModelList);
}
	


void PlyModel::buildModelList(bool hasUVMap){
	//static GLuint 
	plyModelList = glGenLists(1);
	glNewList(plyModelList, GL_COMPILE);
	for (int i = 0; i < modelFaces.size(); i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < modelFaces[i].size(); j++){
			double xcord = modelVertex[modelFaces[i][j]].x * plyModelScale;
			double ycord = modelVertex[modelFaces[i][j]].y * plyModelScale;
			double zcord = modelVertex[modelFaces[i][j]].z * plyModelScale;
			double ucord = modelVertex[modelFaces[i][j]].u;
			double vcord = modelVertex[modelFaces[i][j]].v;
			double nxcord = modelVertex[modelFaces[i][j]].nx;
			double nycord = modelVertex[modelFaces[i][j]].ny;
			double nzcord = modelVertex[modelFaces[i][j]].nz;
			if(hasUVMap)
			{
				//glTexCoord2d(ucord,vcord);
			}
			else
			{
				glTexCoord3d(xcord/8, ycord/4, zcord/4);
			}
			
			glVertex3d(xcord, ycord - (0.085 * plyModelScale), zcord);
			glNormal3d(nxcord,nycord,nzcord);
		}
		glEnd();
	}
	glEndList();
}


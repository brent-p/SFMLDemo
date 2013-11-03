#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

void readstr(FILE *f,char *string)
{
	do{
		fgets(string, 255, f);
	} while ((string[0] == '/') || (string[0] == '\n'));
	return;
}

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
	string filename; 
	string format; 
	int vertexCount; 
	int faceCount;
	vector<ModelPoint> vertex;
	vector< vector<int> > faceList; 
	
public: 
	PlyReader(string filename); // Constructor
	~PlyReader(){}; // Destructor 
	void parseFile();
	void parseHeader(string line);
	void parseVertex(string line, int i);
	void parseFace(string line, int i);
	vector< vector<int> > getFaceList();
	vector<ModelPoint> getVertexList();
};


PlyReader::PlyReader(string newfilename){
	filename = newfilename;
	vertexCount = 0; 
	faceCount = 0; 
	parseFile(); 
}

void PlyReader::parseFile(){
	
	//cout << "File parseing:"<< filename << endl;
	FILE *filein;
	char oneline[255];
	int tempnvertex;
	vector<int> tempfacevertex(5,0);                                        // File To Load World Data From this 
	//fopen_s(&filein,filename.c_str(), "r");				// This needed for windows
        filein = fopen(filename.c_str(),"r");                                  // This is needed for mac
	
	while (vertexCount==0){
		readstr(filein,oneline);
		sscanf(oneline, "element vertex %d\n", &vertexCount);
	};

	while (faceCount==0){
		readstr(filein,oneline);
		sscanf(oneline, "element face %d\n", &faceCount);
	};

	faceList.resize(faceCount);
	vertex.resize(vertexCount);
	
	//strcmp is handled by mac and windows differently GRRR, although to be honest I think the original code was just broken
        //while(strcmp(oneline,"end_header")==-1)
        
        
	while(strcmp(oneline,"end_header") < 0){
		readstr(filein,oneline);
	};
        //cout << "Afterend_header oneline before: "<< oneline << endl;
	readstr(filein,oneline);
        //cout << "Afterend_header oneline: "<< oneline << endl;
	//readstr(filein,oneline);
        //cout << "Afterend_header oneline again: "<< oneline << endl;
	

	//cout << "SystemOut: "<< vertexCount << endl;
	//cout << "SystemOut: "<< faceCount << endl;

	for (int i = 0; i < vertexCount; i++)
	{
		readstr(filein,oneline);		
		sscanf(oneline, "%f %f %f %f %f %f %f %f", &vertex[i].x, &vertex[i].y, &vertex[i].z, &vertex[i].nx, &vertex[i].ny,&vertex[i].nz, &vertex[i].u,&vertex[i].v);
		//cout << "vertexline: "<< i << " : " << " " <<vertex[i].x<< " " << vertex[i].y<< " " << vertex[i].z<< " " << vertex[i].u<< " " << vertex[i].v << endl;
	}
        
	for (int i = 0; i < faceCount; i++)
	{
		readstr(filein,oneline);	
                //cout << "faceline: "<< oneline << endl;
		sscanf(oneline, "%d %d %d %d %d", &tempnvertex, &tempfacevertex[0], &tempfacevertex[1], &tempfacevertex[2], &tempfacevertex[3]);
		//cout << "SystemOut: "<< i << " : " << " " <<tempnvertex<< " " << tempfacevertex[0] << " " << tempfacevertex[1]<< " " << tempfacevertex[2] << " " << tempfacevertex[3] << endl;
                //cout << "SystemOut: "<< tempnvertex << endl;
		faceList[i].resize(tempnvertex);
		for(int j=0; j<tempnvertex; j++){

			faceList[i][j] = tempfacevertex[j];
		}
		//cout << "SystemOut: "<< i << " : " << " " <<faceList[i].size() << " " << faceList[i][0] << " " << faceList[i][1]<< " " << faceList[i][2] << endl;
	}	
	fclose(filein);
	return;
}


vector< vector<int> > PlyReader::getFaceList(){
	return faceList;
}
vector<ModelPoint> PlyReader::getVertexList(){
	return vertex; 
}



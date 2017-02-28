#include <string.h>
#include <iostream>
#include <fstream>
#include "Plane.h"
#include "Box.h"
#include "Sphere.h"
#include "Cone.h"
#include "Vertex.h"

using namespace std; 

void printFile(vector<Vertex*> v, string file_name){

	ofstream file (file_name);
	if(file.is_open()){
		for (vector<Vertex*>::iterator it = v.begin() ; it != v.end(); ++it)
			file << (*it)->print() << endl;
		file.close();
	}
	else cout << "Unable to open file." << endl;
}

int main(int argc, char** argv){

	vector<Vertex*> v;

	if(!strcmp(argv[1],"plane") && argc == 4)
		v = createPlane(atof(argv[2]));

	else if(!strcmp(argv[1],"box") && argc == 7)
		v = createBox(atof(argv[2]),atof(argv[3]),atof(argv[4]),atoi(argv[5]));

	else if(!strcmp(argv[1],"sphere") && argc == 6)
		v = createSphere(atof(argv[2]),atof(argv[3]),atof(argv[4]));

	else if(!strcmp(argv[1],"cone") && argc == 7)
		v = createCone(atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]));	

	else cout << "Invalid input." << endl; 
	printFile(v,argv[argc-1]);

	return 0;
}
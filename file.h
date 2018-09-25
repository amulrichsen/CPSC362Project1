/*	File Class
This is a "folder" containing a file's artifacts
*/
#pragma once
#include <string>
#include "artifact.h"

using namespace std;

class File
{
public:
	string manifest; //manifest name .txt
	string fName; //file name
	string fExt; //file extension
	Artifact* artPtr; //pointer to the most recent artifact file.

	File(string fName, string fExt);
	Artifact* createArt(); //create artifact file and copy file info into it

};

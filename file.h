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
	File* next; //Pointer to the next FILE within the same folder.

	File(string fName, string fExt, File* next = NULL);
	Artifact* createArt(); //create artifact file and copy file info into it

};

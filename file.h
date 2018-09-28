/*	File Class
This is a "folder" containing a file's artifacts
*/
#pragma once
#include <string>
#include "artifact.h"
#include "gtime.h"


using namespace std;

class File
{
public:
	string manifest; //manifest name .txt
	string fName; //file name
	string fExt; //file extension
	string sPath; // full path to source file
	string tPath; //full path to repo file
	Artifact* artPtr; //pointer to the most recent artifact file.
	File* next; //Pointer to the next FILE within the same folder.

	File(string fName, string fExt, string sPath, string tPath, File* next = NULL);
	Artifact* createArt(); //create artifact file and copy file info into it

};
/*	File Class
	This class creates a "hidden" folder containing a file's artifacts

	Authors:
	Anette Ulrichsen
	amulrichsen@csu.fullerton.edu

	John Margis
	margisj@csu.fullerton.edu
*/
#pragma once

#include <string>
#include <experimental/filesystem>
#include <iostream>

#include "artifact.h"
#include "leaf.h"

using namespace std;

char getSlash(string path);

class File
{
public:
	Manifest* manifest; //manifest name .txt
	string fName; //file name
	string fExt; //file extension
	string sPath; // full path to source file
	string tPath; //full path to repo file
	class Artifact* artPtr; //pointer to the most recent artifact file.
	File* next; //Pointer to the next FILE within the same folder.

	File(string fName, string fExt, string sPath, string tPath, Manifest* manifest, File* next = NULL);
	Artifact* createArt(); //create artifact file and copy file info into it
};

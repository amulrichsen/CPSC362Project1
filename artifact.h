/*	Artifact Class
This is a a copy of a file with a checksum as it's name.
*/
#pragma once
#include <string>

#include "manifest.h"
#include "leaf.h"

#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

class Artifact
{
public:
	Artifact(string fname, string fExt, string sPath, string tPath, Manifest* manifest, Artifact* next = NULL);
	std::string getFileName();
	std::string getArtID();
	Artifact* next; //Pointer to previous artifact version
private:
	std::string name; //File name (without extension)
	std::string fExtension; //File extension
	string sPath; // Full source path to file
	string tPath; //Target path
	std::string checkSum; //Calculated checksum for file
	std::string createChecksum();
	Manifest* manifest;

};

//Required Prototypes:
void copyFile(std::string sourceName, std::string destName);
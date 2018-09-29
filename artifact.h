/*	Artifact Class
	This class creates a copy of the given file with a checksum as it's name

	Authors:
	Anette Ulrichsen
	amulrichsen@csu.fullerton.edu

	Hector Rodriguez
	hrod93@csu.fullerton.edu

	John Margis
	margisj@csu.fullerton.edu
*/
#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include "manifest.h"
#include "leaf.h"

using namespace std;

class Artifact
{
public:
	Artifact(string fname, string fExt, string sPath, string tPath, Manifest* manifest, Artifact* next = NULL);
	std::string getFileName(); //Returns the filename
	std::string getArtID(); //Returns the ArtifactID
	Artifact* next; //Pointer to previous artifact version
private:
	std::string name; //File name (without extension)
	std::string fExtension; //File extension
	string sPath; // Full source path to file
	string tPath; //Target path
	std::string checkSum; //Calculated checksum for file
	std::string createChecksum(); //Creates the checksum
	Manifest* manifest; //Pointer to the manifest

};

//Required Prototypes:
void copyFile(std::string sourceName, std::string destName);
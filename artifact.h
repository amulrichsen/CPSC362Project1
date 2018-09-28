/*	Artifact Class
This is a a copy of a file with a checksum as it's name.
*/
#pragma once
#include <string>
#include "gtime.h"

using namespace std;

class Artifact
{
public:
	Artifact(std::string fname, string fExt, string sPath, string tPath, Artifact* next = NULL);
	std::string getFileName();
	std::string Artifact::getArtID();
	Artifact* next; //Pointer to previous artifact version
private:
	std::string name; //File name (without extension)
	std::string fExtension; //File extension
	string sPath; // Full source path to file
	string tPath; //Target path
	std::string checkSum; //Calculated checksum for file
	std::string createChecksum();

};

//Required Prototypes:
void copyFile(std::string sourceName, std::string destName);
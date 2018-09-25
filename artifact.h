/*	Artifact Class
This is a a copy of a file with a checksum as it's name.
*/
#pragma once
#include <string>

class Artifact
{
public:
	Artifact(std::string fileName, Artifact* next);
	std::string getFileName();
	std::string Artifact::getArtID();
	Artifact* next; //Pointer to previous artifact version
private:
	std::string name; //File name (without extension)
	std::string fExtension; //File extension
	std::string checkSum; //Calculated checksum for file
	std::string createChecksum();

};

//Required Prototypes:
void copyFile(std::string sourceName, std::string destName);

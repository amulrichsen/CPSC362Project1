/*	Artifact Class
	This is a a copy of a file with a checksum as it's name.
*/
#pragma once
#include <string>

class Artifact
{
public: 
	Artifact(std::string fileName);
	std::string getFileName();
	std::string Artifact::getArtID();
private:
	std::string name;
	std::string fExtension;
	std::string checkSum;

	std::string createChecksum();

};

void copyFile(std::string sourceName, std::string destName);
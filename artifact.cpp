#include "artifact.h"
#include "extra.h"
#include <fstream>
#include <iostream>

using namespace std;

/*	Constructor
1. Gets file extension
2. Calculates checksum and stores it
3. Creates physical artifact file and renames it
*/
Artifact::Artifact(std::string fname, string fExt, string sPath, string tPath, Artifact* next)
{
	this->name = fname;
	this->fExtension = fExt;
	this->sPath = sPath;
	this->tPath = tPath;
	this->checkSum = this->createChecksum();
	copyFile(this->sPath, this->checkSum);
	copyFile(this->sPath, this->tPath + '\\' + this->name + this->fExtension);
	this->next = next;
}


/*	Params: None
Function creates a checksum by multiplying the file's contents by
1,3,7,9,17 then appending L-<FILE LENGTH> and the file's extension.
Returns: String that will become ArtID.
*/
std::string Artifact::createChecksum()
{
	std::ifstream file(this->sPath);
	char c;
	int weights[5] = { 1,3,7,11,17 };
	int counter = 0;
	int checkSum = 0;
	int fileSize = 0;
	while (file.get(c))
	{
		if (counter > 4)
			counter = 0;
		checkSum += ((int)c * weights[counter]);
		counter++;
		fileSize++;
	}
	file.close();
	//The file name is the target path + \\ or / + checkSum string + -L + fileSize + extension
	return this->tPath + getSlash(tPath) + to_string(checkSum) + "-L" + std::to_string(fileSize) + this->fExtension;
}

/*	Params: None
Function returns the Artifact's original file name
Returns: File name string
*/
std::string Artifact::getFileName()
{
	return this->name + this->fExtension;
}

/*	Params: None
Function returns the Artifact's completed checksum name
Returns: ArtID string
*/
std::string Artifact::getArtID()
{
	return this->checkSum;
}

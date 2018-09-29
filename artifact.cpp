/*	Artifact Functions
	Contains the functions for the Artifact class

	Authors:
	Anette Ulrichsen
	amulrichsen@csu.fullerton.edu

	Hector Rodriguez
	hrod93@csu.fullerton.edu

	John Margis
	margisj@csu.fullerton.edu
*/
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include "artifact.h"

using namespace std;

/*	Constructor
1. Gets file extension
2. Calculates checksum and stores it
3. Creates physical artifact file and renames it
*/
Artifact::Artifact(string fname, string fExt, string sPath, string tPath, Manifest* manifest, Artifact* next)
{
	this->name = fname;
	this->fExtension = fExt;
	this->sPath = sPath;
	this->tPath = tPath;
	this->checkSum = this->createChecksum();
	this->manifest = manifest;

	copyFile(this->sPath, this->checkSum);
	this->manifest->write(this->checkSum, "Artifact Created\t");
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
	double checkSum = 0;
	int fileSize = 0;
	double wrap = (pow(2, 31) - 1); // Wrap around if above this
	//Iterate through characters within the file
	while (file.get(c))
	{
		//Iterate through the weights
		if (counter > 4)
			counter = 0;
		checkSum = fmod(checkSum + (int)c * weights[counter], wrap);
		counter++;
		fileSize++;
	}
	file.close();
	//The file name is the target path + \\ or / + checkSum string + -L + fileSize + extension
	return this->tPath + getSlash(tPath) + to_string((int)checkSum) + "-L" + std::to_string(fileSize) + this->fExtension;
}
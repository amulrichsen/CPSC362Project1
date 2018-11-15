/*	Repo Functions
	Contains functions for the Repo Class

	Authors:
	Anette Ulrichsen
	amulrichsen@csu.fullerton.edu

	Hector Rodriguez
	hrod93@csu.fullerton.edu

	John Margis
	margisj@csu.fullerton.edu
*/
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "repo.h"
using namespace std;

Repo::Repo(string sPath, string tPath) {


}

void Repo::create(string sPath, string tPath) {
	//creates a repo using a given source tree
	this->sPath = sPath;
	//Append root folder name to the target path
	this->tPath = tPath + getSlash(this->sPath) + experimental::filesystem::path(sPath).stem().string();
	//Create Manifest
	this->manifest = new Manifest(tPath);
	//Create initial leaf for root folder
	this->head = new Leaf(this->sPath, this->tPath, this->manifest);	
}
void Repo::checkIn(string sPath, string tPath) {
	//updates an existing project tree
}
void Repo::checkOut(string sPath, string tPath, string manifest) {
	//creates a repo using a given manifest
	//Open the manifest to parse
	ifstream file(sPath + '/' + manifest);
	string line;
	int sPathLen = sPath.length();
	//Parse line by line
	while (getline(file, line))
	{
		if (line[26] == 'F')
		{
			// Extract the folder name from the manifest line
			string fName = line.substr(57, sPathLen - 1);
			fName.erase(fName.begin(), fName.end() - sPathLen);
			// Create a directory at the tPath + folder name
			experimental::filesystem::create_directory(this->tPath+'/'+fName);
			
		}

		else if (line[26] == 'C')
		{
			// Extract the file name from the manifest line
			string fName = line.substr(57, sPathLen - 1);
			fName.erase(fName.begin(), fName.end() - sPathLen);

		}

	}
}




/*	Repo Functions
Contains functions for the Repo Class

Authors:
Anette Ulrichsen
amulrichsen@csu.fullerton.edu

John Margis
margisj@csu.fullerton.edu

*/
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "repo.h"
using namespace std;

// Creates a repo using a source tree
void Repo::create(string sPath, string tPath) {
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

// Creates a copy of a repo using it's manifest
void Repo::checkOut(string sPath, string tPath, string manifest) {
	bool cont = true;
	
	//creates a repo using a given manifest
	this->sPath = sPath;
	this->tPath = tPath + getSlash(this->sPath) + experimental::filesystem::path(sPath).stem().string();
	this->manifest = new Manifest(tPath);
	this->manifest->write(sPath + ",\t" + tPath + ",\t" + manifest, "CHECK-OUT ARGS:\t");

	// Create root directory
	experimental::filesystem::create_directory(this->tPath);

	// Open the manifest to parse
	ifstream file(this->sPath + '/' + manifest);
	string line;
	//Parse line by line
	while ((getline(file, line)) && cont)
	{
		if (line[0] == 'L')
		{
			cont = false;
		}
		
		else if (line[26] == 'F')
		{
			// Extract the folder name from the manifest line
			string fName = line.substr(57, line.length() - 1);
			fName.erase(fName.begin(), fName.begin() + this->sPath.length());
			// Create a directory at the tPath + folder name
			experimental::filesystem::create_directory(this->tPath + fName);
			this->manifest->write(experimental::filesystem::path(this->tPath + fName).string(), "CHECKOUT: Folder\t");


		}

		else if (line[26] == 'C')
		{
			// Extract the file name from the manifest line
			string fPath = line.substr(57, line.length() - 1);
			string fName = fPath;
			fName.erase(fName.begin(), fName.begin() + this->sPath.length());
			// Get the next line that contains the file's artifact
			getline(file, line);
			string aPath = line.substr(57, line.length() - 1);
			// Copy the artifact and rename it to its original name
			copyFile(aPath, this->tPath + '/' + fName);
			this->manifest->write(experimental::filesystem::path(this->tPath + fName).string(), "CHECKOUT: File\t");


		}


	}
}




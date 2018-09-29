/*	File Functions
	This contains the functions for the File Class

	Authors:
	Anette Ulrichsen
	amulrichsen@csu.fullerton.edu

	Hector Rodriguez
	hrod93@csu.fullerton.edu

	John Margis
	margisj@csu.fullerton.edu
*/
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include "file.h"


using namespace std;

/* Constructor
Params: File Name, File Extnesion
Sets the class's file name & extnesion
Also creates an initial artifact and set's the pointer head to it
*/
File::File(string fName, string fExt, string sPath, string tPath, Manifest* manifest, File* next) {
	this->fName = fName;
	this->fExt = fExt;
	this->sPath = sPath;
	this->tPath = tPath;
	this->next = next;
	this->manifest = manifest;
	//Create a physical "hidden" directory with the file's name
	experimental::filesystem::create_directory(this->tPath);
	this->manifest->write(this->tPath, "Created \"Hidden\" File Folder\t");
	//Create the artifact
	//Artifact Class will handle adding backslash itself.
	this->artPtr = this->createArt();
}

/*	Params: None
	Creates the Artifact object and adds it to our File Object's linked list
*/
Artifact* File::createArt()
{
	if (this->artPtr)
		return new Artifact(this->fName, this->fExt, this->sPath, this->tPath, this->manifest, this->artPtr);
	else
		return new Artifact(this->fName, this->fExt, this->sPath, this->tPath, this->manifest);
}
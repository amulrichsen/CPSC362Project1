#include "file.h"
#include <filesystem>
#include <iostream>
using namespace std;
/* Constructor
Params: File Name, File Extnesion
Sets the class's file name & extnesion
Also creates an initial artifact and set's the pointer head to it
*/
File::File(string fName, string fExt, string sPath, string tPath, File* next) {
	this->fName = fName;
	this->fExt = fExt;
	this->sPath = sPath;
	this->tPath = tPath;
	this->next = next;
	//Create a physical "hidden" directory with the file's name
	experimental::filesystem::create_directory(this->tPath);
	cout << "DEBUG: MADE FILE DIRECTORY: " << this->tPath << endl;
	//Create the artifact
	//Artifact Class will handle adding backslash itself.
	this->artPtr = this->createArt();
}

Artifact* File::createArt()
{
	if (this->artPtr)
		return new Artifact(this->fName, this->fExt, this->sPath, this->tPath, this->artPtr);
	else
		return new Artifact(this->fName, this->fExt, this->sPath, this->tPath);
}

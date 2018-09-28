#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <filesystem>
#include <iostream>

#include "file.h"
#include "gtime.h"
#include "leaf.h"

using namespace std;

/* Constructor
Params: File Name, File Extnesion
Sets the class's file name & extnesion
Also creates an initial artifact and set's the pointer head to it
*/
File::File(string manPath, string fName, string fExt, string sPath, string tPath, File* next) {
	this->fName = fName;
	this->fExt = fExt;
	this->sPath = sPath;
	this->tPath = tPath;
	this->next = next;
	this->manifest = manPath;
	//Create a physical "hidden" directory with the file's name
	experimental::filesystem::create_directory(this->tPath);
	string msg = "Created \"Hidden\" File Folder\t";
	writeToManifest(manPath, tPath, msg);
	cout << "DEBUG: MADE FILE DIRECTORY: " << this->tPath << endl;
	//Create the artifact
	//Artifact Class will handle adding backslash itself.
	this->artPtr = this->createArt();
}

Artifact* File::createArt()
{
	if (this->artPtr)
		return new Artifact(manifest, this->fName, this->fExt, this->sPath, this->tPath, this->artPtr);
	else
		return new Artifact(manifest, this->fName, this->fExt, this->sPath, this->tPath);
}
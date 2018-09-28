#include "file.h"
/* Constructor
Params: File Name, File Extnesion
Sets the class's file name & extnesion
Also creates an initial artifact and set's the pointer head to it
*/
File::File(string fName, string fExt, string path, File* next) {
	this->fName = fName;
	this->fExt = fExt;
	this->path = path;
	this->next = next;
	this->artPtr = this->createArt();
}

Artifact* File::createArt()
{
	if (this->artPtr)
		return new Artifact(this->fName, this->fExt, this->path, this->artPtr);
	else
		return new Artifact(this->fName, this->fExt, this->path);
}

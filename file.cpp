#include "file.h"

/* Constructor
Params: File Name, File Extnesion
Sets the class's file name & extnesion
Also creates an initial artifact and set's the pointer head to it
*/
File::File(string fName, string fExt) {
	this->fName = fName;
	this->fExt = fExt;
	this->artPtr = this->createArt();
}

Artifact* File::createArt()
{
	if (this->artPtr)
		return new Artifact(this->fName + this->fExt);
	else
		return new Artifact(this->fName + this->fExt);
}

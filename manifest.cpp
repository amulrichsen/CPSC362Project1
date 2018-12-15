/*	Manifest Functions
Contains the functions for the Manifest Class

Authors:
Anette Ulrichsen
amulrichsen@csu.fullerton.edu

John Margis
margisj@csu.fullerton.edu
*/
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>

#include "manifest.h"

/*	Constructor
1. Creates an empty manifest file inside the root */
Manifest::Manifest(string path, bool checkSum)
{
	int randVar;

	srand(time(NULL));
	randVar = rand() % 9000 + 1000;

	//creates manifest inside of root repo folder
	if (checkSum)
		this->path = path + getSlash(path) + to_string(randVar) + "-manifest.txt";
	else
		this->path = path + getSlash(path) + "manifest.txt";
	copyFile(this->path, this->path);
	this->write(this->path, "Manifest Created\t");
}

/*	Params: Target Path (file that's being modified by command), Message
Appends the make file with the Time, Message, and Target File/Folder
*/
void Manifest::write(string tPath, string msg)
{
	ofstream dst;
	dst.open(this->path, ofstream::app);
	getTime();
	dst << this->tStamp << " - " << left << setw(30) << msg << "\t" << tPath << "\n";
	dst.close();
}

/*	Params: Buffer
Gets the current date/time and formats it
Returns: Formatted time buffer
*/
char* Manifest::getDT(char *buff)
{
	time_t t = time(0);
	strftime(buff, 32, "%a %m/%d/%Y %H:%M:%S", localtime(&t));
	return buff;
}

/*	Params: None
Sets the tStamp variable to the formatted Time
*/
void Manifest::getTime()
{
	char buff[32];
	this->tStamp = getDT(buff);
}


string Manifest::getManifestPath()
{
	return this->path;
}

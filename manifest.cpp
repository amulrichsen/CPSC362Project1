#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include "manifest.h"

Manifest::Manifest(string path)
{
	//creates manifest inside of root repo folder
	this->path = path + getSlash(path) + "manifest.txt";
	copyFile(this->path, this->path);
	this->write(this->path, "Manifest Created\t");
}

void Manifest::write(string tPath, string msg)
{
	ofstream dst;
	dst.open(this->path, ofstream::app);
	getTime();
	dst << this->tStamp << " - " << left << setw(30) << msg << "\t" << tPath << "\n";
	dst.close();

}

char* Manifest::getDT(char *buff)
{
	time_t t = time(0);
	strftime(buff, 32, "%a %m/%d/%Y %H:%M:%S", localtime(&t));
	return buff;
}

void Manifest::getTime()
{
	char buff[32];
	this->tStamp = getDT(buff);
}
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
	string tStamp = "";
	ofstream dst(this->path, ofstream::out | ofstream::app);

	getTime();

	ifstream store("timetrans.txt");
	getline(store, tStamp);
	dst << tStamp << " - " << left << setw(30) << msg << "\t" << tPath << endl;
	store.close();

	ofstream delContent;
	delContent.open("timetrans.txt", ofstream::out | ofstream::trunc);
	delContent.close();

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
	fstream file;
	file.open("timetrans.txt", fstream::out | fstream::app);

	file << getDT(buff);
	file.close();
}
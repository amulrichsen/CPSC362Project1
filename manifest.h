#pragma once

#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
class Manifest
{
private:
	string path;
	void getTime();
	static char *getDT(char *buff);
public:
	Manifest(string path);
	void write(string tPath, string msg);
};

void copyFile(string sourceName, string destName);
char getSlash(string path);
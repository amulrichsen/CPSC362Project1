/*	Manifest Class
	Creates a manifest file that logs commands for the repo

	Authors:
	Anette Ulrichsen
	amulrichsen@csu.fullerton.edu

	Hector Rodriguez
	hrod93@csu.fullerton.edu

	John Margis
	margisj@csu.fullerton.edu
*/
#pragma once

#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
class Manifest
{
private:
	string path; //Path to the manifest file
	string tStamp; //Formatted Time
	void getTime(); //Sets tStamp
	static char *getDT(char *buff); //Gets and formats time, gives to getTime()
public:
	Manifest(string path);
	void write(string tPath, string msg); //Writes to the manifest file
};

//Required Prototypes
void copyFile(string sourceName, string destName);
char getSlash(string path);
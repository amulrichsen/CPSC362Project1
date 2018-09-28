#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <ctime>

using namespace std;

#include "artifact.h"
#include "file.h"
#include "leaf.h"
#include "repo.h"
#include "gtime.h"


void copyFile(string sourceName, string destName);
char getSlash(string path);


int main()
{	

	string sFolder = "";
	string tFolder = "";

	cout << "Enter the complete path of the source folder: ";
	cin >> sFolder;
	cout << "Enter the complete path of the target folder: ";
	cin >> tFolder;

	Repo r1(sFolder, tFolder);

	system("pause");
	return 0;
};



/*	Params: Source file's path+name, Destination file's path + name
Function copies a file from the source to the destination
Returns: Nothing
*/
void copyFile(string sourceName, string destName)
{
	ifstream src(sourceName, ios::binary);
	ofstream dst(destName, ios::binary);

	dst << src.rdbuf();
}

/*	Function to check if we're on widows/Linux by checking if we use / or \
Note: Should probably find a better way to do this, won't work if we use a relative file path
*/
char getSlash(string path)
{
	if (path.find('\\') != string::npos)
		return '\\';
	else
		return '/';
}




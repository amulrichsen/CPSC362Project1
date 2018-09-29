/*	Main Functions
	Contains the Main and global scope functions
	This is the head of the program.

	Authors:
	Anette Ulrichsen
	amulrichsen@csu.fullerton.edu

	Hector Rodriguez
	hrod93@csu.fullerton.edu

	John Margis
	margisj@csu.fullerton.edu
*/
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <string>

#include "artifact.h"
#include "file.h"
#include "leaf.h"
#include "repo.h"

using namespace std;


//Prototypes
void copyFile(string sourceName, string destName);
char getSlash(string path);

/*	Main Function
	Asks the user for the project tree folder and target folder
	Then creates the repo
*/
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

/*	Function to check if we're using a Windows absolute path by checking if we use / or \
*/
char getSlash(string path)
{
	if (path.find('\\') != string::npos)
		return '\\';
	else
		return '/';
}




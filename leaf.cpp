#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <iomanip>

#include "leaf.h"
#include "gtime.h"

using namespace std;

string genManifest(string tPath, string sPath);
void writeToManifest(string manPath, string tPath, string msg);

Leaf::Leaf(string manPath, string sPath, string tPath, Leaf* next) {
	this->sPath = sPath;
	this->tPath = tPath;
	this->files = NULL;
	this->leafNext = next;
	//Make a physical folder
	experimental::filesystem::create_directory(this->tPath);
	//Now the physical folder is created, generate manifest inside
	string msg;
	if (manPath == "")
	{
		
		manPath = genManifest(tPath, sPath);
		
		msg = "Manifest Created\t";
		writeToManifest(manPath, tPath, msg);
	}
	else
	{
		msg = "Folder Created\t";
		writeToManifest(manPath, tPath, msg);
	}

	//DEBUG
	cout << "DEBUG: MADE LEAF FOLDER: " << this->tPath << endl;
	//Search leaf's path for subfolders/files
	for (auto & p : experimental::filesystem::directory_iterator(sPath))
	{
		string path = p.path().string(); // Path
		string name = p.path().stem().string(); //File/Folder name
												//We go down to the directory we just made by appending a slash with getSlash() and
												//adding the source folder's name
												//ex. FOLDER\NEWFOLDER
		string tarPath = this->tPath + getSlash(this->tPath) + name;
		// If iterator is a file -> create file
		if (path.find('.') != string::npos)
		{
			//Find file's extension
			string ext = p.path().extension().string();
			//If this is the first file, there is no need to link it to the previous
			if (this->files == NULL)
				this->files = new File(manPath, name, ext, path, tarPath + ext);
			else
				this->files = new File(manPath, name, ext, path, tarPath + ext, this->files);
		}
		else // Iterator is a folder
		{
			//MAKE NEW LEAF() WITH SPLIT FOLDERNAME WITH LEAF(next=previous this->leafNext)
			//If this is the first folder, there is no need to link it to the previous
			if (this->leafNext == NULL)
				this->leafNext = new Leaf(manPath, path, tarPath);
			else
				this->leafNext = new Leaf(manPath, path, tarPath, this->leafNext);
			//SET this->leafNext TO NEW LEAF()
		}
	}

}


string genManifest(string tPath, string sPath)
{
	//creates manifest inside of root repo folder
	string path = "";
	path = tPath + '\\' + "manifest.txt";

	copyFile(path, path);

	return path;
}

void writeToManifest(string manPath, string tPath, string msg)
{
	string tStamp = "";
	ofstream dst(manPath, ios::out | ofstream::app);

	getTime();

	ifstream store("timetrans.txt");
	getline(store, tStamp);
	dst << tStamp << " - " << left << setw(30) <<msg << "\t" << tPath << endl;
	store.close();

	ofstream delContent;
	delContent.open("timetrans.txt", ofstream::out | ofstream::trunc);
	delContent.close();

}


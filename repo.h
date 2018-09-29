/*	Repo Class
	Creates a repository using a given source tree path and target folder path
	Replicates Files and Folders

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
#include <iostream>
#include <experimental/filesystem>

#include "leaf.h"
#include "manifest.h"
using namespace std;

class Repo
{
public:
	string sPath; //source path
	string tPath; //target path
	string manPath = ""; //manifest path
	Leaf *head; //Root folder
	Manifest* manifest; //Manifest File

public:
	Repo(string sPath, string tPath);
	
};

//Required Prototypes
char getSlash(string path);

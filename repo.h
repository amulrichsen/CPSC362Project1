/*	Repo Class
Creates a repository using a given source tree path and target folder path
Replicates Files and Folders

Authors:
Anette Ulrichsen
amulrichsen@csu.fullerton.edu

John Margis
margisj@csu.fullerton.edu
*/
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
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
	void create(string sPath, string tPath); //creates a repo using a given source tree
	string checkIn(string sPath, string tPath); //updates an existing project tree
	void checkOut(string sPath, string tPath, string manifest); //creates a repo using a given manifest
	void merge(string rPath, string tManifest, string rManifest, string tPath); //merges new changes from a repo into a project tree
	void checkInLog(string ptPath, string mPath); //creates a textfile logging the manifests created for each check in from a project tree
	void dotFile(string rPath, string mPath, string pPath, string act);
	string ancestor(string fName, string checksum, string repoPath, string mPath);


};

//Required Prototypes
char getSlash(string path);
string searchLabels(string sPath, string oldLabel);
bool checkExists(string rManifest, string tManifest);


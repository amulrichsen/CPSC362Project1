#pragma once
#include <string>

#include "leaf.h"
#include "gtime.h"

using namespace std;

string genManifest(string tPath, string sPath);
void writeToManifest(string manPath, string tPath, string msg);
char getSlash(string path);

class Repo
{
public:
	string sPath; //source path
	string tPath; //target path
	string manPath = ""; //manifest path
	Leaf *head;

public:
	Repo(string sPath, string tPath);
	
};

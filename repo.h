#pragma once
#include <string>
#include <iostream>
#include <experimental/filesystem>

#include "leaf.h"
#include "manifest.h"

using namespace std;

char getSlash(string path);

class Repo
{
public:
	string sPath; //source path
	string tPath; //target path
	string manPath = ""; //manifest path
	Leaf *head;
	Manifest* manifest;

public:
	Repo(string sPath, string tPath);
	
};

#pragma once
#include <string>
#include "leaf.h"
//#include "artifact.h"

using namespace std;

class Repo
{
public:
	string sPath; //source path
	string tPath; //target path
	string manifest; //manifest name .txt
	Leaf *head;

public:
	Repo(string sPath, string tPath);
	void assignRepoName(string name);
	void assignManifest(string name);

	//search tree
	//print
	//copy


};


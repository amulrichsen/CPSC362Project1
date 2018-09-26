#pragma once
#include <string>
#include "leaf.h"
//#include "artifact.h"

using namespace std;

class Repo
{
public:
	string rName; //repo name
	string manifest; //manifest name .txt
	Leaf *head;

public:
	Repo(string name);
	void assignRepoName(string name);
	void assignManifest(string name);

	//search tree
	//print
	//copy


};


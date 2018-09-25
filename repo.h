#pragma once
#include <string>
//#include "artifact.h"

using namespace std;

class Repo
{
public:
	string rName; //repo name
	string manifest; //manifest name .txt
	Repo *head;

public:
	Repo();
	void assignRepoName(string name);
	void assignManifest(string name);

	//search tree
	//print
	//copy


};


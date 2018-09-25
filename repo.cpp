#include "repo.h"
#include <iostream>

using namespace std;

Repo::Repo() {
	head = NULL;
}
void Repo::assignRepoName(string name)
{
	this->rName = name;
}

void Repo::assignManifest(string name)
{
	this->manifest = name;
	this->manifest += "-manifest.txt";
	cout << "Name of Manifest Text File: " << this->manifest << endl;
}

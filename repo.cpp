#include "repo.h"
#include "extra.h"
#include <iostream>
#include <filesystem>

using namespace std;

Repo::Repo(string sPath, string tPath) {

	this->sPath = sPath;
	//Append root folder name to the target path
	this->tPath = tPath + getSlash(this->sPath) + experimental::filesystem::path(sPath).stem().string();
	//Create initial leaf for root folder
	this->head = new Leaf(this->sPath, this->tPath);

}
void Repo::assignRepoName(string name)
{
	//this->rName = name;
}

void Repo::assignManifest(string name)
{
	this->manifest = name;
	this->manifest += "-manifest.txt";
	cout << "Name of Manifest Text File: " << this->manifest << endl;
}

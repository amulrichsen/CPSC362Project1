#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include "repo.h"


using namespace std;

Repo::Repo(string sPath, string tPath) {

	this->sPath = sPath;
	//Append root folder name to the target path
	this->tPath = tPath + getSlash(this->sPath) + experimental::filesystem::path(sPath).stem().string();
	//Create Manifest
	this->manifest = new Manifest(tPath);
	//Create initial leaf for root folder
	this->head = new Leaf(this->sPath, this->tPath, this->manifest);
}




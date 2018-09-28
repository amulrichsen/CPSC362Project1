#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <experimental/filesystem>

#include "gtime.h"
#include "repo.h"


using namespace std;

Repo::Repo(string sPath, string tPath) {

	this->sPath = sPath;
	//Append root folder name to the target path
	this->tPath = tPath + getSlash(this->sPath) + experimental::filesystem::path(sPath).stem().string();
	//Create initial leaf for root folder
	this->head = new Leaf(manPath, this->sPath, this->tPath);
}




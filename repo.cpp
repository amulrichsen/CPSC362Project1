#include "repo.h"
#include "extra.h"
#include <iostream>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <experimental/filesystem>

#include "gtime.h"

using namespace std;

Repo::Repo(string sPath, string tPath) {

	this->sPath = sPath;
	//Append root folder name to the target path
	this->tPath = tPath + getSlash(this->sPath) + experimental::filesystem::path(sPath).stem().string();
	//Create initial leaf for root folder
	this->head = new Leaf(this->sPath, this->tPath);
	createManifest(tPath);

}

//generates an empty manifest file inside the root folder
void Repo::createManifest(string tPath)
{
	experimental::filesystem::path p = experimental::filesystem::path(sPath);
	string fname = tPath + '\\' + p.stem().string() + '\\' + p.stem().string() + "-manifest.txt";

	copyFile(fname, fname);

	string msg = "test msg";
	ofstream dst(fname, ios::binary);

	//puts(msg);
	dst << msg;
	//cout << getTime();

}

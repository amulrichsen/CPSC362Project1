#include "repo.h"
#include "extra.h"
#include <iostream>
#include <fstream>
#include <experimental/filesystem>

using namespace std;

Repo::Repo(string sPath, string tPath) {

	this->sPath = sPath;
	//Append root folder name to the target path
	this->tPath = tPath + getSlash(this->sPath) + experimental::filesystem::path(sPath).stem().string();
	//Create initial leaf for root folder
	this->head = new Leaf(this->sPath, this->tPath);
	createManifest(tPath);

}

void Repo::createManifest(string tPath)
{
	experimental::filesystem::path p = experimental::filesystem::path(sPath);
	string fname = tPath + '\\' + p.stem().string() + '\\' + p.stem().string() + "-manifest.txt";
	cout << "manifest path: " << fname << endl;

	ifstream src(fname, ios::binary);
	ofstream dst(fname, ios::binary);

	dst << src.rdbuf();

}

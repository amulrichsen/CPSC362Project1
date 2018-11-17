/*	Repo Functions
	Contains functions for the Repo Class

	Authors:
	Anette Ulrichsen
	amulrichsen@csu.fullerton.edu

	John Margis
	margisj@csu.fullerton.edu
*/
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "repo.h"
using namespace std;

Repo::Repo(string sPath, string tPath) {


}

void Repo::create(string sPath, string tPath) {
	//creates a repo using a given source tree
	this->sPath = sPath;
	//Append root folder name to the target path
	this->tPath = tPath + getSlash(this->sPath) + experimental::filesystem::path(sPath).stem().string();
	//Create Manifest
	this->manifest = new Manifest(tPath);
	//Create initial leaf for root folder
	this->head = new Leaf(this->sPath, this->tPath, this->manifest);	
}
void Repo::checkIn(string sPath, string tPath) {
	//updates an existing project tree
}
void Repo::checkOut(string sPath, string tPath, string manifest) {
	//creates a repo using a given manifest
}




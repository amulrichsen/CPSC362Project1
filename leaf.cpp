#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "leaf.h"
#include "extra.h"
#include "gtime.h"

#include <iostream>


using namespace std;

Leaf::Leaf(string sPath, string tPath, Leaf* next) {
	this->sPath = sPath;
	this->tPath = tPath;
	this->files = NULL;
	this->leafNext = next;
	//Make a physical folder
	experimental::filesystem::create_directory(this->tPath);
	//DEBUG
	cout << "DEBUG: MADE LEAF FOLDER: " << this->tPath << endl;
	//Search leaf's path for subfolders/files
	for (auto & p : experimental::filesystem::directory_iterator(sPath))
	{
		string path = p.path().string(); // Path
		string name = p.path().stem().string(); //File/Folder name
												//We go down to the directory we just made by appending a slash with getSlash() and
												//adding the source folder's name
												//ex. FOLDER\NEWFOLDER
		string tarPath = this->tPath + getSlash(this->tPath) + name;
		// If iterator is a file -> create file
		if (path.find('.') != string::npos)
		{
			//Find file's extension
			string ext = p.path().extension().string();
			//If this is the first file, there is no need to link it to the previous
			if (this->files == NULL)
				this->files = new File(name, ext, path, tarPath + ext);
			else
				this->files = new File(name, ext, path, tarPath + ext, this->files);
		}
		else // Iterator is a folder
		{
			//MAKE NEW LEAF() WITH SPLIT FOLDERNAME WITH LEAF(next=previous this->leafNext)
			//If this is the first folder, there is no need to link it to the previous
			if (this->leafNext == NULL)
				this->leafNext = new Leaf(path, tarPath);
			else
				this->leafNext = new Leaf(path, tarPath, this->leafNext);
			//SET this->leafNext TO NEW LEAF()
		}
	}

}
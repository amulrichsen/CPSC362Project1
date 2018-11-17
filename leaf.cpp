/*	Leaf Functions
	This contains the functions for the Leaf class

	Authors:
	Anette Ulrichsen
	amulrichsen@csu.fullerton.edu

	John Margis
	margisj@csu.fullerton.edu
*/
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include "leaf.h"

using namespace std;

/*	Constructor
	1. Makes a physical folder
	2. Searches through the source folder to find others
	3. Makes a new leaf/file if it finds files/folders
*/
Leaf::Leaf(string sPath, string tPath, Manifest* manifest, Leaf* next) {
	this->sPath = sPath;
	this->tPath = tPath;
	this->files = NULL;
	this->leafNext = next;
	this->manifest = manifest;
	//Make a physical folder
	experimental::filesystem::create_directory(this->tPath);
	//Now the physical folder is created, generate manifest inside
	this->manifest->write(this->tPath, "Folder Created\t");
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
				this->files = new File(name, ext, path, tarPath + ext, this->manifest);
			else
				this->files = new File(name, ext, path, tarPath + ext, this->manifest, this->files);
		}
		else // Iterator is a folder
		{
			//MAKE NEW LEAF() WITH SPLIT FOLDERNAME WITH LEAF(next=previous this->leafNext)
			//If this is the first folder, there is no need to link it to the previous
			if (this->leafNext == NULL)
				this->leafNext = new Leaf(path, tarPath, this->manifest);
			else
				this->leafNext = new Leaf(path, tarPath, this->manifest, this->leafNext);
			//SET this->leafNext TO NEW LEAF()
		}
	}

}




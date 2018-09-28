#include "leaf.h"
#include "extra.h"
#include <iostream>


using namespace std;

Leaf::Leaf(string lname, string path, Leaf* next) {
	this->lName = lname;
	this->path = path;
	//this->lExt = lext;
	this->files = NULL;
	this->leafNext = next;
	//isSubFolder = false;
	//isFileFolder = false;

	//Search leaf's path for subfolders/files
	//string path = lname;
	for (auto & p : experimental::filesystem::directory_iterator(path))
	{
		// If iterator is a file -> create file
		if (p.path().string().find('.') != string::npos)
		{
			cout << "FILE:" << p.path().filename().string() << endl;

			//NEED FUNCTION TO SPLIT PATH FROM FILE NAME
			//MAKE NEW FILE() WITH SPLIT FILENAME/EXT WITH FILE(next = previous this->files)
			if (this->files == NULL)
				this->files = new File(p.path().stem().string(), p.path().extension().string(), p.path().string());
			else
				this->files = new File(p.path().stem().string(), p.path().extension().string(), p.path().string(),  this->files);
			//SET this->files TO NEW FILE()
		}
		else // Iterator is a folder
		{
			cout << "FOLDER:" << p.path().filename().string() << endl;
			//NEED FUNCTION TO SPLIT PATH FROM FOLDER NAME
			//MAKE NEW LEAF() WITH SPLIT FOLDERNAME WITH LEAF(next=previous this->leafNext)
			if (this->leafNext == NULL)
				this->leafNext = new Leaf(p.path().stem().string(), p.path().string());
			else
				this->leafNext = new Leaf(p.path().stem().string(), p.path().string(), this->leafNext);
			//SET this->leafNext TO NEW LEAF()
		}
	}

}



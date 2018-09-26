#include "leaf.h"
#include <iostream>


using namespace std;

Leaf::Leaf(string lname, Leaf* next) {
	this->lName = lname;
	//this->lExt = lext;
	this->files = NULL;
	this->leafNext = next;
	//isSubFolder = false;
	//isFileFolder = false;

	//Search leaf's path for subfolders/files
	string path = lname;
	for (auto & p : experimental::filesystem::directory_iterator(path))
	{
		// If iterator is a file -> create file
		if (p.path().string().find('.') != string::npos)
		{
			cout << "FILE:" << p.path().string() << endl;

			//NEED FUNCTION TO SPLIT PATH FROM FILE NAME
			//MAKE NEW FILE() WITH SPLIT FILENAME/EXT WITH FILE(next = previous this->files)
			//SET this->files TO NEW FILE()
		}
		else // Iterator is a folder
		{
			cout << "FOLDER:" << p.path().string() << endl;
			//NEED FUNCTION TO SPLIT PATH FROM FOLDER NAME
			//MAKE NEW LEAF() WITH SPLIT FOLDERNAME WITH LEAF(next=previous this->leafNext)
			//SET this->leafNext TO NEW LEAF()
		}
	}

}



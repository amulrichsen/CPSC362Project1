#include<iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class File
{
private:
	string manifest; //manifest name .txt
	string fName; //file name
	string fExt; //file extension
	string artName; //artifact name --has same file extension
	File *next; //if a leaf has multiple files, this will point to the next file attached to leaf

public:
	File() {
		fName = "";
		fExt = "";
		artName = "";
		next = NULL;
	}
	//create artifact file and copy file info into it
	//create checksum and assign to artName with file extension


};

class Leaf
{
private:
	string manifest; //manifest name .txt
	string lName; //leaf name
	string lExt; //leaf extension -- not necessary if subfolder

	Leaf *leafNext; //points to next leaf if it is a subfolder
	File *files; //leaf file linked list -- add files inside of leaf folder

	bool isSubFolder; //tells us if it is a subfolder
	bool isFileFolder; //tells us if it a secret file folder
	bool isHead; //head of the repo



public:
	Leaf() {
		manifest = "";
		lName = "";
		lExt = "";
		leafNext = NULL;
		files = NULL;
		isSubFolder = false;
		isFileFolder = false;
		isHead = false;
	}
	void assignLeafName(string name)
	{
		this->lName = name;
	}
	void assignManifest(string name)
	{
		this->manifest = name;
		this->manifest += ".txt";
	}
	//create subfolder
	//create file
	//delete subfolder
	//delete file

};


void createRepo(string source, Leaf repoName);

int main()
{
	/*source folder will be read in a series of paths
	i.e:
	main/
	main/f1/
	main/f1/t1.txt
	main/f1/f2/
	and so on...
	i think this will be easiest for recreation
	*/

	


	system("pause");
	return 0;
}

void createRepo(string source, Leaf rpn)
{
	rpn.assignLeafName(source);
	rpn.assignManifest(source);

	Leaf *emptyLeaf = new Leaf;
	

}

#include<iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class File
{
public:
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
public:
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

	void assignManifest(string name)
	{
		this->manifest = name;
		this->manifest += ".txt";
	}


	/*
	void assignLeafName(string name)
	{
		this->lName = name;
	}
	
	void assignHead(Leaf *n)
	{
		this->leafNext = n;
		cout << this->leafNext;
	}
	*/


	//create subfolder
	//create file
	//delete subfolder
	//delete file

};


void createRepo(string source, Leaf repoName);
void createFile(string newFile);

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

	
	Leaf l1;
	//Leaf *l2 = new Leaf;
	//l2->lName = "test";
	//l1.leafNext = l2;
	
	createRepo("source", l1);

	system("pause");
	return 0;
}

void createRepo(string source, Leaf rpn)
{
	rpn.lName = source;
	rpn.assignManifest(source);
	createFile(rpn.manifest);

	Leaf *emptyLeaf = new Leaf;
	

}

void createFile(string newFile)
{
	ofstream file;
	file.open(newFile);
	file << "test to see if I am creating and writing to a \n new file i made";
	file.close();
	//cout << "got here" << endl;
}

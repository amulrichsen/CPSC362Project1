#include<iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class Repo
{
private:
	string rName; //repo name
	string manifest; //manifest name .txt
	Repo *head;

public:
	Repo() {
		head = NULL;
	}
	//search tree
	//print
	//copy


};

class Leaf
{
private:
	string lName; //leaf name
	string lExt; //leaf extension -- not necessary if subfolder

	Leaf *leafNext; //points to next leaf if it is a subfolder
	File *files; //leaf file linked list -- add files inside of leaf folder

	bool isSubFolder; //tells us if it is a subfolder
	bool isFileFolder; //tells us if it a secret file folder
	


public:
	Leaf() {
		lName = "";
		lExt = "";
		leafNext = NULL;
		files = NULL;
		isSubFolder = false;
		isFileFolder = false;
	}
	//create subfolder
	//create file
	//delete subfolder
	//delete file

};

class File
{
private:
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

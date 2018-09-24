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

public:
	//search tree
	//print
	//copy


};

class Leaf
{
private:
	string lName; //leaf name
	string lExt; //leaf extension -- not necessary if subfolder

	Leaf *leafRight; //points to next right leaf if it is a subfolder
	Leaf *leafLeft; //points to next left leaf if it is a subfolder
	bool isSubFolder; //tells us if it is a subfolder
	bool isFileFolder; //tells us if it a secret file folder
	File *files; //leaf file linked list -- add files inside of leaf folder


public:
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
	//create artifact file and copy file info into it
	//create checksum and assign to artName with file extension


};

int main()
{





	system("pause");
	return 0;
}

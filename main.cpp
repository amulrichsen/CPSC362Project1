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

	Leaf *nextChild; //points to next leaf if it is a subfolder
	bool isSubFolder; //tells us if it is a subfolder
	bool isFileFolder; //tells us if it a secret file folder
	File lfarr[10]; //leaf file array -- each leaf (if a subfolder) can have up to 10 files in it


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
public:
	//create artifact file and copy file info into it
	//create checksum and assign to artName with file extension


};

int main()
{





	system("pause");
	return 0;
}

#pragma once
#include <string>
#include "file.h"
#include "leaf.h"

using namespace std;

class Leaf
{
public:
	string lName; //leaf name
	string lExt; //leaf extension -- not necessary if subfolder

	Leaf *leafNext; //points to next leaf if it is a subfolder
	File *files; //leaf file linked list -- add files inside of leaf folder

	bool isSubFolder; //tells us if it is a subfolder
	bool isFileFolder; //tells us if it a secret file folder



public:
	Leaf();




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

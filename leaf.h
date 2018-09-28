#pragma once
#include <string>
#include <filesystem>
#include "file.h"
#include "leaf.h"
#include "gtime.h"


using namespace std;

class Leaf
{
public:
	string lName; //leaf name
	string lExt; //leaf extension -- not necessary if subfolder
	string sPath; //Source Path
	string tPath; //Target Path

	Leaf *leafNext; //points to next leaf if it is a subfolder
	File *files; //leaf file linked list -- add files inside of leaf folder

	bool isSubFolder; //tells us if it is a subfolder
	bool isFileFolder; //tells us if it a secret file folder



public:
	Leaf(string sPath, string tPath, Leaf* next = NULL);

};
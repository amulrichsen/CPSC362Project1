#pragma once
#include <string>
#include <experimental/filesystem>
#include<iostream>

#include "file.h"
#include "leaf.h"
#include "manifest.h"

using namespace std;

char getSlash(string path);

class Leaf
{
public:
	string lName; //leaf name
	string lExt; //leaf extension -- not necessary if subfolder
	string sPath; //Source Path
	string tPath; //Target Path

	Leaf *leafNext; //points to next leaf if it is a subfolder
	class File *files; //leaf file linked list -- add files inside of leaf folder

	Manifest* manifest; //Pointer to the repo's manifest file

	bool isSubFolder; //tells us if it is a subfolder
	bool isFileFolder; //tells us if it a secret file folder



public:
	Leaf(string sPath, string tPath, Manifest* manifest, Leaf* next = NULL);

};
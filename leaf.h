/*	Leaf Class
	This replicates a folder from the given path.

	Authors:
	Anette Ulrichsen
	amulrichsen@csu.fullerton.edu

	Hector Rodriguez
	hrod93@csu.fullerton.edu

	John Margis
	margisj@csu.fullerton.edu
*/
#pragma once
#include <string>
#include <experimental/filesystem>
#include<iostream>

#include "file.h"
#include "leaf.h"
#include "manifest.h"

using namespace std;

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
public:
	Leaf(string sPath, string tPath, Manifest* manifest, Leaf* next = NULL);

};

//Required Prototypes
char getSlash(string path);
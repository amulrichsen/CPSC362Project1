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

class Repo
{
public:
	string rName; //repo name
	string manifest; //manifest name .txt
	Repo *head;

public:
	Repo() {
		head = NULL;
	}
	void assignRepoName(string name)
	{
		this->rName = name;
	}

	void assignManifest(string name)
	{
		this->manifest = name;
		this->manifest += ".txt";
	}

	//search tree
	//print
	//copy


};



void createRepo(string source, Repo repoName);
void createFile(string newFile);
void copyFile(string sourceName, string destName);
void readFromSource(string sourceFile);


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

	string sourceName;
	cout << "Enter the name of the source file with extension (.txt): ";
	cin >> sourceName;

	Repo r1;
	//Leaf *l2 = new Leaf;
	//l2->lName = "test";
	//l1.leafNext = l2;

	createRepo(sourceName, r1);

	readFromSource(sourceName);


	system("pause");
	return 0;
}

void createRepo(string source, Repo rpn)
{
	rpn.rName = source;
	rpn.assignManifest(source);
	createFile(rpn.manifest);

	//Leaf *emptyLeaf = new Leaf;


}

void createFile(string newFile)
{
	ofstream file;
	file.open(newFile);

	//file << "test to see if I am creating and writing to a \n new file i made";
	file.close();
	//cout << "got here" << endl;
}

/*	Params: Source file's path+name, Destination file's path + name
Function copies a file from the source to the destination
Returns: Nothing
*/
void copyFile(string sourceName, string destName)
{
	ifstream src(sourceName, ios::binary);
	ofstream dst(destName, ios::binary);

	dst << src.rdbuf();
}

void readFromSource(string sourceFile)
{
	string line = "";
	string temp = "";
	char c;
	int iter = 0;
	bool isSubFolder = false;
	bool isFile = false;
	ifstream file(sourceFile);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			//read the file line into line var and call functions
			//do-while loop because first char should always be a '/'
			c = line[iter];
			cout << "c: " << c << endl;
			do
			{
				temp += c;
				if (c == '.')
					isFile = true;
				++iter;
				c = line[iter];
				cout << temp << endl;
			} while (c != '/');

		}
		file.close();
	}

	else
		cout << "Invalid source file.\n";
}



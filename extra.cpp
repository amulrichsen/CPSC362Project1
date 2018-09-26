#include "artifact.h"
#include "file.h"
#include "leaf.h"
#include "repo.h"
#include "extra.h"

#include <fstream>
#include <iostream>

/*
void createRepo(string source, Repo repoName);
void createManifest(string newFile);
void copyFile(string sourceName, string destName);
void readFromSource(string sourceFile, Repo repo);
void createLeafFile();
void createLeafFolder();
*/

void createRepo(string source, Repo rpn)
{
	rpn.rName = source;
	rpn.assignManifest(source);
	createManifest(rpn.manifest);

	cout << "repo successful created" << endl;
	//Leaf *emptyLeaf = new Leaf;


}

void createManifest(string newFile)
{
	ofstream file;
	file.open(newFile);

	file << "test to see if I am creating and writing to a \n new manifest file i made";
	file.close();
	//cout << "got here" << endl;
	cout << "created manifest\n";
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

//void getNextLine(string line, int iter,);

void readFromSource(string sourceFile, Repo repo)
{
	string line = "";
	string curr = "";
	string prev = "";
	string sname = "";
	char c;
	int iter = 0;
	int slashCount = 0;
	//bool isSubFolder = false;
	bool isFile = false;
	bool isRoot = true;
	ifstream file(sourceFile);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			for (int i = 0; i < line.size(); i++)
			{
				if (line[i] == '/')
					slashCount++;
				if (line[i] == '.')
					slashCount++;
			}
			cout << "slash count: " << slashCount << endl;
			//read the file line into line var and call functions
			//do-while loop because first char should always be a '/'

			for (int j = 0; j < slashCount; j++)
			{
				cout << "iter: " << iter << endl;
				c = line[iter];

				do
				{
					curr += c;
					if (c == '.')
						isFile = true;

					if (iter <= (line.size() - 2))
					{
						++iter;
					}
					else
						break;

					c = line[iter];

				} while (c != '/');
				cout << "current: " << curr << endl;

				if (isRoot)
				{
					createRepo(curr, repo);
					isRoot = false;
				}
				else if (isFile == true)
				{
					cout << "Is a File\n";
					sname = ignoreSlash(curr);
					cout << "declared name will be: " << sname << endl;

					createLeafFile(sname, prev);

					//call a create file leaf function to make a file node
					isFile = false;
				}
				else
				{
					sname = ignoreSlash(curr);
					cout << "declared name will be: " << sname << endl;
					//call a create subfolder function to create a subfolder leaf node
				}

				prev += curr;
				curr = "";
				//cout << "previous: " << prev << endl;
			}

		}
		file.close();
	}

	else
		cout << "Invalid source file.\n";
}


void createLeafFile(string lname, string path)
{
	Leaf *nleaf = new Leaf(lname);
	cout << "about to fetch name\n";
	nleaf->lName = getName(lname);
	nleaf->lExt = getExt(lname);
	nleaf->leafNext = NULL;
	nleaf->files = NULL;
	nleaf->isFileFolder = true;
	nleaf->isSubFolder = false;

	//follow path to point this leaf in the right place
}


void createLeafFolder(string lname, string path)
{
	Leaf *nleaf = new Leaf(lname);
	nleaf->lName = lname;
	nleaf->leafNext = NULL;
	nleaf->files = NULL;
	nleaf->isFileFolder = false;
	nleaf->isSubFolder = true;

	//follow path to point this leaf in the right place
}

string ignoreSlash(string temp)
{
	string ret = "";
	
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] != '/')
			ret += temp[i];
	}

	return ret;
}

string getExt(string name)
{
	string temp = "";
	int count = 0;

	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] == '.')
		{
			count = i;
		}
	}

	for (count; count < name.size(); count++)
	{
		temp += name[count];
	}

	cout << "ext is: " << temp << endl;
	return temp;
}

string getName(string name)
{
	string temp = "";
	int count = 0;

	//cout << "got here\n";
	
	while (name[count] != '.')
	{
		temp += name[count];
		count++;
	}

	cout << "saved name is: " << temp << endl;
	return temp;
}
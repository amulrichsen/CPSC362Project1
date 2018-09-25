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
					++iter;
					c = line[iter];

				} while (c != '/');
				cout << curr << endl;



				if (isRoot)
				{
					createRepo(curr, repo);
					isRoot = false;
				}
				else if (isFile == true)
				{
					cout << "Is a File\n";

					//call a create file leaf function to make a file node
					isFile = false;
				}
				else
				{
					//call a create subfolder function to create a subfolder leaf node
				}

				prev = curr;
				curr = "";
			}

		}
		file.close();
	}

	else
		cout << "Invalid source file.\n";
}


void createLeafFile()
{

}


void createLeafFolder()
{

}
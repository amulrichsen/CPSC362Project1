/*	Main Functions
Contains the Main and global scope functions
This is the head of the program.

Authors:
Anette Ulrichsen
amulrichsen@csu.fullerton.edu

John Margis
margisj@csu.fullerton.edu
*/
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <string>
#include <filesystem>

#include "artifact.h"
#include "file.h"
#include "leaf.h"
#include "repo.h"

using namespace std;


//Prototypes
void copyFile(string sourceName, string destName);
char getSlash(string path);
void insertLabel(string mPath, string label);
string searchLabels(string sPath, string oldLabel);

/*	Main Function
Asks the user for the project tree folder and target folder
Then creates the repo
*/
int main()
{
	string comm;
	string label;
	string lpath;

	cout << "COMMANDS: \n";
	cout << "create\n";
	cout << "check-in\n";
	cout << "check-out\n";
	cout << "merge\n";
	cout << "label\n\n";
	cout << "ENTER A COMMAND: " << endl;
	cin >> comm;

	if (comm == "merge")
	{
		string parent = "";
		string repo = "";

		cout << "Enter the complete path of the parent project (T): ";
		cin >> parent;
		cout << "Enter the complete path of the repository: ";
		cin >> repo;

		Repo r3;
		/* check the child into the project tree T before checking the documents
		to see if they have they have small differences*/
		r3.checkIn(repo, parent);

		//merge after this
	}

	else if (comm == "create")
	{
		string sFolder = "";
		string tFolder = "";

		cout << "Enter the complete path of the source folder: ";
		cin >> sFolder;
		cout << "Enter the complete path of the target folder: ";
		cin >> tFolder;

		Repo r1;
		r1.create(sFolder, tFolder);
	}

	else if (comm == "label")
	{
		char ch;
		string fPath;
		string maniName, newLabel, oldLabel;

		//find the path to look in
		cout << "Enter repository path: ";
		cin >> fPath;

		cout << endl;
		cout << "M = add label via manifest name\n";
		cout << "L = add label via existing label\n";
		cin >> ch;

		if (ch == 'M')
		{
			cout << "Enter manifest name (including \".txt\"): ";
			cin >> maniName;
			cout << "Enter new label name: ";
			cin >> newLabel;

			//append the manifest name to the file path
			fPath += getSlash(fPath) + maniName;
			cout << "DEBUG: new file path is = " << fPath << endl;

			insertLabel(fPath, newLabel);
			cout << "DEBUG: added label\n";

		}

		else if (ch == 'L')
		{
			cout << "Enter existing label name: ";
			cin >> oldLabel;
			cout << "Enter new label name: ";
			cin >> newLabel;

			string mPath = searchLabels(fPath, oldLabel);
			insertLabel(mPath, newLabel);

		}
	}

	else if (comm == "check-out")
	{

		string sFolder = "";
		string tFolder = "";
		string manifest = "";

		cout << "Enter the complete path of the source folder: ";
		cin >> sFolder;
		cout << "Enter the complete path of the target folder: ";
		cin >> tFolder;
		cout << "Enter the manifest name or label: ";
		cin >> manifest;

		Repo r1;
		r1.checkOut(sFolder, tFolder, manifest);

	}

	else if (comm == "check-in")
	{
		string source = "";
		string tar = "";

		cout << "Enter the complete path of the source project: ";
		cin >> source;
		cout << "Enter the complete path of the repository: ";
		cin >> tar;


		Repo r2;
		r2.checkIn(source, tar);

	}


	system("pause");
	return 0;
};

string searchLabels(string sPath, string oldLabel)
{
	vector<string> existingFiles;
	string temp;
	ifstream myfile;
	string line;
	string foundMani = "empty";
	bool found = false;

	for (auto& p : experimental::filesystem::directory_iterator(sPath))
	{
		//cout << "DEBUG: " << p << endl;
		temp = p.path().string();
		existingFiles.push_back(temp);
	}

	for (int i = 0; i < existingFiles.size() && !found; i++)
	{
		//cout << existingFiles[i] << endl;
		if (existingFiles[i].find("manifest.txt"))
		{
			myfile.open(existingFiles[i]);
			while (getline(myfile, line))
			{
				if (line[0] == 'L')
				{
					line.erase(0, 3);
					if (line.compare(oldLabel) == 0)
					{
						foundMani = existingFiles[i];
						found = true;
						break;
					}
				}
			}
			myfile.close();

		}
	}

	if (!found)
		cout << "Manifest with label not found\n";
	return foundMani;
}

//inserts a label into a manifest given the manifest path (including .txt)
void insertLabel(string mPath, string label)
{
	ofstream myfile;
	myfile.open(mPath, ios::app);
	myfile << "L: " << label << "\n";
	myfile.close();
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

/*	Function to check if we're using a Windows absolute path by checking if we use / or \
*/
char getSlash(string path)
{
	if (path.find('\\') != string::npos)
		return '\\';
	else
		return '/';
}


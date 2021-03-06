/*	Repo Functions
Contains functions for the Repo Class

Authors:
Anette Ulrichsen
amulrichsen@csu.fullerton.edu

John Margis
margisj@csu.fullerton.edu

*/
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "repo.h"
using namespace std;

// Creates a repo using a source tree
void Repo::create(string sPath, string tPath) {
	this->sPath = sPath;
	//Append root folder name to the target path
	this->tPath = tPath + getSlash(this->sPath) + experimental::filesystem::path(sPath).stem().string();
	//Create Manifest
	this->manifest = new Manifest(tPath);
	this->manifest->write(sPath + ",\t" + tPath, "create-repo ARGS:\t");
	//Create initial leaf for root folder
	this->head = new Leaf(this->sPath, this->tPath, this->manifest);

	string action = "create";
	dotFile(this->tPath, this->manifest->getManifestPath(), this->sPath, action);
}
string Repo::checkIn(string sPath, string tPath) {
	//updates an existing project tree
	this->sPath = sPath;
	//Append root folder name to the target path
	this->tPath = tPath + getSlash(this->sPath) + experimental::filesystem::path(sPath).stem().string();
	//Create Manifest
	this->manifest = new Manifest(tPath);
	this->manifest->write(sPath + ",\t" + tPath, "check-in ARGS:\t");
	this->head = new Leaf(this->sPath, this->tPath, this->manifest); //Create initial leaf for root folder
																	 //checkInLog(sPath, this->manifest->getManifestPath());

	string action = "check-in";
	dotFile(this->tPath, this->manifest->getManifestPath(), this->sPath, action);

	//Return the created manifest
	return this->manifest->getManifestPath();

}

// Creates a copy of a repo using it's manifest
void Repo::checkOut(string sPath, string tPath, string manifest) {

	//creates a repo using a given manifest
	this->sPath = sPath;
	string rootName;
	// Set the source path to the project tree root folder within the source path
	for (auto & p : experimental::filesystem::directory_iterator(sPath))
	{
		string temp = p.path().string();
		if (temp.find('.') == string::npos)
		{
			this->sPath = temp;
			rootName = p.path().stem().string();
		}
	}
	this->tPath = tPath;

	// Find correct manifest to parse from
	if (manifest.find(".txt") == string::npos)
		manifest = experimental::filesystem::path(searchLabels(sPath, manifest)).stem().string() + experimental::filesystem::path(searchLabels(sPath, manifest)).extension().string();
	// Create a manifest one folder above the target project tree root folder
	this->manifest = new Manifest(tPath.substr(0, tPath.length() - (rootName.length() + 1)));
	this->manifest->write(sPath + ",\t" + tPath + ",\t" + manifest, "check-out ARGS:\t");
	this->manifest->write(sPath + getSlash(sPath) + manifest, "Parent: ");

	// Open the manifest to parse
	ifstream file(sPath + '/' + manifest);
	string line;
	//Parse line by line
	while (getline(file, line))
	{
		if (line[0] == 'L')
			break;

		else if (line[26] == 'F')
		{
			// Extract the folder name from the manifest line
			string fName = line.substr(57, line.length() - 1);
			fName.erase(fName.begin(), fName.begin() + this->sPath.length());
			// Create a directory at the tPath + folder name
			experimental::filesystem::create_directory(this->tPath + fName);
			this->manifest->write(experimental::filesystem::path(this->tPath + fName).string(), "checkout: Folder\t");

		}

		else if (line[26] == 'C')
		{
			// Extract the file name from the manifest line
			string fPath = line.substr(57, line.length() - 1);
			string fName = fPath;
			fName.erase(fName.begin(), fName.begin() + this->sPath.length());
			// Get the next line that contains the file's artifact
			getline(file, line);
			string aPath = line.substr(57, line.length() - 1);
			// Copy the artifact and rename it to its original name
			copyFile(aPath, this->tPath + '/' + fName);
			this->manifest->write(experimental::filesystem::path(this->tPath + fName).string(), "checkout: File\t");


		}


	}

	string action = "check-out";
	dotFile(this->sPath, this->manifest->getManifestPath(), this->tPath, action);
}

/*fname= file name    checksum = artifact id       rpath = repo path      mpath = manifest path selected by user*/
string Repo::ancestor(string fName, string checksum, string rPath, string mPath)
{
	cout << "Paramters: \n";
	cout << "fname: " << fName << endl;
	cout << "checksum: " << checksum << endl;
	cout << "rpath: " << rPath << endl;
	//cout << "mpath: " << mPath << endl;

	mPath = rPath + getSlash(rPath) + mPath;
	//open the log
	ifstream file(rPath + getSlash(rPath) + "Log.txt");
	string line;
	bool foundName = false;
	bool foundCheck = false;
	int foundOn = 0;


	int index = 0;
	int count = 0;

	while (getline(file, line))
	{
		if (line.find(mPath) != string::npos)
		{
			index = count;
			break;
		}
		++count;
	}

	file.close();
	file.open(rPath + getSlash(rPath) + "Log.txt");

	cout << "Found manifest path on line " << index << endl;

	cout << "Enter while loop\n";
	while (index > 0)
	{
		//loop to manifest before the manifest being searched
		for (int j = 0; j < index; j++)
		{
			getline(file, line);
		}

		size_t found = line.find("Manifest: ");
		if (found != string::npos) cout << "Found manifest path\n";
		line.erase(0, found + 10); //erase first portion
		cout << "Line: " << line << endl;
		found = line.find("\t");
		if (found != string::npos) cout << "Found tree path\n";
		int eol = line.size() - found;
		line.erase(found, eol);
		cout << "Manifest Path: " << line << endl;

		ifstream mani(line);
		string gline;

		int counter = 0;
		while (getline(mani, gline))
		{
			if ((gline.find(fName) != string::npos))
			{
				cout << "Found manifest with matching file name\n";
				foundName = true;
				foundOn = counter + 1;

			}

			if (gline.find(checksum) != string::npos)
			{
				cout << "Checksum found, wrong manifest, break while loop\n";
				foundCheck = true;
				break;

			}

			++counter;
		}


		if (foundCheck == false && foundName == true)
		{
			//found file with ancestor
			cout << "Found the correct file: " << line << endl;


			return line;

		}
		else
		{
			cout << "error, never found ancestor\n";
			return "";
		}

		index--;
	}

}


//SPATH = sPath = R's manifesto, tPath = Target Project Tree's root folder
void Repo::merge(string rPath, string tManifest, string rManifest, string tPath)
{
	tPath = experimental::filesystem::path(tPath).parent_path().string();
	//FIND COMMON ANCESTOR MANIFESTO

	//OPEN AND PARSE R's MANIFESTO

	// Open the manifest to parse
	ifstream file(rPath + '/' + rManifest);
	string line;
	//Parse line by line
	while (getline(file, line))
	{
		if (line[0] == 'L')
			break;

		else if (line[26] == 'F')
		{

			// Extract the relative path + folder name from the manifest line
			string fName = line.substr(57, line.length() - 1);
			fName.erase(fName.begin(), fName.begin() + rPath.length());
			cout << fName << endl;
			// Check if the folder exists in the target's manifest
			// If it does not exist, create it
			if (!checkExists(fName, tManifest))
			{
				experimental::filesystem::create_directory(tPath + fName);
			}
			//this->manifest->write(experimental::filesystem::path(this->tPath + fName).string(), "checkout: Folder\t");


		}
		else if (line[26] == 'C')
		{
			// Extract the file name from the manifest line
			string fName = line.substr(57, line.length() - 1);
			fName.erase(fName.begin(), fName.begin() + rPath.length());
			cout << fName << endl;
			

			// Get the next line that contains the file's artifact
			getline(file, line);
			string aPath = line.substr(57, line.length() - 1);
			string aName = aPath;
			aName.erase(aName.begin(), aName.begin() + rPath.length());
			if (checkExists(fName, tManifest))
			{
				if (!checkExists(aName, tManifest))
				{
					string extension = experimental::filesystem::path(tPath + fName).extension().string();
					string newName = fName.substr(0, fName.length() - extension.length()) + "_MR" + extension;
					// Create R's version of the file
					cout << "CREATED: " + tPath + newName << endl;
					copyFile(aPath, tPath + newName);

					// Rename T's version of the file
					newName = fName.substr(0, fName.length() - extension.length()) + "_MT" + extension;
					cout << "RENAMED: " + tPath + newName << endl;
					experimental::filesystem::rename(experimental::filesystem::path(tPath + fName), experimental::filesystem::path(tPath + newName));

					// TODO: CREATE GRANDMOTHER VERSION OF FILE
					string gManifest = ancestor(fName, aName, rPath, rManifest);
					ifstream gFile(gManifest);
					string line2;
					while (getline(gFile, line2))
					{
						string pathTest = line2.substr(line2.length() - fName.length(), line2.length() - 1);
						if (fName == pathTest)
						{
							// Get the next line (next line is always artifact)
							getline(gFile, line2);
							string gPath = line2.erase(0, 57); //1 not 58
							newName = fName.substr(0, fName.length() - extension.length()) + "_MG" + extension;
							copyFile(gPath, tPath + newName);
							break;
						}
					}
				}
			}
			else
			{
				// Copy the artifact and rename it to its original name
				copyFile(aPath, tPath + fName);
			}

		}
	}
}

// Pass the path you want to check
bool checkExists(string path, string tManifest)
{
	ifstream tFile(tManifest);
	string line;

	while (getline(tFile, line))
	{
		string pathTest = line.substr(line.length() - path.length(), line.length() - 1);
		cout << "CHECKING :" << path << " VS " << pathTest << endl;
		if (path == pathTest)
		{
			cout << "TRUE" << endl;
			return true;
		}
	}
	cout << "FALSE" << endl;
	return false;

}

/*create a text file named after the project tree that logs the
file path of the manifest created inside the repo for each check in -- ordered
oldest to newest*/
void Repo::checkInLog(string ptPath, string mPath)
{

	char s = getSlash(ptPath);
	string name = "";
	for (int i = 0; i < ptPath.size(); i++)
	{
		name += ptPath[i];

		if (ptPath[i] == s)
		{
			name = "";
		}
	}

	string curr = "";
	string previousPath = "";
	for (int i = 0; i < ptPath.size(); i++)
	{
		curr += ptPath[i];
		if (ptPath[i] == s)
		{
			previousPath += curr;
			curr = "";
		}

	}

	string manifestLog = previousPath + name + "-manifestLog.txt";

	ofstream dst;
	dst.open(manifestLog, ofstream::app);
	dst << mPath << "\n";
	dst.close();
}

//rPath -> repository path	mPath->manifest path	pPath-> parent tree path
/*keeps track of all actions taken within the repository*/
void Repo::dotFile(string rPath, string mPath, string pPath, string act)
{
	char s = getSlash(rPath);
	string curr = "";
	string previousPath = "";
	for (int i = 0; i < rPath.size(); i++)
	{
		curr += rPath[i];
		if (rPath[i] == s)
		{
			previousPath += curr;
			curr = "";
		}

	}

	string log = previousPath + "Log.txt";
	//cout << "log path: " << log << endl;

	ofstream dst;
	dst.open(log, ofstream::app);
	dst << "Action: " << act << "\tManifest: " << mPath << "\tTree: " << pPath << "\n";
	dst.close();
}

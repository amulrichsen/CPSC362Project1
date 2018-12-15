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
	checkInLog(sPath, this->manifest->getManifestPath());

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
}

//SPATH = sPath = R's manifesto, tPath = Target Project Tree's root folder
void Repo::merge(string rPath, string tManifest, string rManifest, string tPath)
{
	//Set Target Project Folder path to root (One folder up)
	tPath = experimental::filesystem::path(tPath).parent_path().string();
	this->manifest = new Manifest(tPath);
	this->manifest->write(rPath + ",\t" + tManifest + ",\t" + rManifest + ",\t" + tPath + ",\t", "check-out ARGS:\t");
	// Find correct manifest to parse from
	if (rManifest.find(".txt") == string::npos)
		rManifest = experimental::filesystem::path(searchLabels(rPath, rManifest)).stem().string() 
		+ experimental::filesystem::path(searchLabels(rPath, rManifest)).extension().string();

	//FIND COMMON ANCESTOR MANIFESTO
	string gManifest;
	//OPEN AND PARSE R's MANIFESTO
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
			this->manifest->write(experimental::filesystem::path(tPath + fName).string(), "Merge: Folder\t");


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
			/* Check if the file exists within the TARGET project tree */
			if (checkExists(fName, tManifest))
			{
				/*  Check if the TARGET project tree's file is the same as the REPO's file 
					If not, create CONFLICT versions of the file		*/
				if (!checkExists(aName, tManifest))
				{
					/*	Extract the extension from the file and insert _MR, _MT, or _MG before it */
					string extension = experimental::filesystem::path(tPath + fName).extension().string();
					string newName = fName.substr(0, fName.length() - extension.length()) + "_MR" + extension;

					// Create R's version of the file
					cout << "CREATED: " + tPath + newName << endl;
					copyFile(aPath, tPath + newName);
					this->manifest->write(experimental::filesystem::path(tPath + newName).string(), "Merge: File Conflict\t");


					// Rename T's version of the file
					newName = fName.substr(0, fName.length() - extension.length()) + "_MT" + extension;
					cout << "RENAMED: " + tPath + newName << endl;
					experimental::filesystem::rename(experimental::filesystem::path(tPath + fName), experimental::filesystem::path(tPath + newName));
					this->manifest->write(experimental::filesystem::path(tPath + newName).string(), "Merge: File Conflict\t");


					// Create G's version of the file
					/* To do this we loop through GRANDMA's manifest until we find it's version of the file */
					ifstream gFile(gManifest);
					string line2;
					while (getline(gFile, line2))
					{
						string pathTest = line2.substr(line2.length() - fName.length(), line2.length() - 1);
						if (fName == pathTest)
						{
							// Get the next line (next line is always artifact)
							getline(gFile, line2);
							string gPath = line2.substr(57, line2.length() - 1);
							newName = fName.substr(0, fName.length() - extension.length()) + "_MG" + extension;
							copyFile(gPath, tPath + newName);
						}
					}
				}
			}
			else
			{
				// Copy the artifact and rename it to its original name
				copyFile(aPath, tPath + fName);
				this->manifest->write(experimental::filesystem::path(tPath + fName).string(), "Merge: File Created\t");

			}

		}
	}
}

/* Checks for the given (path) string within the given tManifest file */
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



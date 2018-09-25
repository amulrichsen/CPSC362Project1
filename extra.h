#include "artifact.h"
#include "file.h"
#include "leaf.h"
#include "repo.h"


void createRepo(string source, Repo repoName);
void createManifest(string newFile);
void copyFile(string sourceName, string destName);
void readFromSource(string sourceFile, Repo repo);
void createLeafFile(string lname, string path);
void createLeafFolder(string lname, string path);
string ignoreSlash(string temp);
string getExt(string name);
string getName(string name);

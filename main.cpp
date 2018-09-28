#include<iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

#include "artifact.h"
#include "file.h"
#include "leaf.h"
#include "repo.h"
#include "extra.h"


int main()
{	
	string sFolder = "";
	string tFolder = "";

	cout << "Enter the complete path of the source folder: ";
	cin >> sFolder;
	cout << "Enter the complete path of the target folder: ";
	cin >> tFolder;

	Repo r1(sFolder, tFolder);

	system("pause");
	return 0;
};


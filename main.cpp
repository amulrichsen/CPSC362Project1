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

	//createRepo(sourceName, r1);

	readFromSource(sourceName, r1);


	system("pause");
	return 0;
}


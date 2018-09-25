#include "leaf.h"
#include <iostream>

using namespace std;

Leaf::Leaf() {
	lName = "";
	lExt = "";
	leafNext = NULL;
	files = NULL;
	isSubFolder = false;
	isFileFolder = false;
}

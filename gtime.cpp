#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

#include "gtime.h"

void getTime()
{
	time_t now = time(NULL);
	tm * tmPtr = localtime(&now);
	char buffer[32];
	strftime(buffer, 32, "%a %m/%d/%Y %H:%M:%S", tmPtr);
	puts(buffer);
}
/****https://stackoverflow.com/questions/2770555/how-do-i-save-time-to-a-file ****/
/*I referenced the above website to find a way to read the buffer into a file correctly*/

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <fstream>

#include "gtime.h"

using namespace std;

static char *getDT(char *buff)
{
	time_t t = time(0);
	strftime(buff, 32, "%a %m/%d/%Y %H:%M:%S", localtime(&t));
	return buff;
}

void getTime()
{
	char buff[32];
	fstream file;
	file.open("timetrans.txt", fstream::out | fstream::app);

	file << getDT(buff);
	file.close();
}
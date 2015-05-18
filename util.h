#include <iostream>
#include <string>

#include <array>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>

#include <mcheck.h>

using namespace std;

#ifndef UTIL
#define UTIL

void err_exit(const char *msg)
{
	cout << msg << endl;
	exit(0);
}

#endif
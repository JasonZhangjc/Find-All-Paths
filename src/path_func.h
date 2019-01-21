#ifndef _PATH_FUNC_H_
#define _PATH_FUNC_H_

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<string> Path;
typedef vector<string>::iterator Path_it;
typedef vector<Path> PathSet;
typedef vector<Path>::const_iterator Paths;


void SplitString(const string& s, vector<string>& v, const string& c);
Path findAllPaths(const string& src, const string& dst, const PathSet& p_s);

#endif //_PATH_FUNC_H_

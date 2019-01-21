#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "path_func.h"

using namespace std;

typedef vector<string> Path;
typedef vector<string>::iterator Path_it;
typedef vector<Path> PathSet;
typedef vector<Path>::const_iterator Paths;


int main ()
{	
	PathSet path_set = {};
	Path all_paths = {};
	string data = "";
	
	  // open the file
	ifstream infile; 
   	infile.open("input.dat");
	
	cout << "Reading from the file" << endl; 
   	
	while (getline(infile,data)) {
		Path p = {};
		SplitString(data, p, ","); 
		path_set.push_back(p);
		cout << data << endl;
	}
  	 	
   	  // close the fiile
   	infile.close();
   	
   	cout << "There are " << path_set.size() << " nodes in this graph."<< endl;
   	cout << "The source is: " << path_set.at(0).at(0) << endl;
   	cout << "The destination is: " << path_set.at(path_set.size()-1).at(0) 
   	     << endl;
   	all_paths = findAllPaths(path_set.at(0).at(0), 
   	                         path_set.at(path_set.size()-1).at(0),
   	                         path_set);
    
   	return 0;
}







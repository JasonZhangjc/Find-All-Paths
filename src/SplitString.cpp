#include "path_func.h"

void SplitString(const string& s, vector<string>& v, const string& c)
{
  	string::size_type pos1, pos2;
  	pos2 = s.find(c);
  	pos1 = 0;
  	while(string::npos != pos2)
  	{
    	v.push_back(s.substr(pos1, pos2-pos1));
 
    	pos1 = pos2 + c.size();
    	pos2 = s.find(c, pos1);
  	}
  	if(pos1 != s.length())
    	v.push_back(s.substr(pos1));
    // v.back() = v.back().substr(0, v.back().length() - 1);
}

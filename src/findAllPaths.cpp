#include "path_func.h"

  /* This function is used to find all paths corresponding to a         *
   * source state src and a destination state dst in a directed graph   *
   * with cycles                                                        */
Path findAllPaths(const string& src, const string& dst, const PathSet& p_s) {
	Path p = {};  // p is to store all forcible paths found
	
	  // initialize the "in_stack" marker 
	map<string, string> in_stack;
	for (int i=0; i<p_s.size(); i++) {
		in_stack.insert(pair<string, string>(p_s.at(i).at(0) , "0"));
	}
	  // check whether the "in_stack" is as expected
	map<string, string>::iterator its = in_stack.begin();
/*
	for( ; its!=in_stack.end(); ++its)
    	cout << "key: " << its->first << ", "
         	 << "value: " << its->second << endl;
*/	
	
	  // initialize the "is_visited" marker
	  // The is_visited_temp is used in is_visited
	//cout << "The vector is_visited_temp: " << endl;
	PathSet is_visited_temp = p_s;
	for (int i=0; i<is_visited_temp.size(); i++) {
		is_visited_temp.at(i).assign(is_visited_temp.at(i).size()-1, "0");
		  // check whether the "is_visited_temp" is as expected
		Path_it it = is_visited_temp.at(i).begin();
/*		
		for (; it != is_visited_temp.at(i).end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
*/
	}
	  // is_visited
	map<string, Path> is_visited;
	for (int i=0; i<p_s.size(); i++) {
		is_visited.insert(pair<string, vector<string>>(p_s.at(i).at(0), 
		                                            is_visited_temp.at(i) ));
	}
	  // check whether the "is_visited" is as expected
	map<string, vector<string>>::iterator itv = is_visited.begin();
	//cout << "The vector is_visited: " << endl;
/*
	for( ; itv!=is_visited.end(); ++itv) {
    	cout << "key: " << itv->first << ", " << "value: ";
    	Path_it ite = itv->second.begin();
		for (; ite != itv->second.end(); ite++) {
			cout << *ite << " ";
		}
		cout << endl;
    }
*/   
              
	  // The algorithm is based on DFS
	Path stack = {};
	stack.push_back(src);
	in_stack.at(src) = "1";
		
	  // Main loop
	while (!stack.empty()) {		
		  // Based on DFS 
		  // Use find to decide
		Path_it it_ele = find(is_visited.at(stack.back()).begin(), 
		                      is_visited.at(stack.back()).end(), "0");
		int n_pos = distance(is_visited.at(stack.back()).begin(), it_ele);
		while (it_ele != is_visited.at(stack.back()).end()) {
			int idx = 0;
		    for (int j=0; j<p_s.size(); j++) {
		    	if (p_s.at(j).at(0) == stack.back())
		       		break;
		       	idx++;
		    }
			if (in_stack.at(p_s.at(idx).at(n_pos + 1)) == "1") {
				is_visited.at(stack.back() ).at(n_pos) = "1";
				break;
			}
			else {				
				if (!is_visited.at(stack.back()).empty())
					is_visited.at(stack.back()).at(n_pos) = "1";
				stack.push_back(p_s.at(idx).at(n_pos + 1));
				in_stack.at(p_s.at(idx).at(n_pos + 1)) = "1";
				//cout << "Push a new state in stack!" << endl;
				break;
			}
		}
        
        //cout << "Reach the output module!" << endl;
		if (stack.back() == dst) {	
			string forcible_path = "";
				
			Path_it it = stack.begin();
			for (; it != stack.end(); it++) {
				forcible_path = forcible_path + "->" + *it;
			}
		
			cout << "Found a forcible path: " << forcible_path << endl;
		
			in_stack.at(stack.back()) = "0";
			stack.pop_back();	
			//continue;
		} 
            
        //cout << "Reach the pop module!" << endl;
		string marker = "0";
		Path_it itm = is_visited.at(stack.back()).begin();
		for( ; itm!=is_visited.at(stack.back()).end(); ++itm) {
			if (*itm == "0")
				marker = "1";
    	}
    	//cout << "The last ele in stack is: " << stack.back() << endl;
    	
    	if (marker == "0") {
    		in_stack.at(stack.back()) = "0";
    		Path_it itc = is_visited.at(stack.back()).begin();
			for( ; itc!=is_visited.at(stack.back()).end(); ++itc) {
				*itc = "0";
    		}
    		stack.pop_back();
    	}
    	
    	//cout << "Is stack empty???? " << stack.empty() << endl;
    	Path_it ito = stack.begin();			
    }
	
	return p;
}

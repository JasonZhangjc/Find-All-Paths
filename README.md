# Find all forcible paths between the src and the dst
This is a demo of a short program for finding all forcible paths between the source state and the destination state in a discrete-event system (DES). A DES can be represented as a directed graph (possibly with cycles), in which the nodes can represent states and the edges can represent transitions. The algorithm used in this program is based on DFS. In fact, this program also works for undirected graphs.

Required tools:
 1. cmake (See here: https://cmake.org/download/)
 
To build the project:
 1. Go to build directory.
 2. Run cmake ..
 3. Run make
 4. Run ./Paths (with input.dat in the build folder)
 
For the graph stored in input.dat
For example:

0,1,2
1,2
2,3,4
3,1,5
4,5
5

The graph is stored in linked_list format.
It means that the node 0 has two edges from it. One edge points to node 1 and the other edge points to node 2.
The node 1 has only one edge from it. The edge points to node 2.
...
The node 5 has no edge from it.

As a result, if we select 0 as the source and 5 as the destination, there are four paths in total:
Found a forcible path: ->0->1->2->3->5
Found a forcible path: ->0->1->2->4->5
Found a forcible path: ->0->2->3->5
Found a forcible path: ->0->2->4->5


/** @brief Finds a topological sort from a given input.

  This file take in one command line argument in a tab separated list of edges of a graph.
  The function then saves these edges and nodes into respective vectors.  It then proceeds to loop
  through the vector list, looking for vectors of indegree 0 and removing themselves and edges that
  originate from them from the vectors of edges and nodes, respectively.  The program them outputs
  a valid topological sort to the console.

  @author Conner Steenrod
  @date April 21, 2020
  @file topological.cpp
  @see https://www.cplusplus.com/reference/vector/vector/
  @warning Program will fail if incorrect command line arguments are given.
  */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief The main method that holds all code for this file.
 */

int main(int argc, char** argv){
	if (argc != 2){
		cout << "Bad input" << endl;
		exit(1);
	}

	ifstream file(argv[1]);
	if (!file.is_open()){
		cout << "File not found" << endl;
		exit(2);
	}

	vector<pair<string,string>> edges;
	vector<string> nodes;
	string a, b;
	bool pass = true;
	while (pass) {
		file >> a;
		file >> b;
		//cout << "edge " << a << " - " << b << endl;
		if (a == "0" && b == "0") {
			pass = false;
		}
		else {
		//	cout << " adding to tree!" << endl;
			edges.push_back({a, b});
		}
		if (pass && find(nodes.begin(), nodes.end(), a) == nodes.end()){
			nodes.push_back(a);
		}
		if (pass && find(nodes.begin(), nodes.end(), b) == nodes.end()){
			nodes.push_back(b);
		}
	}

	string sort;
	bool isempty = false;
	while (!isempty){
		//check if empty
		bool testempty = true;
		for (string node : nodes){
			if (node != ""){
				testempty = false;
			}
		}
		if (testempty){
			isempty = true;
			continue;	
		}

		//find node of indegree 0
		for(string node : nodes){
			//cout << "testing: " << node << endl;
			if (node == ""){
			//	cout << "    Continuing..." << endl;
				continue;	
			}
			
			int indegree = 0;
			for(auto edge : edges){
			//	cout << "              Testing edge: " << edge.first << " - " << edge.second << endl;
				if (edge.second == node){
			//		cout << "               match!" << endl;
					indegree++;
				}
			}
			//cout << "    indegree:" << indegree << endl;

			if (indegree == 0){
				//remove edges from node			
				for (int i = 0; i < edges.size(); i++){
					if (edges[i].first == node){
						edges[i] = {"", ""};
					}
				}
				//get index of node to remove from list
				for (int i = 0; i < nodes.size(); i++){
					if (nodes[i] == node){
						nodes[i] = "";
					}
				}
				sort += node + " ";	
			}
		}
	}

	cout << sort << endl;

	return 1;
}

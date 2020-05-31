/*
 * Conner Steenrod
 * cts4cv
 * 4/13/20
 * huffmanenc.cpp
 */

#include "huffheap.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void genPrefix(huffnode* node, unordered_map<char, string> &codes, string route);

int main(int argc, char** argv){
	//read in frequencies
	if (argc != 2){
		cout << "Incorrect args!" << endl;
		exit(1);
	}
	
	ifstream file(argv[1]);
	if (!file.is_open()) {
		cout << "File could not be opened!" << endl;
		exit(2);
	}
	
	unordered_map<char, int> values;
	char c;
	string phrase;
	while (file.get(c)){
		if (c > 31 && c < 127){
			if (values.count(c)){
				values[c] += 1;
			}
			else {
				values.insert({c, 1});
			}
			phrase += c;
		}
	}
	file.close();

	//put values in minheap
	
	huffheap* hh = new huffheap();

	for (auto pair : values){
		huffnode * node = new huffnode(pair.first, pair.second);
		hh->insert(node);
	}


	//build huffman tree
	int i = 127;
	while (hh->size() > 1){
		huffnode* first = hh->deleteMin();
		huffnode* second = hh->deleteMin();
		huffnode* combined = new huffnode((char)(i), first->freq + second->freq);
		combined->left = first;
		combined->right = second;
		hh->insert(combined);
	}
	huffnode* tree = hh->deleteMin();

	//build prefix codes
	unordered_map<char, string> codes;
	genPrefix(tree, codes, "");
	cout << "----------------------------------------" << endl;
	
	//print out encoded phrase
	int newcount = 0;
	for (char& c : phrase){
		for(auto pair : codes){
			if (pair.first == c){
				cout << pair.second << " ";
				newcount += pair.second.length();
			}
		}
	}	
	
	cout << endl;
	cout << "----------------------------------------" << endl;

	//print stats
	double cr = ((double) phrase.length() * 8) / ((double)newcount);
	cout << "Compression Ratio: " << cr << endl;
	double cost = 0.0;
	for (auto pairone : values){
		for (auto pairtwo : codes){
			if (pairone.first == pairtwo.first){
				cost += ((double)pairone.second / phrase.length() * pairtwo.second.length());
			}
		}
	}
	cout << "Cost: " << cost << endl;


	return 0;
}

void genPrefix(huffnode* node, unordered_map<char, string> &codes, string route){
	if (int(node->val) < 127){
		if (node->val == ' '){
			cout << "space " << route << endl;
		}
		else {
			cout << node->val << " " << route << endl;
		}
		codes.insert({node->val, route});
	}
	if (node->left != 0){
		genPrefix(node->left, codes, route + "0");
	}
	if (node->right != 0){
	genPrefix(node->right, codes, route + "1");
	}
}

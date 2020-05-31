/*
 * Conner Steenrod
 * cts4cv
 * 4/14/20
 * huffmandec.cpp
 */

#include "huffnode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main (int argc, char** argv){
	if (argc != 2){
		cout << "Incorrect arguments" << endl;
		exit(1);
	}

	ifstream file(argv[1], ifstream::binary);
	if (!file.is_open()) {
		cout << "Cannot open file" << endl;
		exit(2);
	}

	huffnode* root = new huffnode((char)128, 0);
	while(true){
		string letter, path;
		file >> letter;
		if (letter[0] == '-' && letter.length() > 1) {
			break;
		}
		if (letter == "space"){
			letter = ' ';
		}

		file >> path;
		//build tree recursively		
		huffnode* loc = root;
		while (path.length() > 0){
			if (path[0] == '0'){
				if (loc->left != 0){
					loc = loc->left;
				}
				else {
					huffnode* newleft = new huffnode((char)128, 0);
					loc->left = newleft;
					loc = newleft;
				}
			}
			else if (path[0] == '1'){
				if (loc->right != 0){
					loc = loc->right;
				}
				else {
					huffnode* newright = new huffnode((char)128, 0);
					loc->right = newright;
					loc = newright;
				}
			}
			else{
				cout << "Bad path" << endl;
				exit(3);
			}
			path = path.substr(1, path.length());
		}
		loc->val = letter[0];

	}
	

	stringstream sstm;
	while(true){
		string bits;
		file >> bits;
		if(bits[0] == '-'){
			break;
		}
		sstm << bits;
	}

	string message = sstm.str();
	string decoded = "";
	huffnode* finder = root;
	for (char c : message){
		if (c == '0'){
			finder = finder->left;
		}
		else if (c == '1'){
			finder = finder->right;
		}
		else {
			cout << "Invalid phrase to decode" << endl;
			exit(4);
		}
		if (finder->val != (char)128){
			cout << finder->val;
			finder = root;
		}
	}
	cout << endl;

	file.close();

	return 0;
}

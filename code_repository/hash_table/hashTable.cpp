/*
 * Conner Steenrod
 * cts4cv
 * 3/2/20
 * hashTable.cpp
 */

#include "hashTable.h"
#include <string>
#include <math.h>
using namespace std;

Hash::Hash(){
	dictSize = 26717;
	dict.reserve(dictSize);
	revDict.reserve(dictSize);
       for (unsigned int i = 0; i < dictSize; i++){
		dict.push_back("");
		revDict.push_back("");
       }
}

Hash::Hash(unsigned int s){
	dictSize = getNextPrime(s);
	dict.reserve(dictSize);
	revDict.reserve(dictSize);
	for (unsigned int i = 0; i < dictSize; i++){
		dict.push_back("");
		revDict.push_back("");
	}

}

Hash::~Hash(){
}

string Hash::value(unsigned int index){
	return dict.at(index);
}

string Hash::revValue(unsigned int index){
	return revDict.at(index);
}

void Hash::set(unsigned int index, string key){
	dict.at(index) = key;
}

unsigned int Hash::hashWord(string s){
	unsigned int hashedVal = 0;
	for (const char &c : s){
		hashedVal += (int)c;
		hashedVal *= 37;
	}
	return hashedVal % dictSize; 
}

void Hash::printDict(){
	for (unsigned int i = 0; i < dictSize; i++){
		cout << i << ": " << dict.at(i) << endl;
	}
}

bool Hash::linProbe(unsigned int oldHash, unsigned int loop, string toInsert, int count){
	if (value(oldHash) == ""){
		set(oldHash, toInsert);
		return true;
	}
	else if (loop == oldHash){
		return false;
	}
	else {
		return linProbe((oldHash + 2 * count + 1)%dictSize, loop, toInsert, count + 1);
	}
}

bool Hash::test(string s){
	unsigned int hashToTest = hashWord(s);
	int count = 0;
	while (value(hashToTest) != ""){
		if (value(hashToTest) == s){
			return true;
		}
		hashToTest = (hashToTest + 2 * count + 1)%dictSize;
		count += 1;
	}
	return false;
	//return findWord(hashToTest, s, 0);
}

bool Hash::findWord(unsigned int h, string s, int count){
	if (value(h) == s){
		return true;
	}
	else if (value(h) != ""){
		return findWord((h + 2 * count + 1)%dictSize, s, count + 1);
	}
	else{
		return false;
	}
}

bool Hash::revTest(string s){
	unsigned int hashToTest = hashWord(s);
	return revFindWord(hashToTest, s, 0);
}

bool Hash::revFindWord(unsigned int h, string s, int count){
	if (revValue(h) == s){
		return true;
	}
	else if (revValue(h) != ""){
		count += 1;
		return findWord((h + count * count)%dictSize, s, count);
	}
	else{
		return false;
	}
}

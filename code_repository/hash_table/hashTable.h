/*
 * Conner Steenrod
 * cts4cv
 * 3/2/20
 * hash.h
 */

#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <vector>
#include "primenumber.h"

using namespace std;

class Hash {
public:
    Hash();
    Hash(unsigned int s);
    ~Hash();
    string revValue(unsigned int index);
    string value(unsigned int index);
    void set(unsigned int index, string key);
    unsigned int hashWord(string s);
    void printDict();
    bool test(string s);
    bool revTest(string s);
    bool linProbe(unsigned int oldHash, unsigned int loop, string toInsert, int count);

private:
	vector<string> dict;
	vector<string> revDict;
	unsigned int dictSize;

	bool revFindWord(unsigned int h, string s, int count);
	bool findWord(unsigned int h, string s, int count);
	vector<int> multiple;
};

unsigned int hashWord(string s);

#endif

/*
 * Conner Steenrod
 * cts4cv
 * 4/14/20
 * huffnode.h
 */

#ifndef HUFFNODE_H
#define HUFFNODE_H
class huffnode {
	public:
		huffnode();
		huffnode(char v, int f);
		~huffnode();
		huffnode* left;
		huffnode* right;
		int freq;
		char val;
};
#endif

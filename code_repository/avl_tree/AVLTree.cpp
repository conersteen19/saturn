#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
	if (find(x)){
		return;
	}
	AVLNode* newNode = new AVLNode();
	newNode->value = x;
	newNode->height = 1;
	if (root == NULL){
		root = newNode;
	}
	else {
		root = insert(root, newNode);
	}
}

AVLNode* AVLTree::insert(AVLNode* currentNode, AVLNode* toInsert) {
	if (currentNode->value < toInsert->value && currentNode -> right == NULL){
		currentNode->right = toInsert;
		
	}
	else if (currentNode->value > toInsert->value && currentNode->left == NULL){
		currentNode->left = toInsert;
	
	}
	else if (currentNode -> value < toInsert->value){
		currentNode->right = insert(currentNode->right, toInsert);
	}
	else {
		currentNode->left = insert(currentNode->left, toInsert);
	}
	currentNode->height = 1 + max(height(currentNode->right), height(currentNode->left));
	return balance(currentNode);
}
// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    if (find(x)){
    	root = remove(root, x);

    }
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
	if (find(x)){

		return pathTo(root, x);
	}
	return "";
}

string AVLTree::pathTo(AVLNode* node, string find) const  {
	if (node->value == find){
		return find;
	}
	else if (node->value > find){
		return node->value + " " + pathTo(node->left, find);
	}
	else {
		return node->value + " " + pathTo(node->right, find);
	}
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    return find(root, x);
}

bool AVLTree::find(AVLNode* node, string val) const {
	if (node == NULL){
		return false;
	} 
	else if (node->value == val){
		return true;
	}
	else if (node->value > val){
		return find(node->left, val);
	}
	else {
		return find(node->right, val);
	}	
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
	return numNodes(root);
}

int AVLTree::numNodes(AVLNode* node) const {
	if (node == NULL){
		return 0;
	} else {
		return 1 + numNodes(node->left) + numNodes(node->right);
	}
}
		

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
AVLNode* AVLTree::balance(AVLNode* n) {
	int bf = getBf(n);
	if (bf == 2){
		if (getBf(n->right) < 0){
			n->right = rotateRight(n->right);
		}
		n = rotateLeft(n);
	}
	else if (bf == -2){	
		if (getBf(n->left) > 0){
			n->left = rotateLeft(n->left);
		}
		n = rotateRight(n);
	}
	return n;
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    AVLNode* b = n->right;
    AVLNode* c = b->left; 
    n->right = c;
    b->left = n;
    n->height = 1 + max(height(n->right), height(n->left));
    b->height = 1 + max(height(b->right), height(b->left));
    return b;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    AVLNode* b = n->left;
    AVLNode* c = b->right;
    n->left = c;
    b->right = n;
    n->height = 1 + max(height(n->right), height(n->left));
    b->height = 1 + max(height(b->right), height(b->left)); 
    return b;

}

int AVLTree::getBf(AVLNode* node){
	int r;
	int l;
	if (node->right != NULL){
		r = node->right->height;
	}
	else {
		r = 0;
	}
	if (node->left != NULL){
		l = node->left->height;
	}
	else {
		l = 0;
	}
	return r - l;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    return balance(n);
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << " (" << root->height << ")" << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}

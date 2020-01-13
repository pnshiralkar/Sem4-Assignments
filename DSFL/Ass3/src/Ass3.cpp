//============================================================================
// Name        : Ass3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template <class T>
class Node{
public:
	T val;
	Node *left, *right;
};

template <class T>
class BinTree{
	Node *head;
public:
	void create()
	{
		createRec(head, "root node");
	}

	void createRec(Node<T> *root, string name)
	{
		root = new Node;
		int res;
		cout << "Enter data for the node (" << name << ") : "; cin >> root->val;
		cout << "This Node has ? (1. Both nodes , 2. Only left , 3. Only Right , 4. No child nodes) : "; cin >> res;
		if(res==4){
			root->left = NULL;
			root->right = NULL;
			return;
		}
		if(res==2){
			root->right = NULL;
			createRec(root->left, "left child of " + root->val);
			return;
		}
		if(res==3){
			root->left = NULL;
			createRec(root->right, "right child of " + root->val);
			return;
		}
		if(res==1){
			createRec(root->left, "left child of " + root->val);
			createRec(root->right, "right child of " + root->val);
		}

	}
};

int main() {
	BinTree<int> bt;
	bt.create();
	return 0;
}

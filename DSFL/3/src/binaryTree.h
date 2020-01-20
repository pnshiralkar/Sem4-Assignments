/*
 * binaryTree.h
 *
 *  Created on: 20-Jan-2020
 *      Author: dsflh-10
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
class node {
public:
	int key_value;
	node *left;
	node *right;
};
class binaryTree {

public:
	  node *root;
	binaryTree();
	void Insert(int key, node *leaf);
    void insert(int key);
    void display();



};

#endif /* BINARYTREE_H_ */

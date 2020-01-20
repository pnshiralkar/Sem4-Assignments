/*
 * binaryTree.cpp
 *
 *  Created on: 20-Jan-2020
 *      Author: dsflh-10
 */

#include "binaryTree.h"
#include <iostream>
#include <queue>
using namespace std;
binaryTree::binaryTree() {
	root=NULL;
}


void binaryTree::insert(int key) {

	 if(root!=NULL)
	    Insert(key, root);
	  else
	  {
	    root=new node;
	    root->key_value=key;
	    root->left=NULL;
	    root->right=NULL;
	  }

}

void binaryTree::Insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left!=NULL)
     Insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      Insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

void binaryTree::display() {
	node *temp;
	temp = root;
	cout<<1;

	if(root == NULL) {
		return ;
	}

	while(temp->left != NULL) {
	cout<<temp->left->key_value<<"  ";
	temp = temp->left;
	}
}



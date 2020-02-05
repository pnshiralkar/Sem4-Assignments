/*
 * binaryTree.cpp
 *
 *  Created on: 20-Jan-2020
 *      Author: dsflh-10
 */

#include "binaryTree.h"
#include <bits/stdc++.h>
#include <queue>
using namespace std;
binaryTree::binaryTree() {
	root=NULL;
}

node* binaryTree::getRoot() {
	
	return root;
}

int binaryTree::isempty() {
	
	if(root ==NULL) {
		
		return 1;
	}
	else {
		return 0;
	}
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
    	cout<<12;

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
    	cout<<1;

      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

void binaryTree::display(node *temp) {

	if (temp!=NULL)
	{
		display(temp->left);
		cout<<"   "<<temp->key_value;
		display(temp->right);
	}	
	
	if(isempty())
		cout<<"\nTree is empty. ";
	
}

int binaryTree::depth(node* temp) {

	int depthLeft,depthRight;
	if(!isempty()) {
		
		if(temp == NULL) 
			return -1;
			
		depthLeft = depth(temp->left);
		depthRight = depth(temp->right);
			
		return max(depthLeft,depthRight)+1;
	}
	
	else
		cout<<"\n\nTree is empty";
}

void binaryTree::displayLeaf(node *temp) {
	
	if(temp!=NULL) {
		displayLeaf(temp->left);
		if(temp->left ==NULL && temp->right ==NULL)
			cout<<"  "<<temp->key_value;
			
		displayLeaf(temp->right);
	}
	
	if(isempty()) {
		cout<<"\n\nEmpty Tree";
	}
}

node* binaryTree::copyTree(node* root) {

	node *temp = NULL;
	if(root!=NULL) 
	{
		temp = new node;
		temp->key_value = root->key_value;
		temp->left = copyTree(root->left);
		temp->right = copyTree(root->right);
	}
	
	return temp;
}



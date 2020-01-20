//============================================================================
// Name        : 3.cpp
// Author      : Atre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "binaryTree.h"
#include "binaryTree.cpp"
using namespace std;

int main() {
	binaryTree tree;
	int n;
	int f=1;
	int ch;
	while(f) {
		cout<<"\n***Binary Tree Operations***\n";
		cout<<"1.Insert\n2.Display\n3.Depth of a tree\n4.Display leaf-nodes\n5.Create a copy of a tree\n6.Exit";
		cout<<"\n\nEnter you're choice:- ";
		cin>>ch;
		switch(ch) {
			case 1:
				cout<<"\nEnter the key to Insert:- ";
				cin>>n;
				tree.insert(n);
				break;
			case 2:
				tree.display();

		}
	}
}


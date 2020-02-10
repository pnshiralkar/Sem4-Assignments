//============================================================================
// Name        : 4.cpp
// Author      : Atre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, ANSI-style
//============================================================================

#include <iostream>
#include<stack>
using namespace std;

typedef struct node {
	char value;
	node *left;
	node *right;
}node;

class expression {
	node *root;
public:
	expression() {
		root = NULL;
	}

	node *createTree(string );
	void inorder(node*);
	node *newNode(int );


};

bool isOperator(char c) {
	if(c=='+' || c == '-' || c=='*' || c=='/' || c=='^')
		return true;

	return false;
}

node* expression::newNode(int v) {
	node *temp = new node;
	temp->left = temp->right = NULL;
	temp->value = v;
	return temp;
}

node* expression::createTree(string postfix) {

	stack<node *> st;
	node *t1,*t2;

	for(int i=0;i<postfix.length();i++) {

		if(!isOperator(postfix[i])) {
			root = newNode(postfix[i]);
			cout<<root->value<<"   \n\n";
			st.push(root);
		}

		else {
			root = newNode(postfix[i]);
			t1 = st.top();
			st.pop();
			t2 = st.top();
			cout<<root->value<<"   \n\n";

			root->right = t1;
			root->left = t2;

			st.push(root);
		}
	}

	root = st.top();
	st.pop();
	return root;
}

void expression::inorder(node *t) {
	if(t) {
		inorder(t->left);
		cout<<"  "<<t->value;
		inorder(t->right);

	}

}

int main() {
	string postfix;
	cout<<"Enter postfix string:- ";
	cin>>postfix;
	expression et;
	node *exptree;
	exptree = et.createTree(postfix);
//	cout<<exptree->value<<"\n\n";
	et.inorder(exptree);
	cout<<"\n\n";


}

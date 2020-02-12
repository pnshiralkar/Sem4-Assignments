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
	void postorder(node*);
	void preorder(node*);
	void NinOrder(node*);
	void NpostOrder(node*);
	void NpreOrder(node*);
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
//			cout<<root->value<<"   \n\n";
			st.push(root);
		}

		else {
			root = newNode(postfix[i]);
			t1 = st.top();
			st.pop();
			t2 = st.top();
			st.pop();
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

void expression::postorder(node *t) {
	if(t) {
		postorder(t->left);
		postorder(t->right);
		cout<<" "<<t->value;
	}

}

void expression::preorder(node *t) {
	if(t) {
		cout<<" "<<t->value;
		preorder(t->left);
		preorder(t->right);
	}
}

void expression::NinOrder(node *t) {
	stack<node*> st;
	node *curr = t;
	while(curr!=NULL || st.empty() == false )
	{
		while(curr != NULL) {
			st.push(curr);
			curr= curr->left;
		}
		curr= st.top();
		st.pop();

		cout<<curr->value<<" ";

		curr = curr->right;
	}
}

void expression::NpostOrder(node *t) {
	stack<node*> st1;
	stack<node*> st2;
	node *temp = t;
	st1.push(temp);
	while(!st1.empty()) {
		temp = st1.top();
		st1.pop();
		st2.push(temp);

		if(temp->left) {
			st1.push(temp->left);
		}
		if(temp->right) {
			st1.push(temp->right);
		}
		}

	while(!st2.empty()) {
		temp = st2.top();
		st2.pop();
		cout<<" "<<temp->value;
	}
}



int main() {
	string postfix;
	int f=1;
	expression et;
	node *exptree;
	int ch;
	while(f) {
		cout<<"\tAssignment 4\n";
		cout<<"1.Enter the postfix version\n2.Inorder(recursive)\n3.Postorder(recursive)\n4.Preorder(recursive)\n5.Inorder(Non-recursive)\n6.Postorder(Non-recursive)\n7.Preorder(Non-recursive)\n8.Exit";
		cout<<"\n\nEnter your choice: ";
		cin>>ch;
		switch(ch) {
			case 1:
				cout<<"Enter postfix string:- ";
				cin>>postfix;
				break;
			case 2:
				cout<<"Inorder Traversal: ";
				exptree = et.createTree(postfix);
				et.inorder(exptree);
				cout<<"\n\n";
				break;
			case 3:
				cout<<"\n\n Post Order traversal: ";
				et.postorder(exptree);
				cout<<"\n\n";
				break;
			case 4:
				cout<<"\n\n Pre Order traversal: ";
				et.preorder(exptree);
				cout<<"\n\n";
				break;
			case 5:
				cout<<"Iterative Inorder traversal: ";
				et.NinOrder(exptree);
				cout<<"\n\n";
				break;
			case 6:
				cout<<"Iterative Post order traversal: ";
				et.NpostOrder(exptree);
				cout<<"\n\n";
				break;
			case 7:

				break;
			case 8:
				f=0;

		}
	}


}

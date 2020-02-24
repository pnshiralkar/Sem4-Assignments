#include <iostream>

using namespace std;

class Node{
public:
	int val;
	Node *left, *right;
};

class DuplicateValueExc{};

class BST{
	Node *root;
public:
	BST(){
		root = NULL;
	}
	
	void insert(int n)
	{
		Node *node = new Node, *curr=root;
		node->val = n;
		node->left = NULL;
		node->right = NULL;
		if(root){
			while(curr)
			{
				if(n < curr->val){
					if(curr->left)
						curr = curr->left;
					else{
						curr->left = node;
						break;
					}
				}else if(n > curr->val){
					if(curr->right)
						curr = curr->right;
					else{
						curr->right = node;
						break;
					}
				}else{
					throw DuplicateValueExc();
					break;
				}
			}
		}else
			root = node;
	}
	
	void disp()
	{
		disp(root);
		cout << endl;
	}
	
	void disp(Node *curr)
	{
		if(curr){
			disp(curr->left);
			cout << curr->val << " ";
			disp(curr->right);
		}
	}
	
	bool search(int n)
	{
		Node *curr = root;
		while(curr){
			
		}
	}
};

int main()
{
	BST bst;
	bst.insert(2);
	bst.insert(4);
	bst.insert(3);
	bst.disp();
	return 0;
}

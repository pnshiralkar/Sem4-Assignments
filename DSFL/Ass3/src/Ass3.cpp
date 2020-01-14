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
	Node<T> *head = NULL;
	Node<T> *h;
public:
	void create()
	{
		head = createRec("root node");
	}

	Node<T>* createRec(string name)
	{
		Node<T> *root = new Node<T>;
		int res;
		cout << "Enter data for the node (" << name << ") : "; cin >> root->val;
		cout << "This Node has ? (1. Both nodes , 2. Only left , 3. Only Right , 4. No child nodes) : "; cin >> res;
		if(res==4){
			root->left = NULL;
			root->right = NULL;
		}
		if(res==2){
			root->right = NULL;
			root->left = createRec("left child of " + to_string(root->val));
		}
		if(res==3){
			root->left = NULL;
			root->right = createRec("right child of " + to_string(root->val));
		}
		if(res==1){
			root->left = createRec("left child of " + to_string(root->val));
			root->right = createRec("right child of " + to_string(root->val));
		}
		return root;
	}
	
	
	void dispPreorder()
	{
	    prerec(head);
	}
	
	void prerec(Node<T> *curr)
	{
	    if(curr)
	    {
	        cout << curr->val << " ";
	        prerec(curr->left);
	        prerec(curr->right);
	    }
	}

	int countLeaf()
	{
		return clrec(head);
	}

	int clrec(Node<T> *curr)
	{
		if(!curr)
		return 0;
		if(curr->left==NULL && curr->right==NULL)
		{
		return 1;
		}
		return (clrec(curr->left) + clrec(curr->right));
	}

	void dispLeaf()
	{
		dlrec(head);
	}

	void dlrec(Node<T> *curr)
	{
		if(!curr)
		return;
		if(!(curr->left || curr->right)){
			cout << curr->val << " ";
			return;
		}
		dlrec(curr->left);
		dlrec(curr->right);
	}

	Node<T>* copy(Node<T> *curr)
	{
		if(!curr)
			return NULL;
		Node<T> *newNode = new Node<T>;
		newNode->val = curr->val;
		newNode->left = copy(curr->left);
		newNode->right = copy(curr->right);
		return newNode;
	}
	
	void abc()
	{
		h = copy(head);
		prerec(h);
	}
	
};

int main() {
	BinTree<int> bt,bt2;
	bt.create();
	bt.dispPreorder();
	cout << "\n\n Leaf nodes : " << bt.countLeaf() << endl;
	bt.dispLeaf();

	cout << "Copied tree : ";
	bt.abc();

	return 0;
}
//23254: Binary Tree Operations [ Count leaf nodes, Make a copy of a tree ]
// 50 1 30 1 20 3 25 4 10 4 60 2 55 4
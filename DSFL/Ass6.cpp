//============================================================================
// Name        : Ass6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef struct _{
	int date, month, year;
} Dob;

class Node;

class friendNode{
public:
	Node *user;
	friendNode *nxt;
};

class Node{
public:
    int pk;
	string name;
	Dob dob;
	int comments;
	friendNode *lnk;
	Node *nxt;

	Node(){
	    pk=0;
		name="";
		dob.date = 0;
		dob.month = 0;
		dob.year = 0;
		comments = 0;
		lnk = NULL;
		nxt = NULL;
	}
	Node(int pk, string name, Dob dob, int comments){
		this->pk=pk;
		this->name=name;
		this->dob = dob;
		this->comments = comments;
		lnk = NULL;
		nxt = NULL;
	}
};

class Facebook{
	Node *head, *tail;
	int max=1;

public:
    Facebook(){
        head = NULL;
        tail = NULL;
    }
	void addUser(string name, Dob dob, int comments){
	    Node *n = new Node(max++, name, dob, comments);
	    if(!head){
	        head = n;
	        tail = n;
	    }
	    else{
	        tail->nxt = n;
	        tail=tail->nxt;
	    }
	}

	Node* search(int pk){
	    for(Node *i = head ; i ; i=i->nxt)
	        if(i->pk == pk)
	            return i;
	    return NULL;
	}

	void beFriend(int pk1, int pk2){
	    Node *n1 = search(pk1), *n2 = search(pk2);
	    friendNode *fn1 = new friendNode, *fn2 = new friendNode, *i;
	    fn1->user = n2;
	    fn1->nxt = NULL;
	    fn2->user = n1;
	    fn1->nxt = NULL;
	    if(n1 && n2){
	        if(n1->lnk){
    	        for(i=n1->lnk;i->nxt;i=i->nxt);
    	        i->nxt = fn1;
	        }
	        else
	            n1->lnk = fn1;

	        if(n2->lnk){
    	        for(i=n2->lnk;i->nxt;i=i->nxt);
    	        i->nxt = fn2;
	        }
	        else
	            n2->lnk = fn2;
	    }
	    else if(!n1)
	        cout << "Invalid User1";
	    else if(!n2)
	        cout << "Invalid User2";
	}

	void disp()
	{
	    for(Node *i=head ; i ; i=i->nxt)
	    {
	        cout << i->name << " : ";
	        for(friendNode *j=i->lnk; j ; j=j->nxt)
	            cout << j->user->name << " ";
	        cout << endl;
	    }
	}

	Node maxFriends()
	{
	    int max=0;
	    Node *maxn;
	    for(Node *i=head ; i ; i=i->nxt)
	    {
	        int c=0;
	        for(friendNode *j=i->lnk; j ; j=j->nxt)
	            c++;
	        if(max < c){
	            max=c;
	            maxn = i;
	        }
	    }
	    return *maxn;
	}
};

int main() {
    Facebook fb;

    Node *user;
    Dob dob;
    dob.date = 4;
    dob.month = 12;
    dob.year = 1999;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        fb.addUser("User" + to_string(i), dob, 3);
    fb.beFriend(1, 2);
    fb.beFriend(1, 3);
    fb.disp();
    cout << fb.maxFriends().name << " has maximum friends\n";
	return 0;
}

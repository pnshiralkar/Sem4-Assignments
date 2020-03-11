//============================================================================
// Name        : Ass6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <stack>
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
	bool visited;

	Node(){
	    pk=0;
		name="";
		dob.date = 0;
		dob.month = 0;
		dob.year = 0;
		comments = 0;
		lnk = NULL;
		nxt = NULL;
		visited = false;
	}
	Node(int pk, string name, Dob dob, int comments){
		this->pk=pk;
		this->name=name;
		this->dob = dob;
		this->comments = comments;
		lnk = NULL;
		nxt = NULL;
		visited = false;
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
	
	void resetVisited()
	{
		for(Node *i=head;i;i=i->nxt)
			i->visited = false;
	}
	
	Node maxComments(){
	    int maxn=0;
	    queue<Node *> q;
	    Node *max;
	    q.push(head);
	    head->visited = true;
	    while(!q.empty()){
	        Node *c = q.front();
	        friendNode *i=c->lnk;
	        q.pop();
	        while(i){
	        	if(!(i->user->visited)){
			        q.push(i->user);
			        i->user->visited = true;
	            }
		        i=i->nxt;
	        }
	        if(c->comments > maxn){
	            maxn = c->comments;
	            max = c;
	        }
	    }
	    resetVisited();
	    return *max;
	}
	
	void bdInMonth(int month)
	{
	    stack<Node *> q;
	    q.push(head);
	    head->visited = true;
	    while(!q.empty()){
	        Node *c = q.top();
	        friendNode *i=c->lnk;
	        q.pop();
	        while(i){
	        	if(!(i->user->visited)){
			        q.push(i->user);
			        i->user->visited = true;
	            }
		        i=i->nxt;
	        }
	        if(c->dob.month == month){
	            cout << c->name << endl;
	        }
	    }
	    resetVisited();
	}
};

int menu()
{
	int r;
	cout << "\n\n***** Facebook *****\n\n\
    1. Create Account\n\
    2. See who's on Facebook\n\
    3. Add Friends\n\
    4. View Profile\n\
    5. Get user with max friends\n\
    6. Get user with max comments\n\
    7. Get users with birthdays in given month\n\
    8. Exit\n\
        Your Choice : ";
	cin>>r;
	return r;
}

int main() {
    Facebook fb;

    Node *user;
    Dob dob;
    
    switch(menu())
    {
    	
    }
//     dob.date = 4;
//     dob.month = 12;
//     dob.year = 1999;
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         fb.addUser("User" + to_string(i), dob, 3*i+!(i%2));
//     fb.beFriend(1, 2);
//     fb.beFriend(1, 3);
//     fb.disp();
//     cout << fb.maxFriends().name << " has maximum friends\n";
//     cout << fb.maxComments().name << " has maximum comments\n";
//     cout << "Birthdays in given month are : " << endl;
//     fb.bdInMonth(12);
 	return 0;
}

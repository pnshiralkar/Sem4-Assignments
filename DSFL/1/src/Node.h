/*
 * Node.h
 *
 *  Created on: 30-Dec-2019
 *      Author: dsflh-10
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>

using namespace std;

class Node{
	public:
	int val;
	Node *nxt;
};

class InvalidPosExc{};
class List{
	public:
	Node *head;
	List()
	{
		head = NULL;
	}
	 void insert(int val);
	 void insert(int pos, int val);
	 void del(int pos);
	friend ostream& operator <<(ostream& out, List ll);
	friend class Stack;
};



#endif

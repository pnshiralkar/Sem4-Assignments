/*
 * LinkedList.h
 *
 *  Created on: 23-Dec-2019
 *      Author: pict
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

using namespace std;

class Node{
	public:
	int val;
	Node *nxt;
};

class InvalidPosExc{};
class myLinkedList{
	Node *head;
	public:
	myLinkedList()
	{
		head = NULL;
	}
	void insert(int val);
	void insert(int pos, int val);
	void del(int pos);
	friend ostream& operator <<(ostream& out, myLinkedList ll);
	friend class Stack;
};

#include "LinkedList.cpp"

#endif /* LINKEDLIST_H_ */

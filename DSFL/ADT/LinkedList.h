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

template<class T>
class Node{
	public:
	T val;
	Node *nxt;
};

class InvalidPosExc{};

template <typename T1>
class myLinkedList{
	public:
	Node<T1> *head;
	myLinkedList()
	{
		head = NULL;
	}
	void insert(T1 val);
	void insert(int pos, T1 val);
	void del(int pos);
};

#endif /* LINKEDLIST_H_ */

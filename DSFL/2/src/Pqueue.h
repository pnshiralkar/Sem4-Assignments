/*
 * Pqueue.h
 *
 *  Created on: 13-Jan-2020
 *      Author: dsflh-10
 */

#ifndef PQUEUE_H_
#define PQUEUE_H_
#include<iostream>
using namespace std;
template <class T>
class Node {
	int data;
	Node *next
public:
	friend class Pqueue;
};
template <class T>
class Pqueue {
	Node<T> *front;
	Node<T> *Rear;
public:
	Pqueue();
	virtual ~Pqueue();
	void push(T);
	void pop();
	bool isempty();
	void display();

};

#endif /* PQUEUE_H_ */

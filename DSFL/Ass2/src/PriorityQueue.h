/*
 * PriorityQueue.h
 *
 *  Created on: 06-Jan-2020
 *      Author: dsflh-10
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_
#include "LinkedList.cpp"

template <class T>
class NodePQ{
public:
	T data;
	int priority;
	NodePQ(){}
	NodePQ(T data, int priority){
		this->data = data;
		this->priority = priority;
	}
	friend ostream& operator <<(ostream& out, NodePQ n){
		out << n.data;
		return out;
	}
};

template <class T>
class PriorityQueue {
	myLinkedList< NodePQ<T> > ll;
	int size=0;
public:
	PriorityQueue();
	int isEmpty();
	void enqueue(T data, int priority);
	T dequeue();
	T front();
	T rear();
	void disp();
};

#endif /* PRIORITYQUEUE_H_ */

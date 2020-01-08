/*
 * PriorityQueue.cpp
 *
 *  Created on: 06-Jan-2020
 *      Author: dsflh-10
 */

#include "PriorityQueue.h"

template <class T>
PriorityQueue<T>::PriorityQueue(){

}

template <class T>
void PriorityQueue<T>::enqueue(T data, int priority)
{
	int i=0;
	for(Node< NodePQ<T> > *t=ll.head;t && t->nxt;t=t->nxt)
	{
		if(priority <= t->val.priority){
			break;
		}
		i++;
	}
	if(ll.head && !(ll.head->nxt)){ // not going inside this.
		if(priority > ll.head->val.priority){
			ll.insert(1, NodePQ<T>(data, priority));
			return;
		}
	}
	ll.insert(i, NodePQ<T>(data, priority));
	size++;
}

template <class T>
T PriorityQueue<T>::dequeue()
{
	return ll.del(--size).data;
}

template <class T>
T PriorityQueue<T>::front()
{
	return ll.head->val.data;
}

template <class T>
T PriorityQueue<T>::rear()
{
	Node< NodePQ<T> > *t;
	for(t = ll.head;t && t->nxt;t=t->nxt);
	return t->val.data;
}

template <class T>
void PriorityQueue<T>::disp()
{
//	cout << ll.head->val.data;
	ll.display();
}

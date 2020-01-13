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
	for(Node< NodePQ<T> > *t=ll.head;t;t=t->nxt)
	{
		if(priority <= t->val.priority){
			break;
		}
		i++;
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
	ll.display();
}

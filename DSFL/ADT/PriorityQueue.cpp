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
		if(priority > t->val.priority && priority <= t->nxt->val.priority)
			break;
		i++;
	}
	if(ll.head && !(ll.head->nxt)){ // not going inside this.
		if(priority > ll.head->val.priority){
			ll.insert(1, NodePQ<T>(data, priority));
			cout<<"f";
			return;
		}
	}
	ll.insert(i, NodePQ<T>(data, priority));
}

template <class T>
void PriorityQueue<T>::disp()
{
//	cout << ll.head->val.data;
	ll.display();
}

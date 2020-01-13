/*
 * LinkedList.cpp
 *
 *  Created on: 23-Dec-2019
 *      Author: pict
 */

#include "LinkedList.h"


template <typename T1>
void myLinkedList<T1>::insert(T1 val)
{
	Node<T1> *n = new Node<T1>, *tmp=head;
	n->val = val;
	n->nxt=NULL;
	if(head)
	{
		while(tmp->nxt!=NULL)
			tmp=tmp->nxt;
		tmp->nxt = n;
	}
	else
		head=n;
}

template <typename T1>
void myLinkedList<T1>::insert(int pos, T1 val)
{
	if(!head && pos){
		throw InvalidPosExc();
		return;
	}
	Node<T1> *n = new Node<T1>, *tmp=head;
	n->val = val;
	if(!pos)
	{
		n->nxt = head;
		head = n;
		return;
	}
	int i=0;
	while(tmp!=NULL && i<pos-1){
		tmp=tmp->nxt;
		i++;
	}
	if(tmp==NULL && i<pos){
		throw InvalidPosExc();
		return;
	}
	n->nxt = tmp->nxt;
	tmp->nxt = n;
}

template <typename T1>
T1 myLinkedList<T1>::del(int pos)
{
	Node<T1> *tmp = head, *tmp1;
	if(!pos)
	{
		head=head->nxt;
		T1 data = tmp->val;
		delete tmp;
		return data;
	}
	int i=0;
	while(tmp!=NULL && i<pos-1){
		tmp=tmp->nxt;
		i++;
	}
	if((tmp==NULL && i<pos) || tmp->nxt==NULL){
		throw InvalidPosExc();
	}
	tmp1 = tmp;
	tmp=tmp->nxt;
	tmp1->nxt = tmp->nxt;

	T1 data = tmp->val;
	delete tmp;
	return data;
}

template <typename T1>
void myLinkedList<T1>::display()
{
	for(Node<T1> *tmp = head;tmp!=NULL;tmp=tmp->nxt)
		cout << tmp->val;
}






//template class myLinkedList<int>;
template class myLinkedList<char>;
template class myLinkedList<float>;
template class myLinkedList<double>;
template class myLinkedList<string>;

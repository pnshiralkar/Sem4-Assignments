/*
 * Node.cpp
 *
 *  Created on: 30-Dec-2019
 *      Author: dsflh-10
 */

#include "Node.h"
#include<iostream>

void List::insert(int val)
{
	Node *n = new Node, *tmp=head;
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

void List::insert(int pos, int val)
{
	if(!head && pos){
		throw InvalidPosExc();
	}
	Node *n = new Node, *tmp=head;
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

void List::del(int pos)
{
	Node *tmp = head, *tmp1;
	if(!pos)
	{
		head=head->nxt;
		delete tmp;
		return;

	}
	int i=0;
	while(tmp!=NULL && i<pos-1){
		tmp=tmp->nxt;
		i++;
	}
	if((tmp==NULL && i<pos) || tmp->nxt==NULL){
		throw InvalidPosExc();
		return;
	}
	tmp1 = tmp;
	tmp=tmp->nxt;
	tmp1->nxt = tmp->nxt;
	delete tmp;
}


ostream& operator <<(ostream& out, List ll)
{
	for(Node *tmp = ll.head;tmp!=NULL;tmp=tmp->nxt)
		out << tmp->val << " ";
	return out;
}

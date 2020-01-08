/*
 * linkedList.cpp
 *
 *  Created on: 06-Jan-2020
 *      Author: dsflh-10
 */

#include "linkedList.h"
#include<iostream>

void List::insert(int p,int val)
{
	linkedList *n = new linkedList;
	n->val = val;
	n->priority = p;
	n->nxt = NULL;

	if(head->priority >p)
	{
		n->nxt = head;
		head = n;

	}
	else
	{
		while(head->nxt != NULL && head->nxt->priority <p) {

			head = head->nxt;
		}

		 n->nxt = head->nxt;
		 head->nxt = n;
	}
}

int List::del()
{
	linkedList *n,*m;
	m = head;
	n = head;
	head = head->nxt;
	delete(n);
	return (m->val);

}

void List::insert(int val) {
	linkedList *n = new linkedList, *tmp=head;
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

int List:: peek() {

	return (head->val);
}
int List::isEmpty()
{
    return (head == NULL);
}

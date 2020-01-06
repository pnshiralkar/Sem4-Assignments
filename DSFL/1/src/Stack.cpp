/*
 * Stack.cpp
 *
 *  Created on: 23-Dec-2019
 *      Author: pict
 */

#include "Stack.h"
#include "Node.cpp"
#include<iostream>
void Stack::push(int n)
{
	ll.insert(0,n);
}

bool Stack::isEmpty()
{
	return ll.head == NULL;
}

int Stack::pop()
{
	if(isEmpty())
		throw StackunderflowExc();
	int n = ll.head->val;
	ll.del(0);
	return n;
}

int Stack::top()
{
	if(isEmpty())
		throw StackunderflowExc();
	return ll.head->val;
}

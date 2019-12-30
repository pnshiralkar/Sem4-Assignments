/*
 * Stack.cpp
 *
 *  Created on: 23-Dec-2019
 *      Author: pict
 */

#include "Stack.h"

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
		throw StackUnderflowExc();
	int n = ll.head->val;
	ll.del(0);
	return n;
}

int Stack::top()
{
	if(isEmpty())
		throw StackUnderflowExc();
	return ll.head->val;
}

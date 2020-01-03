/*
 * Stack.cpp
 *
 *  Created on: 23-Dec-2019
 *      Author: pict
 */

#include "Stack.h"

template <class T>
void Stack<T>::push(T n)
{
	ll.insert(0,n);
}

template <class T>
bool Stack<T>::isEmpty()
{
	return ll.head == NULL;
}

template <class T>
T Stack<T>::pop()
{
	if(isEmpty())
		throw StackUnderflowExc();
	T n = ll.head->val;
	ll.del(0);
	return n;
}

template <class T>
T Stack<T>::top()
{
	if(isEmpty())
		throw StackUnderflowExc();
	return ll.head->val;
}

template class Stack<int>;
template class Stack<char>;

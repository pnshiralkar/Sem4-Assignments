/*
 * Stack.h
 *
 *  Created on: 23-Dec-2019
 *      Author: pict
 */

#ifndef STACK_H_
#define STACK_H_

#include "LinkedList.h"

class StackUnderflowExc{};

template <class T>
class Stack {
	myLinkedList<T> ll;
public:
	void push(T);
	T pop();
	T top();
	bool isEmpty();
};

#endif /* STACK_H_ */

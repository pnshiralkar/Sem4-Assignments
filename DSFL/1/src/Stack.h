/*
 * Stack.h
 *
 *  Created on: 23-Dec-2019
 *      Author: pict
 */

#ifndef STACK_H_
#define STACK_H_

#include "Node.h"

class StackunderflowExc{};
class Stack {
	List ll;
public:
	void push(int);
	int pop();
	int top();
	bool isEmpty();
};


#include "Stack.cpp"

#endif /* STACK_H_ */

/*
 * Queue.h
 *
 *  Created on: 08-Jan-2020
 *      Author: dsflh-10
 */

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
	List ll;
public:
	Queue();
	virtual ~Queue();
	void push(int p,int d);
	void pop();
	void display();
};

#endif /* QUEUE_H_ */

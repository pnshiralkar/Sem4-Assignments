/*
 * linkedList.h
 *
 *  Created on: 06-Jan-2020
 *      Author: dsflh-10
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include<iostream>

class linkedList {
public:
	int val;
	int priority;
	linkedList *nxt;
	char name[25];
	int age;

friend class List;

};


class InvalidPosExc{};

class List{
	public:
	linkedList *head;
	List()
	{
		head = NULL;
	}
	 void insert(int val);
	 void insert(int priority, int val);
	 int del();
	 void display();
	 int peek();
	 int isEmpty();
	friend class Queue;
};


#endif /* LINKEDLIST_H_ */

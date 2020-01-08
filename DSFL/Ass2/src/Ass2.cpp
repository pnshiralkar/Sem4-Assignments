//============================================================================
// Name        : Ass2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "PriorityQueue.cpp"
using namespace std;

class Record{
public:
	string name;
	int age;
	string severity;
	void inp(){

	}
};

int menu()
{
	int rs;
	cout << "***Patient Serving***\n\n1. Enter patient\n2. Display all patients\n3. Service patients\n4. Exit\n    Your response : ";
	cin >> rs;
	return rs;
}

int main() {
	PriorityQueue<int> pq;
	Record p;
	while(1)
	{
		switch(menu())
		{
		case 1:
			cout << "Enter details : " << endl;

			break;
		case 2:

			break;
		case 3:

			break;
		default:
			cout<<"bye"<<endl;
			return 0;
		}
	}
//	pq.enqueue(12, 2);
//	pq.enqueue(13, 1);
//	pq.enqueue(14, 0);
//	pq.enqueue(15, 2);
//	pq.dequeue();
//	pq.enqueue(100, 0);
//	pq.disp();
//	cout<<"\nFront : " << pq.front() << endl;
//	cout<<"Rear : " << pq.rear() << endl;
//	cout<<"Dequeue : "<<pq.dequeue()<<endl;
//	cout<<"Dequeue : "<<pq.dequeue()<<endl;
//	pq.disp();
//	cout<<"Dequeue : "<<pq.dequeue()<<endl;
//	pq.disp();
//	cout<<"Dequeue : "<<pq.dequeue()<<endl;
//	pq.disp();
//	pq.enqueue(15, 2);
//	pq.disp();
	return 0;
}

//============================================================================
// Name        : 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Pqueue.h"
#inlcude "Pqueue.cpp"
using namespace std;

class Hospital {
	string name;
	string disease;
	string bloodgroup;

	Pqueue<Hospital> P;
public:
	void add();

};

int main() {

	return 0;
}

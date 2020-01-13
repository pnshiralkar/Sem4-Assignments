//============================================================================
// Name        : Ass2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include "PriorityQueue.cpp"
using namespace std;

class Record{
public:
	string name;
	int age;
	string disease;
	friend ostream& operator << (ostream& out, Record r)
	{
		out << setw(12) << r.name << "\t" << setw(3) << r.age << "\t" << r.disease << endl;
		return out;
	}
};

int menu()
{
	int rs;
	cout << "\n\n***Patient Serving***\n\n1. Enter patient\n2. Display all patients\n3. Service patients\n4. Exit\n    Your response : ";
	cin >> rs;
	return rs;
}

int priority(Record p)
{
	if(p.disease == "cancer" || p.disease == "accident" || p.disease == "heart attack")
		return 3;
	if(p.disease == "jaundice" || p.disease == "typhoid")
		return 2;
	return 1;
}

int main() {
	PriorityQueue<Record> pq;
	Record p;
	while(1)
	{
		switch(menu())
		{
		case 1:
			cout << "\nEnter patient details :\n    Name : "; cin >> p.name;
			cout << "    Age : "; cin >> p.age;
			cout << "    Disease : "; cin >> p.disease;
			pq.enqueue(p, priority(p));
			cout << "Record inserted successfully.";
			break;
		case 2:
			cout << "Patient name\tAge\tDisease\n";
			pq.disp();
			break;
		case 3:
			cout << "patient to be serviced is : \n" << pq.dequeue();
			break;
		default:
			cout<<"bye"<<endl;
			return 0;
		}
	}
	return 0;
}

/*
***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 1

Enter patient details :
    Name : vrgre
    Age : 432
    Disease : typhoid
Record inserted successfully.

***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 1

Enter patient details :
    Name : fvsegs
    Age : 32
    Disease : fever
Record inserted successfully.

***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 1

Enter patient details :
    Name : dwef
    Age : 32
    Disease : cancer
Record inserted successfully.

***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 2
Patient name	Age	Disease
      fvsegs	 32	fever
       vrgre	432	typhoid
        dwef	 32	cancer


***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 1

Enter patient details :
    Name : vrg
    Age : 22
    Disease : accident
Record inserted successfully.

***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 1

Enter patient details :
    Name : vreg
    Age : 45
    Disease : cough
Record inserted successfully.

***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 2
Patient name	Age	Disease
        vreg	 45	cough
      fvsegs	 32	fever
       vrgre	432	typhoid
         vrg	 22	accident
        dwef	 32	cancer


***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 3
patient to be serviced is :
        dwef	 32	cancer


***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 3
patient to be serviced is :
         vrg	 22	accident


***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 3
patient to be serviced is :
       vrgre	432	typhoid


***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 3
patient to be serviced is :
      fvsegs	 32	fever


***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 3
patient to be serviced is :
        vreg	 45	cough


***Patient Serving***

1. Enter patient
2. Display all patients
3. Service patients
4. Exit
    Your response : 4
bye
*/

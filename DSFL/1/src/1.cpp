#include<bits/stdc++.h>
#include "Stack.h"
#include "Node.h"
using namespace std;

int prec(char c)
{
    if(c == '^')
    	return 3;

    else if(c == '*' || c == '/')
    	return 2;

    else if(c == '+' || c == '-')
    	return 1;

    else
    	return -1;
}

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}


int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixToPostfix(string s)
{
    Stack st;
    st.push('N');
    int l = s.length();
    string ns;
    for(int i = 0; i < l; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
        ns+=s[i];


        else if(s[i] == '(')
        	st.push('(');


        else if(s[i] == ')')
        {
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
               ns += c;
            }
            if(st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }

        else{
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }

    }

    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }
    return ns;

}
string infixToPrefix(string infix)
{

    int l = infix.size();


    reverse(infix.begin(), infix.end());


    for (int i = 0; i < l; i++) {

        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = infixToPostfix(infix);


    reverse(prefix.begin(), prefix.end());

    return prefix;
}



int main()
{
	Stack S;
	bool f = true;
	int ch;
	string s1,s2;
	int x;
	int y,z;
	while(f)
	{
		cout<<"\n\n1.Push\n2.Pop\n3.Top element\n4.Infix To postfix\n5.Infix to Prefix\n6.end";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the element you want to push:- ";
				cin>>x;
				S.push(x);
				break;
			case 2:
				cout<<"\nPoped Element: ";
				 y = S.pop();
				cout<<y<<endl;
				break;
			case 3:
				cout<<"\nTop Element:- ";
				 z= S.top();
				cout<<z<<endl;
				break;
			case 4:
				cout<<"\nEnter the expression: ";
				cin>>s1;
				cout <<"\n\n\n PostFix Version: "<<infixToPostfix(s1)<<endl;
				break;
			case 5:
				cout<<"\nEnter the expression: ";
				cin>>s2;
				cout<<"Infix Expression: "<<s2;
				cout<< "\n\n\nPrefix Version: " <<infixToPrefix(s2);

				break;
			case 6:
				f=false;

		}


	}
}

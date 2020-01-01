#include <bits/stdc++.h>
#include "Stack.h"

using namespace std;

int prec[128]={0};

string inToPost(string in, bool gte=true)
{
	char post[in.length()];
	Stack<int> st;
	int j=0;
	for(int i=0;i<in.length();i++)
	{
		if(('a' <= in[i] && in[i] <= 'z') || ('A' <= in[i] && in[i] <= 'Z') || ('0' <= in[i] && in[i] <= '9'))
		{
			post[j++] = in[i];
		}
		else if(in[i]==')')
		{
			try{
				while(st.top() != '(')
					post[j++] = st.pop();
				st.pop();
			}catch(...)
			{
				cout<<"Invalid expression" <<post;
			}

		}
		else
		{
			if(!st.isEmpty() && (prec[st.top()]>prec[in[i]] || (prec[st.top()]==prec[in[i]] && gte)) && st.top() != '(' && in[i] != '(')
				post[j++] = st.pop();
			st.push(in[i]);
		}
	}
	while(!st.isEmpty()){
		if(st.top()!='(')
			post[j++] = st.pop();
		else
			st.pop();
	}
	post[j]='\0';
	return post;
}

string inToPre(string in)
{
	reverse(in.begin(), in.end());
	for(int i=0;i<in.length();i++)
	{
		if(in[i]=='(')
			in[i]=')';
		else if(in[i]==')')
			in[i]='(';
	}
	string pre = inToPost(in, false);
	reverse(pre.begin(), pre.end());
	return pre;
}

int oper(int a, int b, char op)
{
	switch(op)
	{
	case '+':
		return a+b;
		break;
	case '-':
		return a-b;
		break;
	case '*':
		return a*b;
		break;
	case '/':
		return a/b;
		break;
	case '^':
		return a^b;
		break;
	}
}

int evalPost(string post)
{
	Stack<int> es;
	for(int i=0;i<post.length();i++)
	{
		if('0' <= post[i] && post[i] <= '9')
			es.push(post[i] - '0');
		else
			es.push(oper(es.pop(), es.pop(), post[i]));
	}
	return es.pop();
}

void initPrec()
{
	prec['+']=1;
	prec['-']=1;
	prec['*']=2;
	prec['/']=2;
	prec['^']=3;
}

int main()
{
	initPrec();
	string inp,post;
	cout << "Enter expression : ";
	cin >> inp;
	post = inToPost(inp);
	cout << "Postfix is : " << post << endl;
	cout << "Prefix is : " << inToPre(inp) << endl;


	if('0' <= post[0] && post[0] <= '9')
		cout << "Evaluation is : " << evalPost(post) << endl;

	return 0;
}

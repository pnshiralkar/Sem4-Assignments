#include <bits/stdc++.h>
#include "ADT/Stack.h"

using namespace std;

int prec[128]={0};

string inToPost(string in, bool gte=true)
{
	char post[in.length()];
	Stack st;
	int j=0;
	for(int i=0;i<in.length();i++)
	{
		if(('a' <= in[i] && in[i] <= 'z') || ('A' <= in[i] && in[i] <= 'Z'))
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
	string inp;
	cout << "Enter expression : ";
	cin >> inp;
	cout << "Postfix is : " << inToPost(inp) << endl;
	cout << "Prefix is : " << inToPre(inp) << endl;
	return 0;
}

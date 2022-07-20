#include<iostream>
using namespace std;
#define size 100

class stack
{
	public:
		int top=-1;
		char A[size];
	
	bool empty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
	
	char peek()
	{
		return A[top];
	}	
	
	char pop()
	{
		if(empty())
		{
			cout<<"Stack is Empty!";
		}
		else
		{
			top--;
		}
		return 0;
	}
	
	void push(char value)
	{
		if(top==size-1)
		{
			cout<<"Stack is full!";
		}
		else
		{
			top++;
			A[top]=value;
		}
	}
};

int precedence(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*'||c=='/')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else
		return -1;
}

string infixtopostfix(string s)
{
	stack st;
	string res;
	
	for(int i=0;i<s.length();i++)
	{
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
		{
			res+=s[i];
            cout<<"push:"<<s[i]<<endl;
		}
		else if(s[i]=='(')
		{
			st.push(s[i]);
            cout<<"push:"<<s[i]<<endl;
		}
		else if(s[i]==')')
		{
			while(!st.empty()&&st.peek()!='(')
			{
				res+=st.peek();
                cout<<"pop"<<st.peek()<<endl;
				st.pop();
			}
			if(!st.empty())
			{
                cout<<"pop"<<st.peek()<<endl;
				st.pop();
			}
		}
		else
		{
			while(!st.empty() && precedence(st.peek())>=precedence(s[i]))
			{
				res+=st.peek();
                cout<<"pop"<<st.peek()<<endl;
				st.pop();
			}
			st.push(s[i]);
            cout<<"push:"<<s[i]<<endl;
		}
	}
	while(!st.empty())
	{
		res+=st.peek();
        cout<<"pop"<<st.peek()<<endl;
		st.pop();
	}
	return res;
}

int main()
{
	string str;
	cout<<"Enter String: ";
	cin>>str;
	cout<<"Infix to postfix conversion: "<<infixtopostfix(str);
	return 0;
}

	
			
	
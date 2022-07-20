#include<iostream>
using namespace std;
#define size 100
class stack
{
    public: 
        char A[size];
        int top=-1;
    
    bool empty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
    bool isfull()
    {
        if(top==size-1)
            return true;
        else
            return false;
    }
    void push(char value)
    {
        if(isfull())
        {
            cout<<"Stack is Full!";
        }
        else
        {
            top++;
            A[top]=value;
        }
    }
    char pop()
    {
        char c;
        if(empty())
        {
            cout<<"Stack is Empty!";
        }
        else
        {
            c=A[top];
            top--;
        }
        return c;
    }
};

string reverse(string s)
{
    stack st;
    string res;

    for(int i=0;i<s.length();i++)
    {
        st.push(s[i]);
    }

    for(int i=0;i<s.length();i++)
    {
        res+=st.pop();
    }
    return res;
}

int main()
{
    string str;
    cout<<"Enter String: ";
    cin>>str;
    cout<<"Reversed String: "<<reverse(str);
    return 0;
}
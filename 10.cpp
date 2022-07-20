#include<iostream>
using namespace std;

void print(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<":";
        if(a[i]!=-1)
        cout<<a[i];
        cout<<endl;
    }
}

void QP(int ele, int hash[], int n)
{
    int i=0;
    int hash_val=ele%n;
    cout<<"Hash Value: "<<ele<<" % "<<n<<":"<<hash_val<<endl;
    while(hash[hash_val+(i*i)%n]!=-1)
    {
        cout<<"Collision it at index: "<<hash_val+(i*i)%n<<endl;
        i++;
        cout<<"New Hash value ("<<hash_val<<"+"<<i<<"^2)"<<"%"<<n<<":"<<hash_val+(i*i)%n<<endl;
    }
    cout<<"Element inserted at position: "<<hash_val+(i*i)%n<<endl;
    hash[hash_val+(i*i)%n]=ele;
    print(hash,n);
}

int main()
{
    int ele,n;
    cout<<"Enter Size:";
    cin>>n;
    int h1[n];
    for(int i=0;i<n;i++)
    {
        h1[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Element: ";
        cin>>ele;
        QP(ele,h1,n);
    }
    return 0;
}
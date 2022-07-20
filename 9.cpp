#include<iostream>
using namespace std;

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<":";
        if(a[i]!=-1)
        cout<<a[i];
        cout<<endl;
    }
}

void linearprobing(int ele, int hash[], int n)
{
    int hash_val=ele%n;
    int i=0;
    cout<<"\nHash Value "<<ele<<"%"<<n<<" : "<<hash_val<<endl;
    while (hash[(hash_val+i)%n]!=-1)
    {
        cout<<"Collision at index: "<<(hash_val+i)%n<<endl;
        i++;
        cout<<"New Hash Value("<<hash_val<<"+"<<i<<") %"<<(hash_val+i)%n<<endl;
    }
    cout<<"Element inserted into position: "<<(hash_val+i)%n<<endl;
    hash[(hash_val+i)%n]=ele;
    print(hash,n);
}

int main()
{
    int n,ele;
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
        linearprobing(ele,h1,n);
    }
    return 0;
}
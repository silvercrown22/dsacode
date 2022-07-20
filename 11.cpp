#include <iostream>
#include <vector>
using namespace std;
 
void swap(vector<int> &a, int i, int j)
{
    int temp =a[i];
    a[i]=a[j];
    a[j]=temp;                
}

void printArr(vector<int> &a, int n)
{
    cout<<endl;
    for(int i: a)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void shiftUp(vector<int> &a, int n)
{
    if(n==1)
    {
        cout<<a[n-1]<<endl;
        return;
    }
    int curr = n-1;
    int parent = (curr-1)/2;
    while(a[parent] > a[curr])
    {
        cout<<"\nShift Up "<<a[curr]<<" --> "<<a[parent];
        swap(a, parent, curr);
        curr=parent;
        parent=(parent-1)/2;
    }
    printArr(a, n);
}

void heapify(vector<int> &arr, int n, int i)
{
    int smallest = i; // Largest as root
    int l = 2 * i + 1;
    int r = 2 * i + 2;
   
    // If left child is larger than root
    if (l < n && arr[l] < arr[smallest])
    smallest = l;
   
    // If right child is larger than smallest so far
    if (r < n && arr[r] < arr[smallest])
    smallest = r;
   
    // If smallest is not root
    if (smallest != i)
    {
        cout<<"\nSwap in heapify: "<<arr[i]<<" -- "<<arr[smallest]<<endl;
        swap(arr[i], arr[smallest]);
        printArr(arr, sizeof(arr));
        heapify(arr, n, smallest);
    }
}

void heapSort(vector<int> &a, int n)
{
    cout<<"\nSorting in Ascending Order: "<<endl;
    for (int i = n - 1; i >=0; i--)
    {
        cout<<"\n---------------------------"<<endl;
        cout<<"Swapping "<<a[0]<<" to index "<<i;
        // Move current root to end
        swap(a[0], a[i]);
        printArr(a,n);
        // call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}  
 
int main()
{
    bool ch=1;
    int ele;
    vector<int> arr;
    int n=0;
    while(ch)
    {
        cout<<"Enter Element: ";
        cin>>ele;
        arr.push_back(ele);
        n++;
        printArr(arr, n);
        shiftUp(arr, n);
        cout<<"\nContinue? (0/1): ";
        cin>>ch;
    }
    heapSort(arr, n);
    cout<<"\nFinal Sorted Array: "<<endl;
    for(int i: arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

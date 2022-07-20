#include<iostream>
using namespace std;
int k;
class kQueues
{
    int div,*arr,*rear,*front;
    public:
            kQueues(int k, int n)
            {
                arr = new int[n];
    	        front = new int[k];
            	rear = new int[k];
                div=n/k;
                int t=0;
                for(int i =0;(i<n)&&(t<k);i+=div)
                {
                    rear[t] = i;
                    front[t] = i;
                    t++;
                }
            }
            void enqueue(int x, int qn)
            {
                if(isfull(qn))
                {
                    cout<<"Queue "<<qn<<" is full, Element can't be inserted\n";
                }
                else
                {
                    rear[qn-1]++;
                    arr[rear[qn-1]] = x;
                    cout<<"Insereting "<<x<<" into queue no: "<<qn;
                }
            }
            void dequeue(int qn)
            {
                if(isempty(qn))
                {
                    cout<<"Queue "<<qn<<" is Empty\n";
                }
                else
                front[qn-1]++;
            }
            void displayq(int qn)
            {
                if(isempty(qn))
                {
                    cout<<"Queue "<<qn<<" is Empty\n";
                }
                else
                {
                    cout<<"Queue "<<qn<<": ";
                    for(int i = front[qn-1]+1; i <= rear[qn-1];i++)
                    {
                        cout<<arr[i]<<" ";
                    }
                    cout<<"\n";
                }
            }
            void displayAll( )
            {
                for(int i = 0;i<k;i++)
                {
                    cout<<"Queue "<<i+1<<": ";
                    for(int j = front[i]+1;j <= rear[i];j++)
                    {
                        cout<<arr[j]<<" ";
                    }
                    cout<<"|";
                }
            }     
            bool isfull(int qn)
            {
                if(rear[(qn-1)] == ((div*qn)))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            bool isempty(int qn)
            {
                if(front[qn-1]==rear[qn-1])
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
};
int main()
{
    int n,qn,ch,x;
    cout<<"Enter the size of queue: ";
    cin>>n;
    cout<<"Enter how many divisions: ";
    cin>>k;
    if(n<=k)
    {
        cout<<"Divisions should be less than queue size";
        return 0;
    }
    else
    {
        kQueues ks(k,n);
        while(true)
        {
            cout<<"\n 1.Enqueue\n 2.Dequeue\n 3.displayq\n 4.displayAll\n 5.Exit\n";
            cout<<"Enter choice: ";
            cin>>ch;
            switch (ch)
            {
            case 1:
                cout<<"Enter Qno: ";
                cin>>qn;
                cout<<"Enter element: ";
                cin>>x;
                ks.enqueue(x,qn);
                break;
            case 2:
                cout<<"Enter Qno: ";
                cin>>qn;
                ks.dequeue(qn);
                break;
            case 3:
                cout<<"Enter Qno: ";
                cin>>qn;
                ks.displayq(qn);
                break;
            case 4:
                cout<<"All Queues: \n";
                ks.displayAll();
                break;
            case 5:
                exit(1);
                break;
            default:
                cout<<"Enter valid choice";
            }
        }
    }
}
#include <iostream>
#include<stack>
using namespace std;
//Doubly linked list Node
class Node
{
    public:
            int data;
            Node *prev;
            Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};
//Insertion in Doubly Linked List at Beginning
void insertAtHead(Node* &Head, Node* &Tail, int data, int &len)
{
    if (Tail == NULL)
    {
        Node* temp = new Node(data);
        Tail = temp;
        Head = temp;
    }
    else
    {
        Node* new_node = new Node(data);
        Node* temp1=Head;
          
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=new_node;
        new_node->prev=temp1;
        }
}

void reverse(Node *Head)
    {
        stack<int> st;
        Node* temp = Head;
        while (temp != NULL) {
            st.push(temp->data);
            temp = temp->next;
        }
  
        // added all the elements sequence wise in the
        // st
        temp = Head;
        while (temp != NULL) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
  
        // popped all the elements and the added in the
        // linked list,
        // which are in the reversed order->
    }
//Function to display
void display(Node *temp)
{
    cout<<"\nNULL <--> ";

    while(temp!=NULL)
    {
        cout<<temp->data<<" <--> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//Function to swap
void swap(Node* &i, Node* &j)
{
    int t=i->data;
    i->data=j->data;
    j->data=t;
}
//Function for selection sort
void sort(Node* &Head)
{
    if(Head->next==NULL)
    {
        return;
    }
    Node* i_temp=Head;
    Node* j_temp;
    while(i_temp->next!=NULL)
    {
        j_temp = i_temp->next;
        while(j_temp!=NULL)
        {
            if(i_temp->data > j_temp->data)
            swap(i_temp, j_temp);
            j_temp=j_temp->next;
        }
        i_temp=i_temp->next;
    }
    cout<<"\nSorted List: ";
    display(Head);
}
//Function to deleteNode
void deleteNode(Node* &Head,Node* &del)
{
   if (Head == NULL || del == NULL)
   {
      return;
   }
   if (Head == del)
   {
       Head = del->next;
   }
   if (del->next != NULL)
   {
      del->next->prev = del->prev;
   }
   if (del->prev != NULL)
   {
      del->prev->next = del->next;
   }
   free(del);
}
void deleteatpos(Node* &Head, int &len, int pos)
{
    if (Head == NULL || pos <= 0)
    {
      return;
    }
    if(pos>len)
    {
        cout<<"\nEnter Valid position";
    }
    else
    {

        Node* current=Head;
        int i;
        for (int i = 1; current != NULL && i < pos; i++)
        {
          current = current->next;
        }
        if (current == NULL)
        {
          return;
        }
        deleteNode(Head, current);
        len--;
    }
}

int main()
{
    Node *Head=NULL;
    Node *Tail=NULL;
    int len=1,ele,ch,n,pos;
    cout<<"\nEnter Number of elements: ";
    cin>>n;
    for(int i=0; i<n;i++)
    {
        cin>>ele;
        insertAtHead(Head,Tail,ele,len);
    }
    if(Tail==NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        cout<<"\nData Inserted"<<endl;
        display(Head);
        do
        {
            cout<<"\nEnter Your Choice: "
            <<"\n1. Insert An element"
            <<"\n2. Show Length of list"
            <<"\n3. Sort list"
            <<"\n4. Deletion "
            <<"\n0. Exit "<<endl;
            cin>>ch;
            switch(ch)
            {
                case 1:
                        cout<<"\nEnter an element : ";
                        cin>>ele;
                        insertAtHead(Head,Tail,ele,len);
                        display(Head);
                        sort(Head);
                        cout<<"\nLength : "<<len<<endl;
                        break;
                case 2:
                        reverse(Head);
                        display(Head);
                        break;
                case 3:
                        sort(Head);
                        break;
                case 4:
                        cout<<"\nEnter position of element to be deleted:";
                        cin>>pos;
                        deleteatpos(Head,len,pos);
                        display(Head);
                        sort(Head);
                        cout<<"\nLength : "<<len<<endl;
                        break;
                case 0: break;
                default:
                        cout<<"\nIncorrect Option..";
            }
        }while(ch!=0);
    }
    return 0;
}


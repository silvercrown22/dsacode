    #include <iostream>
    using namespace std;
    class Node
    {
        public:
            char data;
            Node *next;
    }; //Linked List Node
    Node* createNode(char ch) // to add node in linkedist
    {
        Node* temp = new Node();
        temp->data = ch;
        temp->next = NULL;
        return temp;
    }
    Node* string_to_linklist(string s, Node* head)//convert string to linkedlist
    {
        head = createNode(s[0]);
        Node* current = head;
        for (int i = 1; i < s.size(); i++)
        {
            current->next = createNode(s[i]);
            current = current->next;
        }
        return head;
    }
    void display(Node* head)//display the list
    {
        Node* current = head;
        while (current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
    }
    Node* reverse_linklist(Node* head)// Reverse the linkedlist
    {
            if (head == NULL || head->next == NULL)
            {
                return head;
            }
            Node* rest = reverse_linklist(head->next);
            head->next->next = head;
            head->next = NULL;
            return rest;
    }
    void split(Node *head, int mid, int n)//Divide the linkedlist
    {
    Node *temp;
    temp = head;
    while (mid > 1)
    {
        temp = temp->next;
        mid -= 1;
    }
    Node *head2 = temp->next;
    temp->next = NULL;
    
    cout<<"List 1:";
    display(head);
    cout << endl;
    cout<<"List 2:";
    display(head2);
    cout << endl;
    head2=reverse_linklist(head2);
    cout<<"Reverse List 2:";
    display(head2);
    
    Node *t1, *t2;
        t1 = head;
        t2 = head2;
        bool flag = 1;
        for(int i=0;i<n/2; i++)
        {
            if(t1->data != t2->data)
            {
                flag = 0;
                break;
            }
            t1=t1->next;
            t2=t2->next;
        }
        if(flag)
        {
            cout<<"\nGiven String is Palindrome"<<endl;
        }
        else
        {
            cout<<"\nGiven String is not a Palindrome"<<endl;
        }
    }
    int main()
    {
        string s;
        int mid,n;
        cout<<"Enter String: ";
        cin>>s;
        n=s.length();
        Node* head = NULL;
        head = string_to_linklist(s, head);
        mid=n/2;
        split(head, mid, n);
        return 0;
    }

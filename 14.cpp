#include <bits/stdc++.h>
using namespace std;
 
class Node
{
    public:
    int data;
    Node* next;
};

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
void removeDuplicates(Node* head)
{
    /* Pointer to store the pointer of a node to be deleted*/
    Node* to_free;
     
    /* do nothing if the list is empty */
    if (head == NULL)
        return;
 
    /* Traverse the list till last node */
    if (head->next != NULL)
    {
         
        /* Compare head node with next node */
        if (head->data == head->next->data)
        {
            /* The sequence of steps is important.
              to_free pointer stores the next of head
             pointer which is to be deleted.*/   
            to_free = head->next;
            head->next = head->next->next;
            free(to_free);
            removeDuplicates(head);
        }
        else /* This is tricky: only
        advance if no deletion */
        {
            removeDuplicates(head->next);
        }
    }
}
 
void insert(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
             
    /* put in the data */
    new_node->data = new_data;
                 
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
         
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node!=NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
    cout<<endl;
}
 
int main()
{
    Node* head = NULL;
     
    /* Let us create a sorted linked
    list to test the functions
    Created linked list will be
    11->11->11->13->13->20 */
  int choice,data;

    while (true)
    {
        cout << "Choose: ";
        cout << " 1.Insert | 2.Partition | 3.Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element you want to insert : ";
            cin >> data;
            insert(&head, data);
            printList(head);
            break;
        case 2:
            cout<<"Linked list before duplicate removal ";
            reverse(head);
            printList(head);
            removeDuplicates(head);
            cout<<"\nLinked list after duplicate removal ";  
            printList(head);
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
        }         
    }
     
    return 0;
}
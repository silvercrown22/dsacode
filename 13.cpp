#include <iostream>
using namespace std;
struct Node *head = NULL;
struct Node *tail = NULL;
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
void insert(int new_data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    node->data = new_data;
    if (head == NULL)
    {
        head = node;
        tail = node;
        node->prev = NULL;
        node->next = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        tail = node;
        temp->next = node;
        node->prev = temp;
        node->next = NULL;
    }
}
void partition(int x)
{
	 /* Let us initialize first and last nodes of
      three linked lists
        1) Linked list of values smaller than x.
        2) Linked list of values equal to x.
        3) Linked list of values greater than x.*/
    struct Node *shead = NULL;
    struct Node *lhead = NULL;
    struct Node *equal = NULL;
    struct Node *stail = NULL;
    struct Node *ltail = NULL;
    struct Node *etail = NULL;
    struct Node *ptr1;
    ptr1 = head;

    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
	 // Now iterate original list and connect nodes
    // of appropriate linked lists
    else
    {
		// If current node is equal to x, append it
        // to the list of x values
        while (ptr1 != NULL)
        {
            if (ptr1->data >= x)
            {
                if (lhead == NULL)
                {
                    lhead = ptr1;
                    ltail = ptr1;
                }
                else
                {
                    ltail->next = ptr1;
                    ltail = ltail->next;
                }
            }
			// If current node is less than X, append
        // it to the list of smaller values
            else if (ptr1->data <x)
            {
                if (shead == NULL)
                {
                    shead = ptr1;
                    stail = ptr1;
                }
                else
                {
                    stail->next = ptr1;
                    stail = stail->next;
                }
            }
            
            ptr1 = ptr1->next;
        }
        if(lhead!= NULL)
            ltail->next = NULL;

        stail->next = lhead;
        head = shead;
    }
}
void display()
{
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main()
{
    int choice;
    int c;
    int x;
    cout << "Enter element for partition: ";
    cin >> x;
    int data;

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
            insert(data);
            display();
            break;
        case 2:
            cout << "Before Partition: ";
            display();
            // c = findlength();
            partition(x);
            cout << "After Partition: ";
            display();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << "---------------------------------------------------------------------" << endl;
    }
}
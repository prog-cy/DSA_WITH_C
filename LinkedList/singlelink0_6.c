//insert at beginning in the single linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

Node *create_list();
Node*  insert_at_begin(Node *);
void printList(Node *);


int main()
{
    Node *head, *new;

    head = create_list();// calling a function 

    new = insert_at_begin(head);

    printf("Before insert at beginning\n");
    printList(head);//printing the value of the list before insert at beginning

    printf("\nAfter insert at beginning\n");
    printList(new); // printing the value of the list after insert at beginning
}

//function for creating a single linked list
Node *create_list()
{
    Node *start,*n,  *temp;

    int count=0;

    start = NULL;

    printf("Enter the data\n");
    while(1)
    {
        n = (Node*)malloc(sizeof(Node));
        
        scanf("%d", &n->data);
        n->next = 0;

        if(start == NULL)
        {
            start = n;
            temp = start;
        }

        else
        {
            temp->next = n;
            temp = n;
        }

        ++count;
        if(count==3)
            break;
    }

    return start;
    free(n);
}

//printing the list
void printList(Node *n)
{
    while(n!=0)
    {
        printf("%d ", n->data);
        n = n->next;
    }
}

//function for insert at beginning 
Node  *insert_at_begin(Node *head)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    printf("\nEnter the node at beginning\n");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;

    return head;
    free(newnode);

}


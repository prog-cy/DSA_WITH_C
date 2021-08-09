//creating a circular linked list using head pointer
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;

};

typedef struct node Node;
Node *create_list(Node *start) ;
void display(Node *t);

int main()
{
    Node *head = NULL;
    int choice;

    while (1)
    {
        printf("1: Create a circular link list\n");
        printf("2: Display list\n");
        printf("3: Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create_list(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
        printf("\n");
    }
    
    return 0;
}

//function to create a circular link list
Node *create_list(Node *start)
{
    Node *temp, *new;
    int choice;

    while (1)
    {
        printf("Enter 1 to create a node: ");
        scanf("%d", &choice);
        if(choice!=1)
            break;
        
        new = (Node *)malloc(sizeof(Node));
        scanf("%d", &new->data);
        if(start==0)
        {
            start = new;
            temp = start;
        }

        else
        {
            temp->link = new;
            temp = temp->link;
        }

        new->link = start;   
    }

    return start;
    
}

//function to display a list
void display(Node *t)
{
    Node *p;

    if(t==0)
        printf("list is empty\n");
    
    else
    {
        printf("List is \n");
        p = t;
        do
        {
            printf("%d ", p->data);
            p = p->link;
        } while (p!=t);
        
        //varifying that the list is circular or not
        if(p->data==t->data)
            printf("\nGiven list is circular linked list\n");
    }
    
}
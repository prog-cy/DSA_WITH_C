//deleting node from the end
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;
Node *create_list(Node *start);
Node *del_at_end(Node *h);
void display(Node *t);

int main()
{
    Node *head = 0;

    head = create_list(head);
    printf("Elements before deletion\n");
    display(head);

    printf("\nElements after deletion\n");
    head = del_at_end(head);
    display(head);
}

Node *create_list(Node *start)
{
    Node *temp , *new;
    int choice;

    printf("Enter the info in the list\n");
    while(1)
    {
        printf("Enter 1 to fill the info in the list: ");
        scanf("%d", &choice);
        if(choice!=1)
            break;
        
        new = (Node*)malloc(sizeof(Node));
        scanf("%d", &new->data);

        if(start==0)
        {
            start = new;
            temp = start;
            new->link = 0;   
        }

        else
        {
            temp->link = new;
            temp = temp->link;
            new->link = 0;
        }
    }

    return start;
    free(new);
}

void display(Node *t)
{
    while(t!=0)
    {
        printf("%d ", t->data);
        t = t->link;
    }
}

Node *del_at_end(Node *h)
{
    Node *t, *temp;
    t = h;

    while (t->link!=0)
    {
        temp = t;
        t = t->link;
    }

    temp->link = 0;

    return h;
    free(t);
    
}

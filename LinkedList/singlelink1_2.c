//deleting from at specific position
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct  node *link;
};

typedef struct node Node;

Node *del_at_pos(Node *h, int pos);
Node *create_list(Node *start);
void display(Node *t);

int main()
{
    Node *head = 0;

    int pos;
    
    head = create_list(head);

    printf("Elements in the list before deletion\n");
    display(head);

    printf("\nEnter the position\n");
    scanf("%d", &pos);

    head = del_at_pos(head, pos);
    printf("Elements in the list after deletion\n");
    display(head);

    return 0;
}

Node *create_list(Node *start)
{
    Node *temp , *new;
    int choice;

    printf("Enter info in the list\n");
    while (1)
    {
        printf("Enter 1 to fill info in the list: ");
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

Node *del_at_pos(Node *h, int pos)
{
    Node *temp, *prevnode;
    temp = h;
    int i = 1;

    while(i<pos)
    {
        prevnode = temp;
        temp = temp->link;
        i++;
    }
    prevnode->link = temp->link;
    temp->link = 0;

    return h;
    free(temp);
}
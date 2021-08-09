//deleting a node from the begining
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;
Node *create_list(Node *start);
void display(Node *t);
Node *del_at_beg(Node *h);

int main()
{
    Node *head = 0;

    head = create_list(head);
    printf("Elements in the list before deletion\n");
    display(head);

    printf("\nElements in the list after deletion\n");
    head = del_at_beg(head);
    display(head);

    return 0;
}

Node *create_list(Node *start)
{
    Node *temp, *new;
    int choice;

    printf("Enter the info in the list\n");
    while (1)
    {
        printf("Enter 1 to fill info in the list: ");
        scanf("%d", &choice);
        if (choice != 1)
            break;
        new = (Node *)malloc(sizeof(Node));
        scanf("%d", &new->data);

        if (start == 0)
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
    while (t != 0)
    {
        printf("%d ", t->data);
        t = t->link;
    }
}

Node *del_at_beg(Node *h)
{
    Node *temp;

    temp = h;

    h = temp->link;

    return h;
    free(temp);
}

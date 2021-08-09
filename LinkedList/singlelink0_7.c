//insert node at end of the single linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;

Node *create_list();

void insert_at_end(Node *n);

void printList(Node *n);

int main()
{
    Node *l;

    l = create_list();
    printf("\nBefore insertion elements in the List:\n");
    printList(l);

    insert_at_end(l);
    printf("\nAfter insertion , elements in the list\n");
    printList(l);
}

Node *create_list()
{
    Node *start, *n, *temp;
    start = 0;

    int count = 0;

    while (1)
    {
        n = (Node *)malloc(sizeof(Node));
        scanf("%d", &n->data);
        n->next = 0;

        if (start == 0)
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
        if (count == 3)
            break;
    }
    return start;
    free(n);
}

void printList(Node *n)
{
    while (n != 0)
    {
        printf("%d ", n->data);
        n = n->next;
    }
}

void insert_at_end(Node *n)
{
    Node *newnode, *temp;

    newnode = (Node *)malloc(sizeof(Node));

    printf("\n\nEnter element: ");
    scanf("%d", &newnode->data);

    temp = n;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    //newnode->next = temp->next;
    temp->next = newnode;
    newnode->next =0;
}
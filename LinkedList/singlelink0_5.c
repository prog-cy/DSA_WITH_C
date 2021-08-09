//creating single linked list using function
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} Node;

void List()
{
    Node *head, *temp, *n;

    int count = 0;

    int choice;

    head = 0;

    printf("Enter the data in the node:\n");
    while (1)
    {
        printf("\nEnter  1 if you want to create new node: ");
        scanf("%d", &choice);
        if (choice != 1)
            break;
            
        n = (Node *)malloc(sizeof(Node));
        scanf("%d", &n->data);
        n->next = 0;

        if (head == 0)
        {
            head = n;
            temp = head;
        }

        else
        {
            temp->next = n;
            temp = n;
        }

        ++count;
    }

    printf("\nValues in he List:\n");
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n\nNumber of nodes: %d", count);
    free(n);
}

//main function

int main()
{
    List();
    return 0;
}
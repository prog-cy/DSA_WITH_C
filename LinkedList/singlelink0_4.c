#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

} node;

int main()
{
    node *head, *newnode, *temp;

    head = NULL;

    int count = 0;
    while (1)
    {
        newnode = (node *)malloc(sizeof(node));

        printf("Enter the value:\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if(head==NULL)
        {
            head = newnode;
            temp = head;
        }

        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        ++count;
        if(count==3)
            break;
        
    }
    
    printf("\nValues in the list:\n");
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
    free(newnode);
}
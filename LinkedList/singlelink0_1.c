//creating node of single linked list using simple method
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

int main()
{
    node a, b, c, *temp;

    int count = 0;

    temp = &a;

    //first node
    a.data = 10;
    a.next = &b;

    //second node
    b.data = 20;
    b.next = &c;

    //third node
    c.data = 30;
    c.next = 0;

    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        ++count;
    }

    printf("\nNumber of nodes in List: %d", count);

    return 0;
}
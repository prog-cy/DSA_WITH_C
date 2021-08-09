//method second to create single linked list
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head, a, *second, b, *third, c, *t;

    head = &a;
    second = &b;
    third = &c;

    t = head;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("%d %d %d\n", a.data, b.data, c.data);

    while (t != 0)
    {
        printf("%d ", t->data);
        t = t->next;
    }

    return 0;
}
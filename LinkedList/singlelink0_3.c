//Intializing a single linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void printList(struct node *);

int main()
{
    
    struct node *head, *second, *third;

    head = 0;
    second = 0;
    third = 0;

    //assign memory to all nodes
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node* )malloc(sizeof(struct node));

    head->data = 10;//assign data in first node
    head->next = second;//Link first node  with second

    second->data = 20;//assign data in second node
    second->next = third;//Link second node with third

    third->data = 30;//assign data in third node
    third->next = 0;//Set null 

    printList(head);

    return 0;
    free(head);
    free(second);
    free(third);
}

void printList(struct node *n)
{
    while(n!=0)
    {
        printf("%d ", n->data);
        n = n->next;
    }
}
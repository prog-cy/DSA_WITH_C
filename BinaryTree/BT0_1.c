// Implementation of binary Tree data structure using linked list and recursive approach
#include <stdio.h>
#include <rupesh.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int info;
    struct node *right;
};

typedef struct node Node;
Node *create();
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);

int main(void)
{
    Node *root = 0;
    int choice;
    while (1)
    {

        printf("1: Create a Binary tree\n");
        printf("2: Preorder Traversal\n");
        printf("3: Inorder Traversal\n");
        printf("4: Postorder Traversal\n");
        printf("5: Exit\n");
        printf("Enter choice\n");
        choice = inputInt();
        switch (choice)
        {
        case 1:
            printf("Enter root node\n");
            root = create();
            break;
        case 2:
            printf("Preorder Traversal\n");
            preorder(root);
            break;
        case 3:
            printf("Inorder Traversal\n");
            inorder(root);
            break;
        case 4:
            printf("Postorder Traversal\n");
            postorder(root);
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid choice\n");
        }

        printf("\n");
    }
}

// Recursive function to create a Binary Tree
Node *create()
{
    Node *newnode;
    int x = inputInt();

    newnode = (Node *)malloc(sizeof(Node));
    if (x == -1)
        return 0;
    else
    {
        newnode->info = x;
        printf("Enter left node of %d\n", x);
        newnode->left = create();
        printf("Enter Right node of %d\n", x);
        newnode->right = create();
        return newnode;
    }
}

// FUnction for preorder traversal
void preorder(Node *root)
{
    if (root == 0)
        return;
    else
    {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for inorder traversal
void inorder(Node *root)
{
    if (root == 0)
        return;
    else
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

// Function for postorder Traversal
void postorder(Node *root)
{
    if (root == 0)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}
// Implementation of Binary Search Tree using linked list and recursive approach
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int info;
    struct node *right;
};

typedef struct node Node;
Node *createBST();
void inorder(Node *root);
void preorder(Node *root);

int main(void)
{
    Node *root = 0;
    int ch;
    while (1)
    {
        printf("1: Create a Binary search Tree\n");
        printf("2: Inorder Traversal\n");
        printf("3: preorder Traversal\n");
        printf("4: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter root node\n");
            root = createBST();
            break;
        case 2:
            printf("Inorder Traversal\n");
            inorder(root);
            break;
        case 3:
            printf("Preorder Traversal\n");
            preorder(root);
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid choice\n");
        }

        printf("\n");
    }
}

// Function to create a Binary search Tree
Node *createBST()
{
    Node *newnode, *presentnode, *prenode, *nextnode;
    presentnode = 0;

    newnode = (Node *)malloc(sizeof(Node));
    int x;
    scanf("%d", &x);
    if (x == -1)
        return 0;
    else
    {
        prenode = presentnode;
        newnode->info = x;
        presentnode = newnode;

        nextnode = createBST();
        if (newnode->info < prenode->info)
        {
            printf("left node of %d ", prenode->info);
            newnode->left = nextnode;
        }
        else if (newnode->info > prenode->info)
        {
            printf("rigth node of %d ", prenode->info);
            newnode->right = nextnode;
        }
    }

    return newnode;
}

// function for inorder Traversal
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

// function for preorder Traversal
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

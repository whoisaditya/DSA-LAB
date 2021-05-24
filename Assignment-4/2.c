// Aditya Mitra 20BCE2044

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

// A utility function to create a BST node
struct node *newNode(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->key = x;
    temp->left = temp->right = NULL;

    return temp;
}

// A function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);

        printf("%d ", root->key);

        inorder(root->right);
    }
}

//A function to insert a new node with given key in  BST
struct node *insert(struct node *node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
    {
        return newNode(key);
    }

    // Otherwise, recur down the tree
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }

    // return the (unchanged) node pointer
    return node;
}

int findMax(struct node *root)
{
    // Base case
    if (root == NULL)
    {
        return INT_MAX;
    }

    // Return maximum of 3 values:
    // 1) Root's key 2) Max in Left Subtree
    // 3) Max in right subtree

    int res = root->key;

    int lres = findMax(root->left);
    int rres = findMax(root->right);

    if (lres > res)
    {
        res = lres;
    }
    if (rres > res)
    {
        res = rres;
    }
    return res;
}

int findMin(struct node *root)
{
    // Base case
    if (root == NULL)
    {
        return INT_MIN;
    }

    // Return Minimum of 3 values:
    // 1) Root's key 2) Min in Left Subtree
    // 3) Min in right subtree

    int res = root->key;

    int lres = findMin(root->left);
    int rres = findMin(root->right);

    if (lres < res)
    {
        res = lres;
    }
    if (rres < res)
    {
        res = rres;
    }

    return res;
}

// Driver Code
int main()
{
    struct node *root = NULL;
    int ch, temp;

    //Create a sample treee for the user
    printf("Sample Tree Created\n");

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the sample tree \n");
    inorder(root);

    while (1)
    {
        printf("\nMenu\n1. Insert\n2. Find Min\n3. Find Max\n4. Exit\n\nYour choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            printf("\nEnter Number: ");
            scanf("%d", &temp);

            insert(root, temp);
            inorder(root);

            break;
        }
        case 2:
        {
            // Function call
            printf("Minimum element is %d \n", findMin(root));
            break;
        }
        case 3:
        {
            // Function call
            printf("Maximum element is %d \n", findMax(root));
            break;
        }

        case 4:
        {
            exit(0);
            break;
        }
        }
    }
}

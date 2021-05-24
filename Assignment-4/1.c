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
    temp->left = NULL;
    temp->right = NULL;

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

// Function to search a given key in a given BST
struct node *search(struct node *root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL)
    {
        printf("\nNot Found\n");
        return root;
    }

    if (root->key == key)
    {
        printf("\nFound\n");
        return root;
    }

    // Key is greater than root's key
    if (root->key < key)
    {
        return search(root->right, key);
    }

    // Key is smaller than root's key
    return search(root->left, key);
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    // loop down to find the leftmost leaf
    while (current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

// function to delete the key and return the new root

struct node *delnode(struct node *root, int key)
{
    // base case
    if (root == NULL)
    {
        return root;
    }

    // If the key  is smaller than the root's key, then it lies in left subtree
    if (key < root->key)
    {
        root->left = delnode(root->left, key);
    }

    // If the key  is greater than the root's key, then it lies in right subtree
    else if (key > root->key)
    {
        root->right = delnode(root->right, key);
    }

    // If key is same as root's key,
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);

            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);

            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node *temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = delnode(root->right, temp->key);
    }
    return root;
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
        printf("\nMenu\n1. Insert\n2. Search\n3. Delete\n4. Exit\n\nYour choice: ");
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
                printf("\nEnter Number: ");
                scanf("%d", &temp);

                root = search(root, temp);

                break;
            }

            case 3:
            {
                printf("\nEnter Number: ");
                scanf("%d", &temp);

                root = delnode(root, temp);

                printf("\nInorder traversal of the modified tree \n");
                inorder(root);

                break;
            }
            case 4:
            {
                exit(0);
                break;
            }
        }
    }
    return 0;
}

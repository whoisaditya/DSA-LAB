// Aditya Mitra 20BCE2044
/*
    
*/

#include <bits/stdc++.h>
using namespace std;

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


vector<int> longestPath(node *root)
{

    // If root is null means there
    // is no binary tree so
    // return a empty vector
    if (root == NULL)
    {
        vector<int> temp = {};
        return temp;
    }

    // Recursive call on root->right
    vector<int> rightvect = longestPath(root->right);

    // Recursive call on root->left
    vector<int> leftvect = longestPath(root->left);

    // Compare the size of the two vectors
    // and insert current node accordingly
    if (leftvect.size() > rightvect.size())
        leftvect.push_back(root->key);

    else
        rightvect.push_back(root->key);

    // Return the appropriate vector
    return (leftvect.size() > rightvect.size()
                ? leftvect
                : rightvect);
}

// Driver Code
int main()
{
    struct node *root = NULL;
    int n1, temp;

    cin >> n1;

    for(int i = 0; i < n1; i++)
    {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    // Function call
    vector<int> output = longestPath(root);
    int n = output.size();

    cout << n << endl;

    string str = "";


    //cout << output[n - 1] << " ";
    str = to_string(output[n - 1]);
    
    for (int i = n - 2; i >= 0; i--)
    {
        str = str + " " + to_string(output[i]);
        //cout << output[i] << " ";
    }
    cout << str;
}

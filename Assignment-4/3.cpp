// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Tree Structure
struct node
{
	char data;
	struct node *left, *right;
};

typedef struct node * nodeptr;

// Function to create new node
nodeptr newNode(char c)
{
	nodeptr n = new node;

	n->data = c;
	n->left = NULL;
	n->right = NULL;
	
	return n;
}

// Function to build Expression Tree
nodeptr constructTree(string& str)
{
	// Loop Variable
	int i;
 
    // Stack to hold nodes
    stack<nodeptr> stN;
 
    // Stack to hold characters
    stack<char> stC;
    nodeptr t, t1, t2;
 
    // Prioritising the operators
    int p[123] = { 0 };
    p['+'] = p['-'] = 1;
	p['/'] = p['*'] = 2;
	p['^'] = 3;
    p[')'] = 0;
 
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '(') // Push '(' in char stack
		{  
            stC.push(str[i]);
        }
        else if (isalpha(str[i])) // Push the operands in node stack
        {
            t = newNode(str[i]);
            stN.push(t);
        }
        else if (p[str[i]] > 0)
        {
            // If an operator with lower or same associativity appears
            while (!stC.empty() && stC.top() != '(' && ((str[i] != '^' && p[stC.top()] >= p[str[i]]) || (str[i] == '^' && p[stC.top()] > p[str[i]])))
            {
                // Get and Remove the top element from the character stack
                t = newNode(stC.top());
                stC.pop();
 
                // Get and Remove the top element from the node stack
                t1 = stN.top();
                stN.pop();
 
                // Get and Remove the currently top element from the node stack
                t2 = stN.top();
                stN.pop();
 
                // Update the tree
                t->left = t2;
                t->right = t1;
 
                // Push the node to the node stack
                stN.push(t);
            }
 
            // Push str[i] to char stack
            stC.push(str[i]);
        }
        else if (str[i] == ')') 
		{
            while (!stC.empty() && stC.top() != '(')
            {
				// Get and Remove the top element from the character stack
                t = newNode(stC.top());
                stC.pop();

				// Get and Remove the top element from the node stack
                t1 = stN.top();
                stN.pop();

				// Get and Remove the currently top element from the node stack
                t2 = stN.top();
                stN.pop();

				// Update the tree
                t->left = t2;
                t->right = t1;

				// Push the node to the node stack
                stN.push(t);
            }

			// Pop str[i] from char stack
            stC.pop();
        }
    }
    t = stN.top();

    return t;
}

// Function to print the post order traversal of the tree
void inorder(nodeptr root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Driver code
int main()
{
	string str;
	cout << "Enter an infix expression: ";
    getline(cin, str);

	str = "(" + str;
	str += ")";

	nodeptr root = constructTree(str);

	// Function call
	cout<< "Inorder: " ;
	inorder(root);
	cout<< "\n";

	return 0;
}
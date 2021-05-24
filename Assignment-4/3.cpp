// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Tree Structure
typedef struct node
{
	char data;
	struct node *left, *right;
} * nptr;

// Function to create new node
nptr newNode(char c)
{
	nptr n = new node;

	n->data = c;
	n->left = nullptr;
	n->right = nullptr;
	
	return n;
}

// Function to build Expression Tree
nptr build(string& s)
{
 
    // Stack to hold nodes
    stack<nptr> stN;
 
    // Stack to hold chars
    stack<char> stC;
    nptr t, t1, t2;
 
    // Prioritising the operators
    int p[123] = { 0 };
    p['+'] = p['-'] = 1;
	p['/'] = p['*'] = 2;
	p['^'] = 3;
    p[')'] = 0;
 
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') // Push '(' in char stack
		{  
            stC.push(s[i]);
        }
        else if (isalpha(s[i])) // Push the operands in node stack
        {
            t = newNode(s[i]);
            stN.push(t);
        }
        else if (p[s[i]] > 0)
        {
            // If an operator with lower or same associativity appears
            while (!stC.empty() && stC.top() != '(' && ((s[i] != '^' && p[stC.top()] >= p[s[i]]) || (s[i] == '^' && p[stC.top()] > p[s[i]])))
            {
                // Get and remove the top element from the character stack
                t = newNode(stC.top());
                stC.pop();
 
                // Get and remove the top element from the node stack
                t1 = stN.top();
                stN.pop();
 
                // Get and remove the currently top element from the node stack
                t2 = stN.top();
                stN.pop();
 
                // Update the tree
                t->left = t2;
                t->right = t1;
 
                // Push the node to the node stack
                stN.push(t);
            }
 
            // Push s[i] to char stack
            stC.push(s[i]);
        }
        else if (s[i] == ')') 
		{
            while (!stC.empty() && stC.top() != '(')
            {
				// Get and remove the top element from the character stack
                t = newNode(stC.top());
                stC.pop();

				// Get and remove the top element from the node stack
                t1 = stN.top();
                stN.pop();

				// Get and remove the currently top element from the node stack
                t2 = stN.top();
                stN.pop();

				// Update the tree
                t->left = t2;
                t->right = t1;

				// Push the node to the node stack
                stN.push(t);
            }
			
			// Pop s[i] from char stack
            stC.pop();
        }
    }
    t = stN.top();
    return t;
}

// Function to print the post order
// traversal of the tree
void postorder(nptr root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}
void inorder(nptr root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(nptr root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Driver code
int main()
{
	string s;
	cout << "Enter an infix expression: ";
    cin >> s;

	s = "(a^b^(c/d/e-f)^(x*y-m*n))";
	s = "(" + s;
	s += ")";
	nptr root = build(s);

	// Function call
	cout<< "Inorder:   " ;
	inorder(root);
	cout<< "\n";

	return 0;
}
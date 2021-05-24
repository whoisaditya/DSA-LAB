// Exp 4CD: Expression trees traversal
// Author: Pranjal Timsina; 20BDS0392

#include <iostream>
#include <string>
#include <vector>
#include <stack>

#define MAX 500

// Initializing a stack
std::string stack[MAX];
int top = -1;

// functions to check if stack is empty or full
bool is_empty()
{
    return (top == -1);
}
bool is_full()
{
    return (top == MAX - 1);
}

// returns the top element of stack without removing
std::string peek()
{
    if (is_empty())
    {
        throw "Stack underflow!";
    }
    return stack[top];
}

// pops the top most element of the stack and decrements top
std::string pop()
{
    if (is_empty())
    {
        throw "Stack underflow!";
    }
    return stack[top--];
}

// pushes data to the stack and increments top
void push(std::string data)
{
    if (is_full())
    {
        throw "Stack Overflow!";
    }
    stack[++top] = data;
}

// A class to store data
class node
{
public:
    std::string data;
    node *left;
    node *right;
};

// a factory: to create nodes with a data
node *node_factory(std::string data)
{
    node *new_node = new node;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;
    return new_node;
}

// left parenthesis returns -1
// right parenthesis returns 1
// else returns 0
int parentheses(std::string a)
{
    std::string left[3] = {"[", "{", "("};
    std::string right[3] = {"]", "}", ")"};

    for (std::string ob : left)
    {
        if (a == ob)
        {
            return -1;
        }
    }

    for (std::string ob : right)
    {
        if (a == ob)
        {
            return 1;
        }
    }
    return 0;
}

// returns true operator is passed
bool isoperator(std::string character)
{
    // just a simple function to check whether character is
    // an operator or not
    std::string operators[6] = {"+", "-", "*", "\\", "/", "^"};

    for (auto op : operators)
    {
        if (character == op)
            return true;
    }

    return false;
}

// returns the precedence of an operator
int operator_precedence(std::string op)
{
    if (!isoperator(op))
    {
        return 0;
    }
    if (op == "+" || op == "-")
    {
        return 1;
    }
    else if (op == "*" || op == " /" || op == "%")
    {
        return 2;
    }
    else
        return 3;
}

// takes a single string and returns a vector of
// tokens ie. a+b -> [a, +, b]
std::vector<std::string> tokenize(std::string infix)
{
    // to tokenized string, which is initially empty
    std::vector<std::string> tokenized;
    tokenized.push_back("(");
    std::string previous = "";

    for (char &c : infix)
    {

        // hacky way to convert char to string
        std::string temp;
        temp = c;
        if (temp == " ")
            continue;
        // conditions for handling numbers with more than one digit
        if (isoperator(temp) || previous == "" || isoperator(previous) || parentheses(previous) || parentheses(temp))
            tokenized.push_back(temp);
        else
        {
            // if the previous and current are a digit
            // make them a single entry in the vector
            temp = previous + temp;
            tokenized.pop_back();
            tokenized.push_back(temp);
        }
        previous = temp;
    }

    tokenized.push_back(")");
    return tokenized;
}

std::vector<std::string> to_postfix(std::vector<std::string> infix)
{
    std::vector<std::string> postfix;
    std::string temp;
    int number;

    for (std::string current : infix)
    {
        if (!isoperator(current) and !parentheses(current))
        {
            // if a digit or a variable add to postfix
            postfix.push_back(current);
        }
        else
        {
            temp = current;

            if (parentheses(current) == -1)
            {
                push(temp);
            }
            else if (parentheses(current) == 1)
            {
                while (peek() != "(")
                {
                    postfix.push_back(pop());
                }
                temp = pop();
            }
            else if (is_empty() || operator_precedence(current) > operator_precedence(peek()))
            {
                push(temp);
            }
            else
            {
                while (!is_empty() && (operator_precedence(current) <= operator_precedence(peek())))
                {
                    postfix.push_back(pop());
                }
                push(temp);
            }
        }
    }
    return postfix;
}

node *tree_factory(std::vector<std::string> postfix)
{
    std::stack<node *> stacc;
    std::stack<node *> stacc_operator;
    node *temp, *temp1, *temp2;

    for (std::string c : postfix)
    {
        // std::cout << "Working with " << c << "\n";
        if (!isoperator(c))
        {
            // std::cout << c << " is not an operator, pushing to stack\n";
            temp = node_factory(c);
            stacc.push(temp);
        }
        else
        {
            temp = node_factory(c);
            // std::cout << c << " is an operator, pushing to stack\n";
            temp1 = stacc.top();
            // std::cout << temp1->data<< " was popped from stack\n";
            stacc.pop();
            temp2 = stacc.top();
            // std::cout << temp2->data<< " was popped from stack\n";
            stacc.pop();

            temp->right = temp1;
            temp->left = temp2;

            stacc.push(temp);
        }
    }

    temp = stacc.top();
    stacc.pop();

    return temp;
}
node *real_tree_factory(std::vector<std::string> infix)
{
    std::stack<node *> staccNodes;
    std::stack<std::string> staccTokens;

    node *t, *t1, *t2;

    for (std::string c : infix)
    {
        if (parentheses(c) == -1)
        {
            staccTokens.push(c);
        }
        else if (!isoperator(c))
        {
            t = node_factory(c);
            staccNodes.push(t);
        }
        else if (operator_precedence(c) > 0)
        {
            while (
                !staccTokens.empty() && staccTokens.top() != "(" && ((c != "^" && operator_precedence(staccTokens.top()) >= operator_precedence(c)) || (c == "^" && operator_precedence(staccTokens.top()) > operator_precedence(c))))
            {
                t = node_factory(staccTokens.top());
                staccTokens.pop();
                t1 = staccNodes.top();
                staccNodes.pop();
                t2 = staccNodes.top();
                staccNodes.pop();

                t->left = t2;
                t->right = t1;
                staccNodes.push(t);
            }
        }
        else if (c == ")")
        {
            while (!staccTokens.empty() && staccTokens.top() != "(")
            {
                t = node_factory(staccTokens.top());
                staccTokens.pop();
                t1 = staccNodes.top();
                staccNodes.pop();
                t2 = staccNodes.top();
                staccNodes.pop();
                t->left = t2;
                t->right = t1;
                staccNodes.push(t);
            }
            staccTokens.pop();
        }
    }
    t = staccNodes.top();
    return t;
}

void inorder_traverse(node *root)
{
    if (root != NULL)
    {
        inorder_traverse(root->left);
        std::cout << root->data << " ";
        inorder_traverse(root->right);
    }
}

void preorder_traverse(node *root)
{
    if (root != NULL)
    {
        std::cout << root->data << " ";
        preorder_traverse(root->left);
        preorder_traverse(root->right);
    }
}

void postorder_traverse(node *root)
{
    if (root != NULL)
    {
        postorder_traverse(root->left);
        postorder_traverse(root->right);
        std::cout << root->data << " ";
    }
}

int main()
{
    std::string infix;

    std::cout << "Enter an infix expression: ";
    std::cin >> infix;

    std::vector<std::string> tokenized = tokenize(infix);
    std::vector<std::string> postfix = to_postfix(tokenized);

    for (auto a : tokenized)
    {
        std::cout << a << " ";
    }
    std::cout << "\n";

    // node* tree = tree_factory(postfix);
    node *tree = real_tree_factory(tokenized);
    std::cout << "In Order: ";
    inorder_traverse(tree);
    std::cout << "\nPostOrder: ";
    postorder_traverse(tree);
    std::cout << "\nPreOrder: ";
    preorder_traverse(tree);
    return 0;
}

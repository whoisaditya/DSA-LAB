//20BCE2044 Aditya Mitra
//Program to evaluate infix expressions
#include <bits/stdc++.h>
using namespace std;

class Expression {

    private:

        map<string, int> precedence;
        list<string> infix_tokens;
        list<string> postfix_tokens;
        string exp;

    public:

        Expression() {
            precedence.insert( pair<string, int> ("^", 4) );
            precedence.insert( pair<string, int> ("/", 3) );
            precedence.insert( pair<string, int> ("*", 3) );
            precedence.insert( pair<string, int> ("+", 2) );
            precedence.insert( pair<string, int> ("-", 2) );
            precedence.insert( pair<string, int> ("(", 1) );
        }
        void Evaluate(string strexp);
        void Tokenize();
        void InfixToPostfix();
        void EvaluatePostfix();
};

void Expression :: Evaluate (string strexp) {
    exp = strexp;
    cout << "Expression : " << exp << endl;
    Tokenize();
    InfixToPostfix();
    EvaluatePostfix();
}

// Tokenize individual characters into operators and operands
void Expression :: Tokenize () {

    int sz = exp.size();
    string token("");
     
    int i;
    for (i=0; i<sz-1; i++) {
  
        char p = exp.at(i);
  
        if (p == '+' or p == '-' or p == '/' or p == '*' or p == '^' or p == '(' or p == ')') {
            token = p;
            infix_tokens.push_back(token);
            token = "";
        } else {
            token += p;
            if (!(exp.at(i+1) >= '0' and exp.at(i+1) <= '9')) { 
                infix_tokens.push_back(token);
                token = "";
            }
        }
    }

    if (exp.at(i) >= '0' and exp.at(i) <= '9') {
        token += exp.at(sz-1);
    } else {
        token = exp.at(sz-1);
    }
    infix_tokens.push_back(token);
}

void Expression :: InfixToPostfix () {

    stack<string> stk;
    stk.push("(");
    infix_tokens.push_back(")");

    while (!infix_tokens.empty()) {

        string token = infix_tokens.front();
        infix_tokens.pop_front();

        if (token == "(") {
            stk.push(token);
        } else if (token == ")") {

            // Pop out all the operators and append them to the postfix expression till 
            // an opening bracket is found
            while(stk.top() != "("){
                postfix_tokens.push_back(stk.top());
                stk.pop();
            }
            stk.pop();

        } else if (token == "*" or token == "/" or token == "+" or token == "-" or token == "^") {

            // Pop out operators with higher precedence at the top of the stack and append them to 
            // the postfix expression, before pushing the current operator to the stack.
            while (!stk.empty() and precedence[stk.top()] >= precedence[token]) {
                postfix_tokens.push_back(stk.top());
                stk.pop();
            }
            stk.push(token);

        } else { 
            // Positions of the operands do not change in the postfix expression so append
            // an operand as it is.
            postfix_tokens.push_back(token);
        }
    }
   
    cout << "Postfix Expression :";
    for (auto &i  : postfix_tokens)
        cout << i << ",";
    cout << endl;
}

void Expression :: EvaluatePostfix () {

    stack<int> stk_result;

    while (!postfix_tokens.empty()) {

        string token = postfix_tokens.front();
        postfix_tokens.pop_front();

        if (token.at(0) >= '0' and token.at(0) <= '9') {  
            stringstream ss(token);
            int n;
            ss >> n;
            stk_result.push(n);
        } else {
            int x = stk_result.top();
            stk_result.pop();
            int y = stk_result.top();
            stk_result.pop();
             
            // Note the order of operands(x, y), result equals [y(operator)x]
            if (token == "+") {
               stk_result.push( y + x );
            } else if (token == "-") {
               stk_result.push( y - x );
            } else if (token == "*") {
               stk_result.push( y * x );
            } else if (token == "/") {
               stk_result.push( y / x );
            } else if (token == "^") {
               stk_result.push(pow(y, x));
            }
        }
    } 
    cout << exp << " = " << stk_result.top() << endl << endl;
    stk_result.pop();
}

int main() {

    string strexp1("110+50"); // => 160
    string strexp2("110+50+(4-2*5)-10+40"); // => 184
    string strexp3("(110+50)*(2-4)"); //=> -320
    string strexp4("2^5*(3-4)"); // => -32
    string strexp5("2^5"); // => 32
    string strexp6("0-8-0-5^3"); // => -133

    Expression e;
    e.Evaluate(strexp1);
    e.Evaluate(strexp2);
    e.Evaluate(strexp3);
    e.Evaluate(strexp4);
    e.Evaluate(strexp5);
    e.Evaluate(strexp6);

    return 0;
}
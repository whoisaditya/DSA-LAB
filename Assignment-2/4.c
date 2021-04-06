#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//defining node structure
typedef struct node{
    char ch;
    struct node *next;
}node;

//initializing top of stack to NULL value
node *top = NULL;

//prototype declarations
void push(char);
char pop();
int pre(char);

int evaluate(int, int, char);

int main(){

    //getting infix string from user
    char in[30] = {0}, post[30] = {0};
    printf("Enter infix string: ");
    fgets(in, 20, stdin);
    in[strlen(in) - 1] = 0;

    //runs loop from start of string to end of string 
    for(int i = 0; i < strlen(in); i++){
        //discards spaces in input
        if(in[i] == ' ')
            continue;

        //checks if the character is alphanumeric
        else if(isdigit(in[i])) 
            //adds character to postfix string
            strncat(post, (in + i), 1);
        
        //checks if character is '(' or '^' or the operator preceeding the current operator is of lower precendence
        else if(in[i] == '(' || in[i] == '^' || in[i] == '{' || in[i] == '['|| (top != NULL && pre(top->ch) < pre(in[i])))
            //pushes character in stack
            push(in[i]);
        
        //checks if character is ')'
        else if(in[i] == ')' || in[i] == '}' || in[i] == ']'){
            char p_type;

            if(in[i] == ')')
                p_type = in[i] - 1;
            else
                p_type = in[i] - 2;
            //pops the characters until '(' encountered and adds the popped characters to postfix string
            while(top->ch != p_type && top != NULL){
                char c;
                c = pop();
                strncat(post, &c, 1);
            }
            //discards '('
            pop();
        }
        
        else{
            //pops all operators until the operator preceeding the current operator in stack is of lower precendence
            //appends the popped characters to postfix string
            while((top != NULL && pre(top->ch) >= pre(in[i]))){
                char c;
                c = pop();
                strncat(post, &c, 1);
            }
            push(in[i]);
        }
    }

    //pops any remaining characters in stack and appends them to postfix string
    while(top != NULL){
        char c = pop();
        strncat(post, &c, 1);   
    }

    //infix to postfix conversion done, now evaluation:
    //traverses entire postfix string 
    for(int i = 0; i < strlen(post); i++){
        //checks if current element is operator or operand
        //pushes element in stack if operand
        if(isdigit(post[i]))
            push(post[i]);

        //if operator is found, performs required operation and pushes result in stack
        else{
            int b = (pop()) - 48;       //-48 to convert from character to integer
            int a = (pop()) - 48;       
            char res = (evaluate(a, b, post[i])) + 48;  //+48 to convert from integer to character 
            push(res);
        }
    }

    //pops final result from stack
    int res = (pop()) - 48;

    //prints final result
    printf("%d\n", res);
    return 0;
}

void push(char c){
    //creates a new node and pushes the character onto the stack
    node *new_node;
    new_node = (node *) malloc(sizeof(node));

    new_node->ch = c;
    new_node->next = top;
    top = new_node;
}

char pop(){

    //pops a character from the top of the stack and returns popped character 
    char c;
    c = top->ch;
    node *ptr;
    ptr = top;
    top = top->next;
    
    free(ptr);

    return c;
}

int pre(char c){
    //checks the precendence of the character and returns the appropriate value
    if(c == '-' || c == '+')
        return 0;
    else if(c == '*' || c == '/')
        return 1;
    else if(c == '^')
        return 2;
    else    
        return -1;
}


//evaluates required expression
int evaluate(int a, int b, char op){
    //checks the operator and performs appropriate operation 
    if(op == '+')
        return(a + b);
    else if(op == '-')
        return(a - b);
    else if(op == '/')
        return(a / b);
    else if(op == '*')
        return(a * b);
    else if(op == '^')
        return(pow(a, b));
}
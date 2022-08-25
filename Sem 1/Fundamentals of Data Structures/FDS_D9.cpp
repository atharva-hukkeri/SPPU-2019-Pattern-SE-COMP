#include <iostream>
using namespace std;
#define size 10

class Stack
{
    int top;
    char stack[size];

public:
    Stack()
    {
        top = -1;
    }
    void push(char);
    char pop();
    int isfull();
    int isempty();
};

void Stack::push(char x)
{
    top = top + 1;
    stack[top] = x;
}

char Stack::pop()
{
    char s;
    s = stack[top];
    top = top - 1;
    return s;
}

int Stack::isfull()
{
    if (top == size)
        return 1;
    else
        return 0;
}

int Stack::isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    Stack s1;
    char exp[20], ch;
    int i = 0;
    cout << "\nEnter the expression to check whether it is in well form or not :  ";
    cin >> exp;
    if ((exp[0] == ')') || (exp[0] == ']') || (exp[0] == '}'))
    {
        cout << "\n Invalid Expression.....\n";
        return 0;
    }
    else
    {
        while (exp[i] != '\0')
        {
            ch = exp[i];
            switch (ch)
            {
            case '(':
                s1.push(ch);
                break;
            case '[':
                s1.push(ch);
                break;
            case '{':
                s1.push(ch);
                break;
            case ')':
                s1.pop();
                break;
            case ']':
                s1.pop();
                break;
            case '}':
                s1.pop();
                break;
            }
            i = i + 1;
        }
    }
    if (s1.isempty())
    {
        cout << "\nExpression is well parenthesis...\n";
    }
    else
    {
        cout << "\nInvalid Expression, not well parenthesized....\n";
    }
    return 0;
}

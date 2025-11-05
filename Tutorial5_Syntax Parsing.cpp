#include <iostream>
using namespace std;

#define MAX 100

class InfixToPostfix {
    char infix[500], postfix[MAX];  
    char stack[MAX];                 
    int top;                      
    int pIndex;                     // Index for postfix array

public:
    InfixToPostfix() {
        top = -1;
        pIndex = 0;
    }

    void get_exp() {
        cout << "Enter infix expression : ";
        cin >> infix;
    }

    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    int precedence(char ch) {
        if (ch == '+' || ch == '-') return 1;
        if (ch == '*' || ch == '/') return 2;
        return 0;
    }

    void push(char ch) {
        stack[++top] = ch;
    }

    char pop() {
        return stack[top--];
    }

    char getTop() {
        return stack[top];
    }

    bool isEmpty() {
        return (top == -1);
    }

    void convert() {
        int i = 0;
        while (infix[i] != '\0') {
            char ch = infix[i];
            if (isdigit(ch)) {
                postfix[pIndex++] = ch;  // Append operand directly
            }
            else if (ch == '(') {
                push(ch);
            }
            else if (ch == ')') {
                while (!isEmpty() && getTop() != '(') {
                    postfix[pIndex++] = pop();
                }
                if (!isEmpty()) pop(); // Remove '('
            }
            else if (isOperator(ch)) {
                while (!isEmpty() && precedence(getTop()) >= precedence(ch)) {
                    postfix[pIndex++] = pop();
                }
                push(ch);
            }
            i++;
        }
        while (!isEmpty()) {
            postfix[pIndex++] = pop();
        }
        postfix[pIndex] = '\0'; // Null-terminate postfix string
    }

    void display() {
        cout << "Postfix Expression: " << postfix << endl;
    }

    int evaluate_Postfix() {
        int stk[MAX];
        int topEval = -1;
        int i = 0;
        while (postfix[i] != '\0') {
            char ch = postfix[i];
            if (isdigit(ch)) {
                stk[++topEval] = ch - '0';  // Convert char digit to int
            } else {
                int b = stk[topEval--];
                int a = stk[topEval--];
                int res = 0;
                if (ch == '+') res = a + b;
                else if (ch == '-') res = a - b;
                else if (ch == '*') res = a * b;
                else if (ch == '/') res = a / b;
                stk[++topEval] = res;
            }
            i++;
        }
        return stk[topEval];
    }
};

int main() {
    InfixToPostfix conv;
    conv.get_exp();
    conv.convert();
    conv.display();
    cout << "Evaluated Result: " << conv.evaluate_Postfix() << endl;
    return 0;
}

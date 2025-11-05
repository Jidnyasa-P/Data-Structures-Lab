#include <iostream>
#include <string>
using namespace std;

class stack {
public:
    int top;
    char arr[100]; 

    stack() {
        top = -1;
    }

    void push(char p) {
        if (top >= 99) { 
            return;
        }
        top += 1;
        arr[top] = p;
    }

    char pop() {
        if (top == -1) { 
            return '\0'; 
        }
        char popped_char = arr[top];
        top -= 1; 
        return popped_char;
    }

    int isEmpty() {
        if (top == -1) {
            return 1;
        } else {
            return 0;
        }
    }
    
    char getTop() {
        if (top == -1) {
            return '\0';
        }
        return arr[top];
    }
};

int main() {
	int n;
	cout << "Enter the number of characters : ";
	cin>>n;
	
    string exp;
    cout << "Enter the expression :";
    cin>>exp; 
    
    stack s;
    bool balanced = true;

    for (int i = 0; i < n; i++) {
        char ch = exp[i];
        
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } 
        else if (ch == ')' || ch == ']' || ch == '}') {
            
            if (s.isEmpty()) {
                balanced = false;
                break; 
            }

            char top_element = s.getTop();
            
            if ((ch == ')' && top_element == '(') || 
                (ch == ']' && top_element == '[') || 
                (ch == '}' && top_element == '{')) {
                
                s.pop();
            } else {
                balanced = false;
                break;
            }
        }
    }

    // check if the loop finished and the stack is not empty, it's unbalanced
    if (!s.isEmpty()) {
        balanced = false;
    }

    // Output the result
    if (balanced) {
        cout << "The expression is well-parenthesized (balanced)." << endl;
    } else {
        cout << "The expression is NOT well-parenthesized (unbalanced)." << endl;
    }
    
    return 0;
}

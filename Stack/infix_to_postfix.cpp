#include <iostream>
#include <string>
using namespace std;

#define size 100

struct Stack {
    char arr[size];
    int top = -1;

    bool isFull() {
        return (top == size - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(char x) {
        if (!isFull()) {
            top++;
            arr[top] = x;
        }
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }

    char Top() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0'; // Return null character if the stack is empty
    }
};

// Function to determine the precedence of operators
int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

// Function to convert infix expression to postfix
string infixToPostfix(string s) {
    Stack st;
    string res;

    for (int i = 0; i < s.length(); i++) {
        // If the character is an operand, add it to the result
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            res += s[i];
        }
        // If the character is '(', push it onto the stack
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        // If the character is ')', pop and add to the result until '(' is encountered
        else if (s[i] == ')') {
            while (!st.isEmpty() && st.Top() != '(') {
                res += st.Top();
                st.pop();
            }
            if (!st.isEmpty()) {
                st.pop(); // Remove '(' from the stack
            }
        }
        // If the character is an operator
        else {
            while (!st.isEmpty() && prec(st.Top()) >= prec(s[i])) {
                res += st.Top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // Pop all the remaining operators from the stack
    while (!st.isEmpty()) {
        res += st.Top();
        st.pop();
    }

    return res;
}

int main() {
    string infix = "(a-b/c)*(a/k-l)";
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}

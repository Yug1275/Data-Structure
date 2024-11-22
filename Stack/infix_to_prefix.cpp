#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

struct Stack {
    char arr[SIZE];
    int top = -1;

    bool isFull() {
        return (top == SIZE - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(char x) {
        if (!isFull()) {
            arr[++top] = x;
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
        return '\0';
    }
};

// Custom function to reverse a string using a stack
string reverseString(string s) {
    Stack st;
    
    // Push all characters of the string into the stack
    for (int i=0;i<s.length();i++) {
        char c=s[i];
        st.push(c);
    }

    // Pop characters from the stack and build the reversed string
    string reversed = "";
    while (!st.isEmpty()) {
        reversed += st.Top();
        st.pop();
    }

    return reversed;
}

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

// Function to convert infix to prefix
string infixToPrefix(string s) {
    Stack st;
    string res;

    // Reverse the input infix expression using custom reversal
    s = reverseString(s);

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    // Convert the reversed infix expression to postfix
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            res += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.isEmpty() && st.Top() != '(') {
                res += st.Top();
                st.pop();
            }
            if (!st.isEmpty()) {
                st.pop(); // Remove '(' from the stack
            }
        } else {
            while (!st.isEmpty() && prec(st.Top()) >= prec(s[i])) {
                res += st.Top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // Pop all remaining operators from the stack
    while (!st.isEmpty()) {
        res += st.Top();
        st.pop();
    }

    // Reverse the postfix expression to get the prefix expression
    res = reverseString(res);

    return res;
}

int main() {
    string infix = "(a-b/c)*(a/k-l)";
    cout << "Prefix expression: " << infixToPrefix(infix) << endl;
    return 0;
}

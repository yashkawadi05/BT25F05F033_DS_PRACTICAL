#include <iostream>
#include <cstring>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        arr[++top] = x;
    }

    int pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;
    char postfix[100];

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // If operand, push it into stack
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }
        // If operator, perform operation
        else {
            int b = s.pop();
            int a = s.pop();

            switch (ch) {
                case '+':
                    s.push(a + b);
                    break;

                case '-':
                    s.push(a - b);
                    break;

                case '*':
                    s.push(a * b);
                    break;

                case '/':
                    s.push(a / b);
                    break;
            }
        }
    }

    cout << "Result = " << s.pop() << endl;

    return 0;
}

#include <iostream>
#include <cstdio>
#include <cctype>
#define MAX 100
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int ipow(int base, int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^') return ipow(a, b);
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX];
    int top = -1, pIndex = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) 
			postfix[pIndex++] = infix[i++];
            postfix[pIndex++] = ' ';
            i--;
        } 
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } 
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[pIndex++] = stack[top--];
            if (top != -1) top--;
        } 
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            char curr = infix[i];
            while (top != -1 && stack[top] != '(') {
                int precTop = precedence(stack[top]);
                int precCurr = precedence(curr);
                if (precTop > precCurr || (precTop == precCurr && curr != '^'))
                    postfix[pIndex++] = stack[top--];
                else break;
            }
            stack[++top] = curr;
        }
    }

    while (top != -1) postfix[pIndex++] = stack[top--];
    postfix[pIndex] = '\0';
}

int evalPostfix(char postfix[]) {
    int stack[MAX], top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i]))
                num = num * 10 + (postfix[i++] - '0');
            stack[++top] = num;
        } 
        else if (postfix[i] == ' ') continue;
        else {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = applyOp(a, b, postfix[i]);
        }
    }
    return stack[top];
}

int main() {
    char infix[MAX], postfix[MAX];
    cout << "Enter expression: ";
    gets(infix);

    infixToPostfix(infix, postfix);
    cout << "Postfix: " << postfix << endl;

    int result = evalPostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}


#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluatePostfix(string postfix) {
    stack<int> operands;

    for (char token : postfix) {
        if (isdigit(token)) {
            operands.push(token - '0');
        } else if (isOperator(token)) {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            switch (token) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
            }
        }
    }

    return operands.top();
}

string infixToPostfix(string infix) {
    stack<char> operators;
    stringstream postfix;

    for (char token : infix) {
        if (isdigit(token)) {
            postfix << token;
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() operators.top() != '(') {
                postfix << operators.top();
                operators.pop();
            }
            operators.pop(); // Pop the '('
        } else if (isOperator(token)) {
            while (!operators.empty() precedence(operators.top()) >= precedence(token)) {
                postfix << operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        postfix << operators.top();
        operators.pop();
    }

    return postfix.str();
}

int main() {
    string expression;
    cout << "Enter a mathematical expression: ";
    getline(cin, expression);

    string postfix = infixToPostfix(expression);
    int result = evaluatePostfix(postfix);

    cout << "Result: " << result << endl;

    return 0;
}

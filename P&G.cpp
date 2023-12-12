#include<bits/stdc++.h>
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


int check(vector<int>& a, string oper){

    int n = oper.length();
    int j = 0;
    string expression = "";
    for(int i = 0;i<n;i++){

        if(oper[i]==j+65){expression+=a[j];j++;}
        else expression+=oper[i];
    }
    string postfix = infixToPostfix(expression);
    int result = evaluatePostfix(postfix);

    return result;
}

bool fun(int idx, vector<int>& a, int n, vector<bool>& vis, string oper, int out){

    if(idx == n){

        if(check(a, oper)==out)return true;
        return false;
    }
    for(int i = 1;i<10;i++){

        if(vis[i])continue;
        vis[i] = true;
        a[idx] = i;
        if(fun(idx+1, a, n, vis, oper, out)){

            return true;
        }
        vis[i] = false;
    }

    return false;
}

int main(){

    int n;
    cin>>n;

    vector<int>a(n, 0);
    vector<bool> vis(10, false);
    string oper;
    cin>>oper;
    int op;
    cin>>op;
    cout<<op;
    fun(0, a, n, vis, oper, op);
    for(auto it: a){

        cout<<it<<' ';
    }

    return 0;
    
}
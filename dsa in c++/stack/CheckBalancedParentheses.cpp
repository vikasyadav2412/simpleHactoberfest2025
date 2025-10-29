#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else {
            if (s.empty()) return false;
            char top = s.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '['))
                s.pop();
            else
                return false;
        }
    }
    return s.empty();
}

int main() {
    string expr = "{[()]}";
    if (isBalanced(expr))
        cout << "Balanced parentheses" << endl;
    else
        cout << "Not balanced" << endl;
    return 0;
}

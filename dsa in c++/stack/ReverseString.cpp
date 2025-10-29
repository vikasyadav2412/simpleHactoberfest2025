#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str = "gp";
    stack<char> s;

    for (char ch : str)
        s.push(ch);

    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    cout << "Reversed string: " << reversed << endl;
    return 0;
}

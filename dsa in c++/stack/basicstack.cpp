#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    // Push elements into stack
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;  // 30

    // Pop the top element
    st.pop();

    cout << "After one pop, new top: " << st.top() << endl;  // 20

    // Check if stack is empty
    if (st.empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    // Size of stack
    cout << "Stack size: " << st.size() << endl;

    return 0;
}

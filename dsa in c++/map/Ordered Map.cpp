#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> student;

    // Insertion
    student[101] = "gp";
    student[102] = "Ravi";
    student[103] = "Aman";

    // Another way to insert
    student.insert({104, "Kiran"});

    // Traversal
    cout << "Student Records:\n";
    for (auto it : student)
        cout << "Roll No: " << it.first << " -> Name: " << it.second << endl;

    // Search
    int roll = 102;
    if (student.find(roll) != student.end())
        cout << "\nFound: " << student[roll] << endl;
    else
        cout << "\nNot Found!" << endl;

    // Deletion
    student.erase(103);

    cout << "\nAfter deleting Roll No 103:\n";
    for (auto it : student)
        cout << it.first << " -> " << it.second << endl;

    return 0;
}

#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<int, string> marks;

    // Inserting duplicate keys
    marks.insert({90, "gp"});
    marks.insert({85, "Ravi"});
    marks.insert({90, "Kiran"});
    marks.insert({80, "Aman"});

    cout << "Student Marks (with duplicates):\n";
    for (auto it : marks)
        cout << it.first << " -> " << it.second << endl;

    // Range-based search for duplicates
    int score = 90;
    auto range = marks.equal_range(score);
    cout << "\nStudents with marks " << score << ":\n";
    for (auto it = range.first; it != range.second; ++it)
        cout << it->second << endl;

    return 0;
}

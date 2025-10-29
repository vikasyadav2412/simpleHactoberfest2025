
      //    Frequency Counter

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> freq;

    string words[] = {"apple", "banana", "apple", "cherry", "banana", "apple"};

    // Count frequency
    for (string w : words)
        freq[w]++;

    // Display frequencies
    cout << "Word Frequency:\n";
    for (auto it : freq)
        cout << it.first << " -> " << it.second << endl;

    // Search a word
    string key = "banana";
    if (freq.find(key) != freq.end())
        cout << "\nFrequency of '" << key << "': " << freq[key] << endl;

    return 0;
}

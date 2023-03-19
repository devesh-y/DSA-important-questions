#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int minimumSwaps(string s, char given) {
    vector<int> list;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == given) {
            list.push_back(i);
        }
    }
    int mid = list.size() / 2;

    int minDistance = 0;
    int index = 0;
    for (int number : list) {
        minDistance += abs(number - list[mid]) - abs(mid - index);
        index++;
    }
    return minDistance;
}

int main() {
    string s = "aaafdbdffdsfsaa";
    char given = 'a';
    cout << minimumSwaps(s, given) << endl; 
    return 0;
}

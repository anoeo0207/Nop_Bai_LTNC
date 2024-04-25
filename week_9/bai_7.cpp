#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    string stringArray;
    for (int i = 0; i < n; i++) {
        cin >> stringArray;
        string oddString;
        string evenString;
        for (int j = 0; j < stringArray.size(); j++) {
            if (j % 2 == 0) {
                evenString += stringArray[j];
            } else {
                oddString += stringArray[j];
            }
        }
        cout << evenString << " " << oddString << endl;
    }
    return 0;
}

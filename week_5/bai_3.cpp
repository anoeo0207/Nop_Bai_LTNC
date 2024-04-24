#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
 
int main() {
    int n; cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int variable; cin >> variable;
        arr.push_back(variable);
    }
    int erase_directly; cin >> erase_directly;
    int range1, range2; cin >> range1 >> range2;
    arr.erase(arr.begin() + erase_directly - 1);
    arr.erase(arr.begin() + range1 - 1, arr.begin() + range2 - 1);
    cout << arr.size() << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}
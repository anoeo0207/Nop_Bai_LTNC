#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    int test;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        cin >> test;
        arr.push_back(test);
    }
    int numberOfTestcase; cin >> numberOfTestcase;
    int testCase[numberOfTestcase];
    for (int i = 0; i < numberOfTestcase; i++) {
        cin >> testCase[i];
    }
    for (int i = 0; i < numberOfTestcase; i++) { 
        for (int j = 0; j < n; j++) {
        vector<int>::iterator it1 = lower_bound(arr.begin(), arr.end(), testCase[i]);
        if (*it1 == testCase[i]) {
            cout << "Yes " << it1 - arr.begin() + 1 << endl;
            break;
        } else {
            cout << "No " << it1 - arr.begin() + 1 << endl;
            break;
            }
        }
    }  
    return 0;
}

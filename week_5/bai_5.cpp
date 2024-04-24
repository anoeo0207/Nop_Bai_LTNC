#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int queries; cin >> queries;
    set<int> s;
    for (int i = 0; i < queries; i++) {
        int query; cin >> query;
        int num; cin >> num;
        switch (query) {
            case 1:
            s.insert(num);
            break;
            case 2:
            s.erase(num);
            break;
            case 3:
            if (s.find(num) != s.end()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            break;
        }
    }   
    return 0;
}




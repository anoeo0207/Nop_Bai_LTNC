#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    int query[n];
    string x; int y;
    map<string, int> mp;  
    for (int i = 0; i < n; i++) {
        cin >> query[i];
        if (query[i] == 1) {
            cin >> x >> y;
            mp[x] += y;
        } else if (query[i] == 2) {
            cin >> x;
            mp.erase(x);
        } else if (query[i] == 3) {
            cin >> x;
            if (mp.find(x) != mp.end()) {
                cout << mp[x] << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}




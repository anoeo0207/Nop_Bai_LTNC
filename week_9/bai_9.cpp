#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    map<string, int> mp;
    int query; cin >> query;
    string a, yeu_cau;
    int b;
    
    for (int i = 0; i < query; i++) {
        cin >> a >> b;
        mp[a] = b;
    }
    
    while (cin >> yeu_cau) {
        if (mp.find(yeu_cau) != mp.end()) {
            cout << yeu_cau << "=" << mp[yeu_cau] << endl;
        } else {
            cout << "Not found" << endl;
        }
    }
    return 0;
}

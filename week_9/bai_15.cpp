#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int query; cin >> query;
    for (int i = 0; i < query; i++) {
        int number01, number02;
        cin >> number01 >> number02;
        try {
            if (number01 < 0 || number02 < 0) {
                throw std::invalid_argument ("n and p should be non-negative");
            }
            int c = pow(number01, number02);
            cout << c << endl;
        }  catch (std::invalid_argument& e) {
                cout << "n and p should be non-negative" << endl;
        }
    }   
    return 0;
}

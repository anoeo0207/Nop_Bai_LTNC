#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
 
int main() {
    int a; cin >> a;
    long b; cin >> b;
    char c; cin >> c;
    float d; cin >> d;
    double e; cin >> e;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << fixed << setprecision(3) << d << endl;
    cout << fixed << setprecision(6) << e << endl;
    return 0;
}
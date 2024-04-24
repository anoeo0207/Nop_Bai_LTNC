#include <iostream>
#include <string>
using namespace std;
 
int main() {
	string a, b; cin >> a >> b;
    string c = a + b;
    a[0] = b[0];
    b[0] = c[0];
    cout << a.size() << " " << b.size() << endl;
    cout << c << endl;
    cout << a << " " << b;
    return 0;
}
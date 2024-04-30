#include <bits/stdc++.h>

using namespace std;



int main()
{
    string S;
    getline(cin, S);
    try {
        int a = stoi(S);
        cout << a;
    } catch (const std::invalid_argument& e) {
        cout << "Bad String" << endl;
    } catch (const std::out_of_range& e) {
        cout << "Bad String" << endl;
    }
    return 0;
}

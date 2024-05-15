#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    
    string str;
    while (n > 0) {
        if (n % 2 == 0) {
            str += "0";
        } else {
            str += "1";
        }
        n /= 2;
    }
    int count = 0;
    int maxCount = 0;
    for (char digit : str) {
        if (digit == '1') {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }
    cout << maxCount;
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

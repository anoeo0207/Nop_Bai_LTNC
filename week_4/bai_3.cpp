#include <bits/stdc++.h>
 
using namespace std;
 
string ltrim(const string &);
string rtrim(const string &);
 
/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
 
int palindromeIndex(string s) {
    int result;
    int n = s.size() - 1;
    reverse (s.begin(), s.end());
    string a = s;
    reverse (s.begin(), s.end());
    if (s == a) {
        result = -1;
    } else {
        for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i]) {
            if ((s[i] == s[n - i - 1]) && (s[i +1] == s[n -i - 2])) {
                result = (n - i);
            } else {
                result = i;
                }
            break;
            }
        }
    }
    return result;
}
 
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
 
    string q_temp;
    getline(cin, q_temp);
 
    int q = stoi(ltrim(rtrim(q_temp)));
 
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
 
        int result = palindromeIndex(s);
 
        fout << result << "\n";
    }
 
    fout.close();
 
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

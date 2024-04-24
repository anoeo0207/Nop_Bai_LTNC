#include <bits/stdc++.h>
 
using namespace std;
 
/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
 
string timeConversion(string s) {
    int n = s.size();
    string result;
    if (s[n - 1] == 'M' && s[n - 2] == 'P') {
        string time_change;
        time_change += s[0];
        time_change += s[1];
        int time_change_int = stoi(time_change);
        if (time_change_int != 12) {
            time_change_int += 12;
            string my_time = to_string(time_change_int);
            result += my_time;
            for (int i = 2; i < n; i++) {
                if (i == n - 2) {
                    break;
                }
                result += s[i];
            }
        } else if (time_change_int == 12) {
            for (int i = 0; i < n; i++) {
                if (i == n - 2) {
                    break;
                }
                result += s[i];
            }
        }
    } else if (s[n - 1] == 'M' && s[n - 2] == 'A') {
        string time_change;
        time_change += s[0];
        time_change += s[1];
        int time_change_int = stoi(time_change);
        if (time_change_int == 12) {
            result += "00";
            for (int i = 2; i < n; i++) {
            if (i == n - 2) {
                break;
            }
            result += s[i];
            }
        } else {
            for (int i = 0; i < n; i++) {
            if (i == n - 2) {
                break;
            }
            result += s[i];
            }
        }
    }
    return result;
}
 
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
 
    string s;
    getline(cin, s);
 
    string result = timeConversion(s);
 
    fout << result << "\n";
 
    fout.close();
 
    return 0;
}
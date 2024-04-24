#include <bits/stdc++.h>
 
using namespace std;
 
string ltrim(const string &);
string rtrim(const string &);
 
/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */
 
int pageCount(int n, int p) {
    int count_xuoi = 0;
    int count_nguoc = 0;
    for (int i = 1; i < n; i += 2 ) {
        if (p % 2 == 0) {
            if (i == p || i == p + 1) {
                break;
            }
            } else if (p % 2 != 0) {
                if (i == p || i == p - 1) {
                    break;
                }
        }
        count_xuoi++;
 
    }
    for (int j = n; j >= 1; j -= 2) {
        if (p % 2 == 0) {
            if (j == p || j == p + 1) {
                break;
            }
        } else if (p % 2 != 0) {
                if (j == p || j == p - 1) {
                    break;
                }
            }
        count_nguoc++;
    }
    int number_return = count_xuoi < count_nguoc ? count_xuoi : count_nguoc;
    return number_return;
}
 
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
 
    string n_temp;
    getline(cin, n_temp);
 
    int n = stoi(ltrim(rtrim(n_temp)));
 
    string p_temp;
    getline(cin, p_temp);
 
    int p = stoi(ltrim(rtrim(p_temp)));
 
    int result = pageCount(n, p);
 
    fout << result << "\n";
 
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
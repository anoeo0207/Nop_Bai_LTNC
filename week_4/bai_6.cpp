#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int boiChungNhoNhat (vector <int> b) {
    int first = __gcd(b[0],b[1]);
    for (int i = 2; i < b.size(); i++) {
        first = __gcd(first, b[i]);
    }
    int ans = b[0];
    for (int i = 1; i < b.size(); i++) {
        ans = (ans * b[i]) / __gcd(ans,b[i]);
    }
    return ans;
}

int getTotalX(vector<int> a, vector<int> b) {
    int first = __gcd(a[0],a[1]);
    for (int i = 2; i < a.size(); i++) {
        first = __gcd(first, a[i]);
    }
    int second = boiChungNhoNhat(b);
    int countResult = 0;
    int count1 = 0;
    int count2 = 0;
    int n = first;
    while (n <= second) {
            for (int j = 0; j < a.size(); j++) {
                if (n % a[j] == 0) {
                    count1++;
                }
            }
            for (int e = 0; e < b.size() ; e++) {
                if (b[e] % n == 0) {
                    count2++;
                }
            }
        if (count1 == a.size() && count2 == b.size()) {
            countResult++;
        }
        count1 = 0;
        count2 = 0;
        n++;
    }
    return countResult;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

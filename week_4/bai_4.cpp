#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int number; cin >> number;
    int number_query; cin >> number_query;
    vector<vector<int>> arr(number);
    int length, arr_num;
    for (int i = 0; i < number; i++) {
        cin >> length;
        for (int j = 0; j < length; j++) {
            cin >> arr_num;
            arr[i].push_back(arr_num);
        }
    }
    int query[number], query2[number];
    for (int i = 0; i < number; i++) {
        cin >> query[i] >> query2[i];
        int index1, index2;
        index1 = query[i];
        index2 = query2[i];
        cout << arr[index1][index2] << endl;
    }
    return 0;
}

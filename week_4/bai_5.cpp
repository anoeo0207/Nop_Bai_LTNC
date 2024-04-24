#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
 
int main() {
    int n; cin >> n;
    int a = n + 1;
    int arr1[n];
    int arr2[a];
    int result;
    sort(arr1, arr1 + n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    sort(arr1, arr1 + n);
    for (int i = 0; i < n + 1; i++) {
        cin >> arr2[i];
    }
    sort(arr2, arr2 + a);
    for (int i = 0; i < n + 1; i++) {
        if (arr1[i] != arr2[i]) {
            result = arr2[i];
            break;
        }
    }
    cout << result;
    return 0;
}
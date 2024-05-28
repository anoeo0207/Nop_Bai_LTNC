#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int day, month, year; cin >> day >> month >> year;
    int dayDue, monthDue, yearDue; cin >> dayDue >> monthDue >> yearDue;
    int fine;
    if (year < yearDue) {
        cout << 0;
        return 0;
    } else if (year == yearDue) {
        if (month < monthDue) {
            cout << 0;
            return 0;
        } else if (month == monthDue) {
            if (day < dayDue) {
                cout << 0;
                return 0;
            }
        }
    }
    if (year > yearDue) {
        fine = 10000;
    } else if (year == yearDue && month != monthDue) {
        int n = month - monthDue;
        fine = n * 500;
    } else if (year == yearDue && month == monthDue && day != dayDue) {
        int n = day - dayDue;
        fine = n * 15;
    }
    cout << fine;
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool validPos(int x, int y, int col, int row, char pos[1001][1001]) {
    return 0 <= x && col > x && 0 <= y && row > y;
}

int main() {
   int w, h; cin >> w >> h;
    char pos[1001][1001];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> pos[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (pos[i][j] == 'Y') {
                if (validPos(i + 1, j, h, w, pos) && pos[i + 1][j] == 'E') {
                 pos[i + 1][j] = 'Y';
             }
             if (validPos(i + 1, j + 1, h, w, pos) && pos[i + 1][j + 1] == 'E' && pos[i][j + 1] == 'E') {
                 pos[i + 1][j + 1] = 'Y';
             }
             if (validPos(i + 1, j - 1, h, w, pos) && pos[i][j - 1] == 'E' && pos[i + 1][j - 1] == 'E') {
                 pos[i + 1][j - 1] = 'Y';
             }
            }
        }
    }
    for (int i = 0; i < w; i++) {
        if (pos[h - 1][i] == 'Y') {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
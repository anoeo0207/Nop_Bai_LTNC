#include <iostream>
#include <vector>
#include <algorithm>

int binerySearch (int num, int firstNum, int lastNum, std::vector<int> vct) {
    if (firstNum <= lastNum) {
        int mid = firstNum + (lastNum - firstNum) / 2;
    if (vct[mid] == num) {
        return mid;
    }
    if (vct[mid] < num) {
        return binerySearch(num, mid + 1, lastNum, vct);
    }
    if (vct[mid] > num) {
        return binerySearch(num, firstNum, mid - 1, vct);
        }
    }
    return 0;
}

int main () {
    int num; std::cin >> num;
    int vectorSize; std::cin >> vectorSize;
    std::vector<int> vct;
    for (int i = 0; i < vectorSize; i++) {
        int temp; std::cin >> temp;
        vct.push_back(temp);
    }
    std::sort(vct.begin(), vct.end());
    int res = binerySearch(num, 0, vectorSize - 1, vct);
    if (res != 0) {
        std::cout << "INDEX: " << res << std::endl;
    } else {
        std::cout << "INDEX NOT EXSIST!" << std::endl;
    }
    return 0;
}

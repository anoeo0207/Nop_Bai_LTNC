#include <iostream>
#include <vector>

int main () {
    std::vector<char> vct = {'a','b','c','d'};
    int n = vct.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int e = 0; e < n; e++) {
                std::string str;
                str += vct[i];
                str += vct[j];
                str += vct[e];
                std::cout << str << " ";
            }
        }
    }
    return 0;
}

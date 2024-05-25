#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<string> splitWord (const string &words) {
    vector<string> res;
    stringstream ss(words);
    string word;
    while (getline(ss, word, ';')) {
        res.push_back(word);
    }
    return res;
}

bool isHorizontal (const vector<string> &grid, const string &word, int row, int col) {
    if (word.size() + col > grid.size()) {
        return false;
    }
    for (int i = 0; i < word.size(); i++) {
        if (grid[row][col + i] != '-' && grid[row][col + i] != word[i]) {
            return false;
        }
    }
    return true;
}

bool isVertical (const vector<string> &grid, const string &word, int row, int col) {
    if (word.size() + row > grid.size()) {
        return false;
    }
    for (int i = 0; i < word.size(); i++) {
        if (grid[row + i][col] != '-' && grid[row + i][col] != word[i]) {
            return false;
        }
    }
    return true;
}

void placeWordHorizontal (vector<string> &grid, vector<bool> &place, const string &word, int row, int col) {
    for (int i = 0; i < word.size(); i++) {
        if (grid[row][col + i] == '-') {
            grid[row][col + i] = word[i];
            place[i] = true;
        }
    }
}

void placeWordVerticle (vector<string> &grid, vector<bool> &place, const string &word, int row, int col) {
    for (int i = 0; i < word.size(); i++) {
        if (grid[row + i][col] == '-') {
            grid[row + i][col] = word[i];
            place[i] = true;
        }
    }
}

void removeHorizontal (vector<string> &grid, vector<bool> &place, const string &word, int row, int col) {
    for (int i = 0; i < word.size(); i++) {
        if (place[i]) {
            grid[row][col + i] = '-';
        }
    }
}

void removeVertical (vector<string> &grid, vector<bool> &place, const string &word, int row, int col) {
    for (int i = 0; i < word.size(); i++) {
        if (place[i]) {
            grid[row + i][col] = '-';
        }
    }
}

bool solve (vector<string> &grid, vector <string> &words, int index) {
    if (index == words.size()) {
        return true;
    }
    string word = words[index];
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (isHorizontal(grid, word, i, j)) {
                vector<bool> place(word.size(), false);
                placeWordHorizontal(grid, place, word, i, j);
                if (solve(grid, words, index + 1)) {
                    return true;
                    }
                removeHorizontal(grid, place, word, i, j);
                }
            if (isVertical(grid, word, i, j)) {
                vector<bool> place(word.size(), false);
                placeWordVerticle(grid, place, word, i, j);
                if (solve(grid, words, index + 1)) {
                    return true;
                    }
                removeVertical(grid, place, word, i, j);
                }
            }
        }
        return false;
    }


vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<string> list = splitWord(words);
    solve(crossword, list, 0);
    return crossword;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

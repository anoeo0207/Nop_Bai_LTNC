#ifndef recordScore_h
#define recordScore_h
void readFile (int &killCount, int &lastScore) {
    FILE *file = freopen("saveScore.txt", "r", stdin);
    std::string inFile; getline(std::cin, inFile);
    lastScore = std::stoi(inFile);
    if (killCount > lastScore) {
        lastScore = killCount;
    }
    fclose(file);
}

void recordHighestScore (int &lastScore) {
    FILE *file = freopen("saveScore.txt", "w", stdout);
    std::cout << std::to_string(lastScore) << std::endl;
    fclose(file);
}

#endif /* recordScore_h */

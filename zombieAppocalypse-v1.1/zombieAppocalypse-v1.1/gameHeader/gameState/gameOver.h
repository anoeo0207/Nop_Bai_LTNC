#ifndef gameOver_h
#define gameOver_h
#include "displayTextHeader.h"

void displayGameOver (SDL_Renderer* renderer, SDL_Texture *gameOverBackground, SDL_Texture *newGameButton, SDL_Texture *backButton, SDL_Texture *scoreBoard, int &killCount, int &lastScore, bool &playGame, bool &inMenu, bool &gameOver,bool &moveLeft, bool &moveRight, bool &moveUp, bool &moveDown, bool &fire, bool &shootCheck, int &X, int &Y) {
    handleMusic("gameOverSound.wav");
    SDL_Rect scoreBoardR = {100,300,840,300};
    SDL_Rect newGameButtonR = {680,320,150,150};
    SDL_Rect backButtonR = {680,470,150,150};
    
    SDL_RenderCopy(renderer, gameOverBackground, NULL, NULL);
    SDL_RenderCopy(renderer, scoreBoard, NULL, &scoreBoardR);
    SDL_RenderCopy(renderer, newGameButton, NULL, &newGameButtonR);
    SDL_RenderCopy(renderer, backButton, NULL, &backButtonR);
    
    SDL_Color colorWhite = {255,255,255};
    SDL_Color colorBlack = {0,0,0};
    std::string kill = std::to_string(killCount);
    std::string highestScore = std::to_string(lastScore);
    
    displayText(renderer, colorWhite, 250, 70, 100, "Game Over");
    displayText(renderer, colorWhite, 360, 170, 50, "Try Again?");
    displayText(renderer, colorBlack, 150, 340, 30, "Your Score:");
    displayText(renderer, colorBlack, 350, 340, 30, kill.c_str());
    displayText(renderer, colorBlack, 150, 400, 30, "Your Highest Score:");
    displayText(renderer, colorBlack, 480, 400, 30, highestScore.c_str());

    SDL_RenderPresent(renderer);
    
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_MOUSEBUTTONDOWN:
                        if (event.button.button == SDL_BUTTON_LEFT) {
                        int mouseX = event.button.x;
                        int mouseY = event.button.y;
                        if (mouseX >= newGameButtonR.x && mouseX <= newGameButtonR.x + newGameButtonR.w && mouseY >= newGameButtonR.y && mouseY <= newGameButtonR.y + newGameButtonR.h) {
                            handleMusic("battleSound.wav");
                            moveLeft = false; moveRight = false; moveUp = false; moveDown = false;
                            fire = false; shootCheck = false;
                            playGame = true;
                            gameOver = false;
                            quit = true;
                            killCount = 0;
                            X = 100;
                            Y = 260;
                            SDL_RenderClear(renderer);
                        } else if (mouseX >= backButtonR.x && mouseX <= backButtonR.x + backButtonR.w && mouseY >= backButtonR.y && mouseY <= backButtonR.y + backButtonR.h) {
                            quit = true;
                            gameOver = false;
                            inMenu = true;
                            killCount = 0;
                            X = 100;
                            Y = 260;
                            SDL_RenderClear(renderer);
                    }
                }
            }
        }
    }
}

#endif /* gameOver_h */

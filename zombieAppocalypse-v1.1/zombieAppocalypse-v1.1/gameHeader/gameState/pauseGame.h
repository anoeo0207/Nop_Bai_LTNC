#ifndef pauseGame_h
#define pauseGame_h
#include "displayTextHeader.h"
#include "struct.h"

void pauseGameBoard (SDL_Renderer *renderer, SDL_Texture *pauseBoard, SDL_Texture *continueButton, SDL_Texture *backToMenuButton, bool &playGame, bool &inMenu, bool &pause, bool &moveLeft, bool &moveRight, bool &moveUp, bool &moveDown, int &velChar, int &velZom, int &X, int &Y, int &killCount, std::vector<BULLET> &bulletVector) {
    
    SDL_Rect pauseBoardR = {330,250,370,200};
    SDL_Rect continueButtonR = {370, 320, 130,130};
    SDL_Rect backToMenuButtonR = {530, 320, 130,130};
    
    SDL_Color colorWhite {255,255,255};
    
    SDL_RenderCopy(renderer, pauseBoard, NULL, &pauseBoardR);
    SDL_RenderCopy(renderer, continueButton, NULL, &continueButtonR);
    SDL_RenderCopy(renderer, backToMenuButton, NULL, &backToMenuButtonR);
    displayText(renderer, colorWhite, 415, 250, 70, "PAUSE");
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
                        if (mouseX >= continueButtonR.x && mouseX <= continueButtonR.x + continueButtonR.w && mouseY >= continueButtonR.y && mouseY <= continueButtonR.y + continueButtonR.h) {
                            moveLeft = false; moveRight = false; moveUp = false; moveDown = false;
                            velChar = 8;
                            velZom = 5;
                            pause = false;
                            playGame = true;
                            quit = true;
                            SDL_RenderClear(renderer);
                        } else if (mouseX >= backToMenuButtonR.x && mouseX <= backToMenuButtonR.x + backToMenuButtonR.w && mouseY >= backToMenuButtonR.y && mouseY <= backToMenuButtonR.y + backToMenuButtonR.h) {
                            bulletVector.clear();
                            killCount = 0;
                            X = 100;
                            Y = 260;
                            velChar = 8;
                            velZom = 5;
                            pause = false;
                            inMenu = true;
                            quit = true;
                            SDL_RenderClear(renderer);
                        }
                }
            }
        }
    }
}

#endif /* pauseGame_h */

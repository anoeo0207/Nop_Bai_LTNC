#ifndef mainMenu_h
#define mainMenu_h

#include "gameMusic.h"
#include "handleAnimation.h"

void displayMainMenu(SDL_Renderer* renderer, SDL_Texture* playButton, SDL_Texture *playButtonClick, SDL_Texture* exitButton, SDL_Texture* controlsButton, SDL_Texture* menuBackground, SDL_Texture* character, SDL_Texture* zombie, SDL_Event &event, bool &playGame, bool &quitGame, bool &inMenu, bool &inControls, bool &moveLeft, bool &moveRight, bool &moveUp, bool &moveDown, bool &fire, bool &shootCheck){
    int currentFrame = 1; int currentZombieFrame = 1;
    int mainCharacterPos = 0; int zombiePos = 2;
    int mainCharacterFrame = 6; int zombieFrame = 7;
    int characterX = 250; int zombieX = characterX + 250; int zombie1X = zombieX + 50; int zombie2X = zombieX - 50;
    int characterY = 230; int zombieY = 200; int zombie1Y = 250;
    int characterW = 200;
    int characterH = 150;
    
    
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("font.ttf", 70);
    SDL_Color color = {255, 255, 255};
    SDL_Surface* headerSurface = TTF_RenderText_Solid(font, "Zombie   Apocalypse", color);
    SDL_Texture* headerTexture = SDL_CreateTextureFromSurface(renderer, headerSurface);
    SDL_Rect headerRect = {100,80, headerSurface->w, headerSurface->h};
    
    SDL_Rect playButtonR = {100,480,200,100};
    SDL_Rect controlsButtonR = {400,480,200,100};
    SDL_Rect exitButtonR = {700, 480,200, 100};
    
    TTF_CloseFont(font);
    SDL_FreeSurface(headerSurface);
    
    
    bool choice = false;
    while (!choice) {
        SDL_Delay(70);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, menuBackground, NULL, NULL);
        handleAnimation(renderer, character, characterX, characterY, characterW, characterH, currentFrame, mainCharacterPos, mainCharacterFrame);
        handleAnimation(renderer, zombie, zombieX, zombieY, characterW, characterH, currentZombieFrame, zombiePos, zombieFrame);
        handleAnimation(renderer, zombie, zombie1X, zombie1Y, characterW, characterH, currentZombieFrame, zombiePos, zombieFrame);
        handleAnimation(renderer, zombie, zombie2X, zombie1Y, characterW, characterH, currentZombieFrame, zombiePos, zombieFrame);
        SDL_RenderCopy(renderer, headerTexture, NULL, &headerRect);
        SDL_RenderCopy(renderer, playButton, NULL, &playButtonR);
        SDL_RenderCopy(renderer, exitButton, NULL, &exitButtonR);
        SDL_RenderCopy(renderer, controlsButton, NULL, &controlsButtonR);
        SDL_RenderPresent(renderer);
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_MOUSEBUTTONDOWN:
                        if (event.button.button == SDL_BUTTON_LEFT) {
                        int mouseX = event.button.x;
                        int mouseY = event.button.y;
                        if (mouseX >= playButtonR.x && mouseX <= playButtonR.x + playButtonR.w && mouseY >= playButtonR.y && mouseY <= playButtonR.y + playButtonR.h) {
                            handleMusic("battleSound.wav");
                            moveLeft = false; moveRight = false; moveUp = false; moveDown = false;
                            fire = false; shootCheck = false;
                            playGame = true;
                            choice = true;
                            inMenu = false;
                            SDL_RenderClear(renderer);
                        } else if (mouseX >= exitButtonR.x && mouseX <= exitButtonR.x + exitButtonR.w && mouseY >= exitButtonR.y && mouseY <= exitButtonR.y + exitButtonR.h) {
                            choice = true;
                            quitGame = true;
                            inMenu = false;
                            SDL_RenderClear(renderer);
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyTexture(playButton);
                            SDL_DestroyTexture(controlsButton);
                            SDL_DestroyTexture(exitButton);
                            SDL_DestroyTexture(character);
                            SDL_DestroyTexture(zombie);
                            SDL_DestroyTexture(menuBackground);
                            SDL_DestroyTexture(headerTexture);
                        } else if (mouseX >= controlsButtonR.x && mouseX <= controlsButtonR.x + controlsButtonR.w && mouseY >= controlsButtonR.y && mouseY <= controlsButtonR.y + controlsButtonR.h) {
                            inControls = true;
                            choice = true;
                            inMenu = false;
                            SDL_RenderClear(renderer);
                    }
                }
            }
        }
    }
    SDL_RenderClear(renderer);
    Mix_CloseAudio();
}
#endif /* mainMenu_h */

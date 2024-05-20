#ifndef displayControls_h
#define displayControls_h
#include "displayTextHeader.h"

void displayControls (SDL_Renderer *renderer, SDL_Texture *backButton, SDL_Texture *backGround, bool &inControls, bool &inMenu) {
    SDL_Color colorWhite = {255,255,255};
    SDL_RenderCopy(renderer, backGround, NULL, NULL);
    displayText(renderer, colorWhite, 210, 70, 70, "Controls Button");
    displayText(renderer, colorWhite, 150, 180, 40, "- Move Left: A");
    displayText(renderer, colorWhite, 150, 230, 40, "- Move Right: D");
    displayText(renderer, colorWhite, 150, 280, 40, "- Move Up: W");
    displayText(renderer, colorWhite, 150, 330, 40, "- Move Down: S");
    displayText(renderer, colorWhite, 150, 380, 40, "- Shoot: O");
    displayText(renderer, colorWhite, 150, 430, 40, "- Pause Game: Space");
    
    displayText(renderer, colorWhite, 120, 500, 40, "Kill as much as you could !");
    SDL_Rect backButtonR= {780, 550, 150, 150};
    SDL_RenderCopy(renderer, backButton, NULL, &backButtonR);
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
                        if (mouseX >= backButtonR.x && mouseX <= backButtonR.x + backButtonR.w && mouseY >= backButtonR.y && mouseY <= backButtonR.y + backButtonR.h) {
                            inControls = false;
                            inMenu = true;
                            quit = true;
                            SDL_RenderClear(renderer);
                    }
                }
            }
        }
    }
}

#endif /* displayControls_h */

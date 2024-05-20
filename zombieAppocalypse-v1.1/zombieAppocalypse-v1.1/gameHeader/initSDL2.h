//
//  initSDL2.h
//  zombieAppocalypse-v1.1
//
//  Created by Hai An Nguyen on 17/04/2024.
//

#ifndef initSDL2_h
#define initSDL2_h
void initSDL2(SDL_Window* &window, SDL_Renderer* &renderer) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    IMG_Init(IMG_INIT_JPG);
    TTF_Init();
    window = SDL_CreateWindow("ZOMBIE APOCALYPSE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 704, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

#endif /* initSDL2_h */

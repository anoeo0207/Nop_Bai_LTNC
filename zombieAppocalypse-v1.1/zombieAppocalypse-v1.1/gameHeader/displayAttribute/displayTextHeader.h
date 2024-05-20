#ifndef displayTextHeader_h
#define displayTextHeader_h
void displayText (SDL_Renderer *renderer, SDL_Color color, int X, int Y, int textSize, std::string text) {
    TTF_Font* font = TTF_OpenFont("fontGame.ttf", textSize);
    SDL_Color colorText = color;
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str() , colorText);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {X,Y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    
    TTF_CloseFont(font);
    SDL_FreeSurface(surface);
}

#endif /* displayTextHeader_h */

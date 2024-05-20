#ifndef handleAnimation_h
#define handleAnimation_h

void handleAnimation(SDL_Renderer* renderer, SDL_Texture* texture, int &characterX, int &characterY, int &characterW, int &characterH, int &currentFrame, int animationPosition, int numberFrame) {
    int textureW, textureH;
    SDL_QueryTexture(texture, NULL, NULL, &textureW, &textureH);
    textureW /= 14;
    textureH /= 5;
    SDL_Rect src = {currentFrame * textureW, textureH * animationPosition, textureW, textureH};
    SDL_Rect dst = {characterX, characterY, characterW, characterH};
    currentFrame = (currentFrame + 1) % numberFrame;
    SDL_RenderCopy(renderer, texture, &src, &dst);
}

void handleAnimationUpdate(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect characterPos, int column, int width, int &currentFrame, int animationPosition, int numberFrame) {
    int textureW, textureH;
    SDL_QueryTexture(texture, NULL, NULL, &textureW, &textureH);
    textureW /= width;
    textureH /= column;
    SDL_Rect src = {currentFrame * textureW, textureH * animationPosition, textureW, textureH};
    SDL_Rect dst = {characterPos.x, characterPos.y, characterPos.w, characterPos.h};
    currentFrame = (currentFrame + 1) % numberFrame;
    SDL_RenderCopy(renderer, texture, &src, &dst);
}

#endif /* handleAnimation_h */

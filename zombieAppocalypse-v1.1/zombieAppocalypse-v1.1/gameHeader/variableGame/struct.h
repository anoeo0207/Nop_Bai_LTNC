#ifndef struct_h
#define struct_h
struct BULLET {
    int bulletX, bulletY, bulletW, bulletH;
    SDL_Texture *bulletTexture, *bulletFlipTexture;
    int bulletVelocity = 50;
};

struct ZOMBIE {
    SDL_Texture *texture;
    SDL_Rect position;
    int frameWidth, frameHeight;
    int currentFrame = 1;
    int totalFrame = 7;
    int framePosition = 2;
};

struct EXPLOSION {
    SDL_Texture *explosionTexture;
    SDL_Rect explosionPos;
    int currentExplosionFrame = 1;
    bool finish;
};

#endif /* struct_h */

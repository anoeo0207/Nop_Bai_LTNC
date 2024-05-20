#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <cstdlib>
#include <ctime>
#include "mainMenu.h"
#include "gameMusic.h"
#include "handleAnimation.h"
#include "gameOver.h"
#include "displayTextHeader.h"
#include "displayControls.h"
#include "pauseGame.h"
#include "struct.h"
#include "initSDL2.h"
#include "recordScore.h"
#include "declareVariable.h"

//----------------StructBullet---------------------
SDL_Texture *bulletTexture;
void updateBullet ();
void clearBullet (std::vector<BULLET> &bulletDelete);
void fireBullet (bool &bulletDirectionLeft, bool &fire);
void renderBullet (bool &bulletDirectionLeft, bool &fire);
void attack (std::vector<BULLET> &bulletVector, SDL_Event &e, bool &fire, bool &shootCheck, int &currentShootFrame);
//----------------StructZombie---------------------
SDL_Texture *zombieTexture;
void displayZombies(std::vector<ZOMBIE> &zombieVector, std::vector<BULLET> &bulletVector, int &killCount);
void updateZombiePosition (std::vector<ZOMBIE> &zombieVector, SDL_Texture *zombieTexture);
void handleZombieAnimation (std::vector<ZOMBIE> &zombieVector, SDL_Texture* zombieTexture);
void zombieApproach (std::vector<ZOMBIE> &zombieVector);
//----------------Uint32Variable--------------------
Uint32 lastSpawnTime = 0;
Uint32 lastShoot = 0;
//----------------SDL2Function--------------------
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *renderer);
//----------------SupportFunction-----------------
void handleTexture();
void handleAnimationHoldGun(SDL_Renderer* renderer, SDL_Texture* texture, int &characterX, int &characterY, int &characterW, int &characterH, int &currentFrame, int animationPosition, int numberFrame);
void displayKills (int &killCount);
void displayHeart();
//----------------InUseFunction--------------------
void handleMovements(SDL_Event &e, bool &moveLeft, bool &moveRight, bool &moveUp, bool &moveDown, bool &fire, bool &shootCheck, bool &pause);
void move(bool &moveLeft, bool &moveRight, bool &moveUp, bool &moveDown,int &characterX, int &characterY, int &characterW, int &characterH, int &currentFrame, int &currentFlipFrame);
void renderMap(SDL_Renderer* renderer, SDL_Texture* texture);
void shootEffect();
void checkLimit(int &characterX, int &characterY, int &characterW, int &characterH);
void displayAttribute();
void pauseGame (std::vector<ZOMBIE> &zombieVector);
void runningGame (SDL_Event &e, bool &shootCheck, bool &bulletDirectionLeft);
void freeResource();
//-------------------------------------------------


int main (int argc, char *argv[]) {
    initSDL2(window, renderer);
    handleTexture();
    srand(time(NULL));
    
    bool bulletDirectionLeft = false;
    
    SDL_Event e;
    while (!quitGame) {
        if (gameOver) {
            zombieVector.clear();
            bulletVector.clear();
            readFile(killCount, lastScore);
            recordHighestScore (lastScore);
            displayGameOver(renderer, menuBackground,newGameButton, backButton, scoreBoard, killCount, lastScore, playGame, inMenu, gameOver, moveLeft, moveRight, moveUp, moveDown, fire, shootCheck, characterX, characterY);
            SDL_RenderClear(renderer);
        }
        if (playGame) {
            runningGame (e, shootCheck, bulletDirectionLeft);
            SDL_RenderClear(renderer);
            }
        if (inMenu) {
            handleMusic("mainMenuSound.wav");
            zombieVector.clear();
            displayMainMenu(renderer, playButton, playButtonClick, exitButton, controlsButton, menuBackground, mainCharacter, zombieTexture, e, playGame, quitGame, inMenu, inControls, moveLeft, moveRight, moveUp, moveDown, fire, shootCheck);
            if (inControls) {
                playGame = false;
                displayControls(renderer, backButton, menuBackground, inControls,inMenu);
            }
            SDL_RenderClear(renderer);
        }
        SDL_RenderClear(renderer);
    }
    freeResource();
}

//----------------DefineFunction--------------------
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *renderer) {
    SDL_Texture *texture = nullptr;
    SDL_Surface *loadImage = IMG_Load(file.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, loadImage);
    SDL_FreeSurface(loadImage);
    return texture;
}

void handleTexture() {
    mainCharacter = loadTexture("character.png", renderer);
    mainCharacterFlip = loadTexture("characterFlip.png", renderer);
    zombieTexture = loadTexture("characterFlip.png", renderer);
    zombieDeath = loadTexture("deathAnimation.png", renderer);
    holdGun = loadTexture("holdGun.png", renderer);
    map = loadTexture("mapGame.png", renderer);
    bullet = loadTexture("bullet.png", renderer);
    playButton = loadTexture("playButton.png", renderer);
    playButtonClick = loadTexture("playClick.png", renderer);
    exitButton = loadTexture("exitButton.png", renderer);
    menuBackground = loadTexture("menuBackground.jpg", renderer);
    heart = loadTexture("heart.png", renderer);
    scoreBoard = loadTexture("scoreBoard.png", renderer);
    controlsButton = loadTexture("optionButton.png", renderer);
    newGameButton = loadTexture("playAgainButton.png", renderer);
    backButton = loadTexture("backButton.png", renderer);
    pauseBoard = loadTexture("pauseBoard.png", renderer);
    continueButton = loadTexture("continueButton.png", renderer);
    backToMenuButton = loadTexture("backToMenuButton.png", renderer);
}

void freeResource() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(mainCharacter);
    SDL_DestroyTexture(mainCharacterFlip);
    SDL_DestroyTexture(map);
    SDL_DestroyTexture(bullet);
    SDL_DestroyTexture(holdGun);
    SDL_DestroyTexture(scoreBoard);
    SDL_DestroyTexture(controlsButton);
    SDL_DestroyTexture(newGameButton);
    SDL_DestroyTexture(backButton);
    SDL_DestroyTexture(continueButton);
    SDL_DestroyTexture(backToMenuButton);
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
//----------------MainCharacter + HoldGun-------------
void handleAnimationHoldGun(SDL_Renderer* renderer, SDL_Texture* texture, int &characterX, int &characterY, int &characterW, int &characterH, int &currentFrame, int animationPosition, int numberFrame) {
    int textureW, textureH;
    SDL_QueryTexture(texture, NULL, NULL, &textureW, &textureH);
    textureW /= 16;
    textureH /= 3;
    SDL_Rect src = {currentFrame * textureW, textureH * animationPosition, textureW, textureH};
    SDL_Rect dst = {characterX + 80, characterY + 20, 60, 60};
    SDL_RenderCopy(renderer, texture, &src, &dst);
    currentFrame = (currentFrame + 1) % numberFrame;
}
//-------------------------------------------------

void renderMap(SDL_Renderer* renderer, SDL_Texture* texture) {
    SDL_RenderCopy(renderer, map, NULL, NULL);
}

void handleMovements(SDL_Event &e, bool &moveLeft, bool &moveRight, bool &moveUp, bool &moveDown, bool &fire, bool &shootCheck, bool &pause) {
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_a:
                moveLeft = true;
                break;
            case SDLK_d:
                moveRight = true;
                break;
            case SDLK_w:
                moveUp = true;
                break;
            case SDLK_s:
                moveDown = true;
                break;
            case SDLK_LEFT:
                moveLeft = true;
                break;
            case SDLK_RIGHT:
                moveRight = true;
                break;
            case SDLK_UP:
                moveUp = true;
                break;
            case SDLK_DOWN:
                moveDown = true;
                break;
            case SDLK_SPACE:
                pause = true;
                break;
            case SDLK_o:
                Uint32 currentShoot = SDL_GetTicks();
                if (currentShoot - lastShoot >= coolDown) {
                    handleSoundEffect("gunShot.wav");
                    lastShoot = currentShoot;
                    updateBullet();
                    fire = true;
                    shootCheck = true;
                }
                break;
        }
    } else if (e.type == SDL_KEYUP) {
        switch (e.key.keysym.sym) {
            case SDLK_a:
                moveLeft = false;
                break;
            case SDLK_d:
                moveRight = false;
                break;
            case SDLK_w:
                moveUp = false;
                break;
            case SDLK_s:
                moveDown = false;
                break;
            case SDLK_LEFT:
                moveLeft = false;
                break;
            case SDLK_RIGHT:
                moveRight = false;
                break;
            case SDLK_UP:
                moveUp = false;
                break;
            case SDLK_DOWN:
                moveDown = false;
                break;
        }
    }
}

void move(bool &moveLeft, bool &moveRight, bool &moveUp, bool &moveDown,int &characterX, int &characterY, int &characterW, int &characterH, int &currentFrame, int &currentFlipFrame) {
        if (moveRight) {
            characterX += velocityCharacter;
            handleAnimation(renderer, mainCharacter, characterX, characterY, characterW, characterH, currentMoveRightFrame, runPosition, runFrame);
            currentMoveUpFrame = 1;
            currentMoveDownFrame = 1;
        } else if (moveUp) {
            characterY -= velocityCharacter;
            handleAnimation(renderer, mainCharacter, characterX, characterY, characterW, characterH, currentMoveUpFrame, runPosition, runFrame);
            currentFrame = 1;
            currentMoveRightFrame = 1;
            currentMoveDownFrame = 1;
            currentFrame = 1;
        } else if (moveDown) {
            characterY += velocityCharacter;
            handleAnimation(renderer, mainCharacter, characterX, characterY, characterW, characterH, currentMoveDownFrame, runPosition, runFrame);
            currentMoveRightFrame = 1;
            currentMoveUpFrame = 1;
            currentFrame = 1;
        } else if (moveLeft) {
            characterX -= velocityCharacter;
            handleAnimation(renderer, mainCharacter, characterX, characterY, characterW, characterH, currentMoveDownFrame, runPosition, runFrame);
            currentMoveRightFrame = 1;
            currentMoveUpFrame = 1;
            currentFrame = 1;
        } else {
            handleAnimation(renderer, mainCharacter, characterX, characterY, characterW, characterH, currentFrame, idlePosition, idleFrame);
            currentMoveRightFrame = 1;
            currentMoveUpFrame = 1;
            currentMoveDownFrame = 1;
        }
}

void checkLimit(int &characterX, int &characterY, int &characterW, int &characterH) {
    if (characterX + characterW >= 1024) {
        characterX = 1024 - characterW;
    }
    if (characterX + characterW <= 125) {
        characterX = -20;
    }
    if (characterY + characterH >= 704) {
        characterY = 704 - characterH;
    }
    if (characterY + characterH <= 165) {
        characterY = 62;
    }
}

void pauseGame (std::vector<ZOMBIE> &zombieVector) {
    velocityCharacter = 0;
    velocityZombie = 0;
    fire = false;
    shootCheck = false;
}

void runningGame (SDL_Event &e, bool &shootCheck, bool &bulletDirectionLeft) {
    while (SDL_PollEvent(&e)) {
        handleMovements(e, moveLeft, moveRight, moveUp, moveDown, fire, shootCheck, pause);
    }
        SDL_RenderClear(renderer);
        SDL_Delay(50);
        renderMap(renderer, map);
        if (pause) {
            pauseGame(zombieVector);
            pauseGameBoard(renderer, pauseBoard, continueButton, backToMenuButton, playGame, inMenu, pause, moveLeft, moveRight, moveUp, moveDown, velocityCharacter, velocityZombie, characterX, characterY, killCount, bulletVector);
        } 
        else {
            displayZombies(zombieVector, bulletVector, killCount);
            checkLimit(characterX, characterY, characterW, characterH);
            move(moveLeft, moveRight, moveUp, moveDown, characterX, characterY, characterW, characterH, currentFrame, currentFlipFrame);
            attack(bulletVector, e, fire, shootCheck, currentShootFrame);
            displayAttribute();
            SDL_RenderPresent(renderer);
        }

}

//----------------DisplayAttribute-----------------
void displayKills (int &killCount) {
    SDL_Color color = {255,255,255};
    std::string count = std::to_string(killCount);
    displayText(renderer, color, 820, 30, 20, "Kills:");
    displayText(renderer, color, 900, 30, 20, count.c_str());
}

void displayHeart () {
    SDL_Rect heart01 = {80, -2, 100, 100};
    SDL_Rect heart02 = {120, -2, 100, 100};
    SDL_Rect heart03 = {160, -2, 100, 100};
    if (lifeRemain == 3) {
        SDL_RenderCopy(renderer, heart, NULL, &heart01);
        SDL_RenderCopy(renderer, heart, NULL, &heart02);
        SDL_RenderCopy(renderer, heart, NULL, &heart03);
    } else if (lifeRemain == 2) {
        SDL_RenderCopy(renderer, heart, NULL, &heart01);
        SDL_RenderCopy(renderer, heart, NULL, &heart02);
    } else if (lifeRemain == 1) {
        SDL_RenderCopy(renderer, heart, NULL, &heart01);
    } else if (lifeRemain == 0) {
        gameOver = true;
        playGame = false;
        inMenu = false;
        lifeRemain = 3;
    }
}

void displayAttribute () {
    displayHeart();
    displayKills(killCount);
}
//----------------Zombie---------------------------
void updateZombiePosition (std::vector<ZOMBIE> &zombieVector, SDL_Texture *zombieTexture) {
    for (int i = 0; i < 1; i++) {
        ZOMBIE zombie;
        zombie.position.x = 1000;
        zombie.position.y = rand() % (704 - characterH - 30) + 30;
        zombie.position.w = 150;
        zombie.position.h = 100;
        zombie.texture = zombieTexture;
        zombieVector.push_back(zombie);
    }
}

void handleZombieAnimation (std::vector<ZOMBIE> &zombieVector, SDL_Texture* zombieTexture) {
    for (auto& zombie : zombieVector) {
            handleAnimation (renderer, zombie.texture, zombie.position.x, zombie.position.y, zombie.position.w, zombie.position.h, zombie.currentFrame, zombie.framePosition, zombie.totalFrame);
       }
}

void zombieApproach (std::vector<ZOMBIE> &zombieVector) {
    for (auto &zombie : zombieVector) {
            zombie.position.x -= velocityZombie;
        }
    for (auto it = zombieVector.begin(); it != zombieVector.end();) {
        if ((*it).position.x <= 0) {
            it = zombieVector.erase(it);
            lifeRemain--;
        } else {
            it++;
        }
    }
}

//----------------Bullet---------------------------
void updateBullet () {
    BULLET bullets;
    bullets.bulletX = characterX + 35;
    bullets.bulletY = characterY - 8;
    bullets.bulletW = 100;
    bullets.bulletH = 100;
    bullets.bulletTexture = bullet;
    bullets.bulletFlipTexture = bulletFlip;
    bulletVector.push_back(bullets);
}

void clearBullet (std::vector<int> &bulletDelete) {
    for (auto it = bulletDelete.rbegin(); it != bulletDelete.rend(); ++it) {
            if (*it < bulletVector.size()) {
                bulletVector.erase(bulletVector.begin() + *it);
            }
        }
        bulletDelete.clear();
}

void clearZombie (std::vector<int> &zombieDelete) {
    for (auto it = zombieDelete.rbegin(); it != zombieDelete.rend(); ++it) {
            if (*it < zombieVector.size()) {
                zombieVector.erase(zombieVector.begin() + *it);
            }
        }
        zombieDelete.clear();
}

void handleZombieDeathAnimation(std::vector<EXPLOSION> &explosionVector) {
    for (auto it = explosionVector.begin(); it != explosionVector.end();) {
        if (!it->finish) {
            handleAnimationUpdate(renderer, it->explosionTexture, it->explosionPos, 1, 13, it->currentExplosionFrame, 0, 13);
            if (it->currentExplosionFrame == 12) {
                it->finish = true;
            }
        }
        if (it->finish) {
            it = explosionVector.erase(it);
        } else {
            ++it;
        }
    }
}

void updateHarder () {
    SDL_Color white = {255,255,255};
    if (killCount <= 10 && killCount >= 0) {
        displayText(renderer, white, 450, 20, 30, "Stage I");
        velocityZombie = 5;
        spawnTime = 1300;
    }
    if (killCount <= 25 && killCount >= 11) {
        displayText(renderer, white, 450, 20, 30, "Stage II");
        velocityZombie = 6;
        spawnTime = 1100;
        coolDown = 600;
        velocityCharacter = 12;
    }
    if (killCount <= 50 && killCount >= 26) {
        displayText(renderer, white, 450, 20, 30, "Stage III");
        velocityZombie = 7;
        spawnTime = 900;
        coolDown = 500;
        velocityCharacter = 13;
    }
    if (killCount <= 100 && killCount >= 51) {
        displayText(renderer, white, 450, 20, 30, "Stage IV");
        velocityZombie = 8;
        spawnTime = 700;
        coolDown = 300;
        velocityCharacter = 14;
    }
    if (killCount >= 101 ) {
        displayText(renderer, white, 450, 20, 30, "Stage V");
        velocityZombie = 10;
        spawnTime = 600;
        velocityCharacter = 15;
    }
}

void fireBullet (bool &fire) {
    for (size_t i = 0; i < bulletVector.size(); i++) {
            bulletVector[i].bulletX += bulletVector[i].bulletVelocity;
    }
    for (auto it = bulletVector.begin(); it != bulletVector.end();) {
        if ((*it).bulletX >= 1024) {
            it = bulletVector.erase(it);
            fire = false;
        } else {
            it++;
        }
    }
    for (int i = 0; i < bulletVector.size(); i++) {
        for (int j = 0; j < zombieVector.size(); j++) {
            if (bulletVector[i].bulletX + bulletVector[i].bulletW >= zombieVector[j].position.x + 90 && bulletVector[i].bulletX <= zombieVector[j].position.x + zombieVector[j].position.w - 90 &&
                bulletVector[i].bulletY + bulletVector[i].bulletH >= zombieVector[j].position.y + 70 && bulletVector[i].bulletY <= zombieVector[j].position.y + zombieVector[j].position.h - 70) {
                handleSoundEffect("zombieDeath.wav");
                
                EXPLOSION explosion;
                explosion.explosionTexture = zombieDeath;
                explosion.explosionPos = zombieVector[j].position;
                explosion.currentExplosionFrame = 0;
                explosion.finish = false;
                
                explosionVector.push_back(explosion);
                bulletDelete.push_back(i);
                zombieDelete.push_back(j);
                killCount++;
            }
        }
    }
    
    clearZombie(zombieDelete);
    clearBullet(bulletDelete);
}

void renderBullet (bool &fire) {
    fireBullet(fire);
    for (auto &bullets : bulletVector) {
            SDL_Rect bulletDst = {bullets.bulletX, bullets.bulletY, bullets.bulletW, bullets.bulletH};
            SDL_RenderCopy(renderer, bullets.bulletTexture, NULL, &bulletDst);
        }
    }

void attack(std::vector<BULLET> &bulletVector, SDL_Event &e, bool &fire, bool &shootCheck, int &currentShootFrame) {
        if (fire || shootCheck) {
            if (shootCheck) {
                handleAnimationHoldGun(renderer, holdGun, characterX, characterY, characterW, characterH, currentShootFrame, fireGunPosition, fireGunFrame);
                if (currentShootFrame == 0) {
                    shootCheck = false;
                }
            } else {
                handleAnimationHoldGun(renderer, holdGun, characterX, characterY, characterW, characterH, currentShootFrame, idleHoldGunPosition, idleHoldGunFrame);
            }
        } else {
            handleAnimationHoldGun(renderer, holdGun, characterX, characterY, characterW, characterH, currentHoldGunFrame, idleHoldGunPosition, idleHoldGunFrame);
        }
        renderBullet(fire);
    }


void displayZombies(std::vector<ZOMBIE> &zombieVector, std::vector<BULLET> &bulletVector, int &killCount) {
    Uint32 currentTime = SDL_GetTicks();
    updateHarder();
    if (currentTime - lastSpawnTime >= spawnTime) {
        lastSpawnTime = SDL_GetTicks();
        updateZombiePosition (zombieVector, zombieTexture);
    }
    handleZombieDeathAnimation(explosionVector);
    handleZombieAnimation(zombieVector, zombieTexture);
    zombieApproach(zombieVector);
}
//-------------------------------------------------


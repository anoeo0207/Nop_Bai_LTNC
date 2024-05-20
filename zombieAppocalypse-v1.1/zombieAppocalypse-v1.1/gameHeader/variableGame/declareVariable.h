#ifndef declareVariable_h
#define declareVariable_h
#include "struct.h"
//----------------Variable------------------------
bool moveLeft = false;
bool moveRight = false;
bool moveUp = false;
bool moveDown = false;
bool shootCheck = false;
bool playGame = false;
bool mainMenu = true;
bool quitGame = false;
bool gameOver = false;

bool inMenu = true;
bool inControls = false;
bool pause = false;

bool fire = false;

int characterX = 100;
int characterY = 260;
int characterW = 150;
int characterH = 100;

int zombieX = 500;
int zombieY = 200;
int zombieW = 150;
int zombieH = 100;
int currentZombieFrame = 1;

int currentFrame = 1;
int currentMoveUpFrame = 1;
int currentMoveDownFrame = 1;
int currentFlipFrame = 1;
int currentMoveLeftFrame = 1;
int currentMoveRightFrame = 1;

int currentShootFrame = 1;
int currentHoldGunFrame = 1;

int killCount = 0;
int lifeRemain = 3;
int lastScore = 0;

int velocityCharacter = 10;
int velocityZombie = 4;
int spawnTime = 1500;
int coolDown = 750;
//----------------ConstVariable-------------------
const int idlePosition = 0;
const int idleFrame = 6;
const int runPosition = 3;
const int runFrame = 7;
const int zombieFlipPosition = 2;

const int idleFlipPosition = 3;
const int runFlipPosition = 1;
const int idleHoldGunFlipPosition = 2;
const int fireGunFlipPosition = 1;
const int zombieFrame = 7;

const int idleHoldGunPosition = 2;
const int idleHoldGunFrame = 4;
const int fireGunPosition = 0;
const int fireGunFrame = 7;

//----------------Vector--------------------------
std::vector<ZOMBIE> zombieVector;
std::vector<BULLET> bulletVector;
std::vector<EXPLOSION> explosionVector;
std::vector <int> explosionDelete;
std::vector <int> bulletDelete;
std::vector <int> zombieDelete;
//----------------SDL2Variable--------------------
SDL_Texture *mainCharacter, *holdGun;
SDL_Texture *mainCharacterFlip, *holdGunFlip;
SDL_Texture *zombieDeath;
SDL_Texture *heart;
SDL_Texture *map;
SDL_Texture *bullet, *bulletFlip;
SDL_Texture *playButton, *playButtonClick, *exitButton,*controlsButton, *newGameButton, *backButton, *menuBackground;
SDL_Texture *scoreBoard, *pauseBoard;
SDL_Texture *continueButton, *backToMenuButton;

SDL_Rect bulletR;
SDL_Rect buttonPlayR;
//----------------WindowInit----------------------
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

#endif /* declareVariable_h */

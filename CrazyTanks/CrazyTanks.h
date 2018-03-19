#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

enum fInput { STOP = 0, UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75, FIRE = 32 };
fInput fHit;

const int ammo = 300;
const int MaxWallSize = 3;
const int fieldX = 20;
const int fieldY = 20;
const int coordinates = 6;

const char
wallSymb			= '#',
PlayersPanzerSymb	= 'X',
enemyPanzerSymb		= 'O',
AmoSymb				= '*';

// для танка гг
int positionX, positionY, pFireX, pFireY, prevAmmoSymbX, prevAmmoSymbY, prev2AmmoSymbX, prev2AmmoSymbY, 
AIPositionX, AIPositionY, pPanzerX, pPanzerY, pAIFireX, pAIFireY,

// для вражеских танков
firstAIPanzerX, firstAIPanzerY, secondAIPanzerX, secondAIPanzerY,
thirdAIPanzerX, thirdAIPanzerY, forthAIPanzerX, forthAIPanzerY,
fithAIPanzerX, fithAIPanzerY, sixthAIPanzerX, sixthAIPanzerY,
AIprevAmmoSymbX, AIprevAmmoSymbY, AIprev2AmmoSymbX, AIprev2AmmoSymbY, 
randWalkOnMap, tempCoordAIPanzer = 0; 

//tempCoordX, tempCoordY;
int	_sleepScale = 100; 
int temp = 0; 
int i = 1; //находится в функции AIPanzer()
int ammoValue = 0;
int AIammoValue = 0;
int iEnemyHit = 0;
int iPlayerHit = 3;
int panzerSize = 5;

double iTimer;

//arrays
char mainfieldArr[fieldX][fieldY]{};
char reservfieldArr[fieldX][fieldY]{};
char AmmoSymbX[ammo]{};
char AmmoSymbY[ammo]{};
char prevpFireX[ammo]{};
char prevpFireY[ammo]{};
char AIprevpFireX[ammo]{};
char AIprevpFireY[ammo]{};
char AIAmmoSymbX[ammo]{};
char AIAmmoSymbY[ammo]{};

//bool
bool _bcheckPosition;
bool _randAxis;
bool gameOver = false;
bool kostul = false;  // костыль
bool bFireCheck = false;
bool bWasUP = false, bWasDown = false, bWasRight = false, bWasLeft = false;

bool bReady = false;
bool winner = false;
bool loser = false;

bool caseUPCheck = false;
bool caseDownCheck = false;
bool caseRightCheck = false;
bool caseLeftCheck = false;

bool bShootUp = false;
bool bShootDown = false;
bool bShootRight = false;
bool bShootLeft = false;

bool bEnemyHit1 = false;
bool bEnemyHit2 = false;
bool bEnemyHit3 = false;
bool bEnemyHit4 = false;
bool bEnemyHit5 = false;
bool bEnemyHit6 = false;

//functions

//настройка поля
int mainMenu();
int randWallLocationX();
int randWallLocationY();
int randAIPanzerLocationX();
int randAIPanzerLocationY();
void fieldDefault(char(*fieldDefArr)[fieldY]);
void transfusion();
void CheckWallPosition(char(*arr)[fieldY], int, int, int);
void randWallPosition(char(*locationArr)[fieldY]);
void fieldPrint(char (*fieldPrintArr)[fieldY]);

//танк ГГ
void PlayersPanzer(char(*playersPanzerArr)[fieldY], int, int);
void shooting();

//Вражеские танки
void randAIPanzerPosition(char(*AIPanzerArr)[fieldY], int, int, int&, int&);
void CheckAIPanzerPosition();
void AIPanzer(char AIPanzerArr[fieldX][fieldY], int&, int&);
void AIShoot(int, int);


void GameOver();


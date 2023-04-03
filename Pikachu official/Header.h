#pragma once
#include <vector>
#include <string>
using namespace std;

// save file hacking
#define PADDING 500
#define NAMESIZE 50
#define PASSSIZE 50
#define BOARDSIZE 999
#define URLSIZE 100

struct State
{
    int p, q;
    int p_, q_;
    char board[BOARDSIZE];
    char file_background[URLSIZE];
};

struct Date
{
    int dd, mm, yy;
};

struct Record
{
    Date date;	// Date of completed record
    int points; // points achieved
    // 500 byte NULL
};

struct savefile
{
    char mask;
    char name[NAMESIZE];
    char password[PASSSIZE];
    //Player* list;
    Record record[5];
    State state[5];
};

struct Board {
    int col;
    int row;
    int width; //col * cell width
    int height; //row * cell Height
};

struct Pokemon {
    int i; //index
    int j;

    int x; //coordinate
    int y; // x = 4 + (j - 1) * 10, 3 + (i - 1) * 5
};

struct InforMatches
{
    int bestPoint = 0;
    int bestTime = 0;
    int matches = 0;
    int mistake = 0;
    int point = 0;
    int move = 0;
    int pokemon = 0;
    int time = 0;
    int** board = NULL;
};
struct Player
{
    char userName[20];
    InforMatches* Easy;
    InforMatches* Hard;
};


// Cac ham trong Function.cpp - Thuc hien các chuc nang co ban
void gotoxy(int x, int y);                                               // REF: https://hoctincungthukhoa.com/index.php/l-p-trinh-c-c/64-xay-d-ng-ham-gotoxy-wherex-wherey-trong-dev-c
void TextColor(int x);                                                   // Change text color  REF: https://tuicocach.com/viet-ham-thay-doi-mau-chu-trong-man-hinh-console-c-c/
void ShowConsoleCursor(bool showFlag);                                   // 0: hide cursor, 1: show cursor  REF: https://cplusplus.com/forum/beginner/118176/

// Cac ham trong Screen.cpp - Hien cac man hinh khac nhau
void IntroScreen();
void loginScreen(vector <Player*>& list, int& playerPos);
void helpScreen();
void leaderboardScreen(vector <Player*> list);
void customScreen(int& mode, Board& gameBoard);
void hackScreen(vector <Player*>& list, int playerPos);

// Cac ham trong Menu.cpp - Thao tac voi menu
void interactWithMenu(vector <Player*> list, int playerPos);

// Cac ham trong Display.cpp - Ve hinh
void displayBox(int x, int y, int boxHeight, int boxWidth, string s);    // Draw play button
void displayScreen();
void displayLogo(int x, int y);
void displayMenuScreen();
void displayGameBox(int x, int y, int boxHeight, int boxWidth, int** board, Board gameBoard);
void displayPokeball(int x, int y, int ball_color);
void displayBackground_1(int x, int y);
void deleteBox(int x, int y, int boxHeight, int boxWidth);
void displayBoxChar(int x, int y, int boxHeight, int boxWidth, char s);
void displayPlayerInfo(vector <Player*> list, int playerPos);
void displayGameStatistic();
void displayGameInstruction();
void updateGameStatistic(int point, int move, int mistake);
void displayWinGame(int time, int& choice);
void displayConfirmQuit(int& choice);
void displayContinueGame(int& choice);
void matchingLineType(Pokemon p, int type);
void displayMatchingLine(Pokemon p1, Pokemon p2, int** board, Pokemon*& temp, Board gameBoard, bool display);
void displayMatchingLineL(Pokemon p1, Pokemon p2, Pokemon corner, int** board, Board gameBoard);
void matchingLineUZ(Pokemon p1, Pokemon p2, Pokemon corner1, Pokemon corner2, int** board, Board gameBoard);
void displayBackground_2(Pokemon p);
void background_1_upgrade(Pokemon p);

// Cac ham trong Gameplay-Pointer.cpp - Gameplay bang pointer
void createBoard(int**& board, Board gameBoard); // tao bang ao
void createPoint(int**& board, Board gameBoard); // tao cac gia tri
void deletePoint(int** board, Pokemon p1, Pokemon p2, int mode);
bool samePoint(int** board, Pokemon p1, Pokemon p2);
bool matchingI(int** board, Pokemon p1, Pokemon p2);
bool matchingL(int** board, Pokemon p1, Pokemon p2, Pokemon& corner);
bool matchingUZ(int** board, Pokemon& p1, Pokemon& p2, Pokemon& corner1, Pokemon& corner2, Board gameBoard);
bool checkMatching(int** board, Pokemon p1, Pokemon p2, int& point, Board gameBoard, bool display);
bool checkContinue(int** board, Pokemon& p1, Pokemon& p2, Board gameBoard);
void shuffleBoard(int**& board, Board gameBoard);
void Gameplay(int**& board, int mode, Board& gameBoard, vector <Player*> list, int playerPos);
void GameplayCustom(int**& board, int mode, Board& gameBoard, vector <Player*> list, int playerPos);
void deleteBoard(int**& board, Board gameBoard);

// Cac ham trong Player.cpp - Xu li du lieu nguoi choi
bool checkAvailableUserName(vector <Player*> list, string userName);
void addNewPlayerToList(vector <Player*>& list, string userName);
int posPlayerInList(vector <Player*>& list, string userName);
void copyBoardEasy(vector <Player*> list, int pos, int** board, Board gameBoard);
void copyBoardHard(vector <Player*> list, int pos, int** board, Board gameBoard);
void copyBoard(int** mainBoard, int** board, Board gameBoard);
void outputInfoPlayerBin(vector <Player*> list, string nameFile);
void loadInfoPlayerBin(vector <Player*>& list, string nameFile);
void sortPlayerPointEasy(vector <Player*> list);
void sortPlayerPointHard(vector <Player*> list);
void sortPlayerTimeEasy(vector <Player*> list);
void sortPlayerTimeHard(vector <Player*> list);

// Cac ham trong SaveFileHacking
void loadFileHacking(string fileName, savefile& a);
string operatorXor(string a, string mask);
string binary(int a);
int decimal(string a);
string sovleXor(char a[], string mask);
void changeInfor(savefile& a, Player*& bht);
void saveFileHacking(string nameFile, savefile a);

// COLOR CODE
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

// MOVEMENT
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27
#define SPACE_BAR 32
#define KEY_F 102
#define KEY_H 104
#define KEY_S 115

//
#define screenWidth 120
#define screenHeight 35

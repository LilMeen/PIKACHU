#include <iostream>
#include <ctime>
#include <vector>
#include "Header.h"
using namespace std;

int main()
{
    srand(time(0));
    vector <Player*> list;
    int playerPos;
    cout << "OPEN FULL SCREEN BEFORE START GAME" << endl;
    cout << endl;
    system("pause");
    system("cls");
    IntroScreen();
    loginScreen(list, playerPos);
    interactWithMenu(list, playerPos);
    return 0;
}

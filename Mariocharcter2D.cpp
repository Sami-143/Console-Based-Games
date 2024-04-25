#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

char getCharAtxy(short int x, short int y);
void gotoxy(int x, int y);

string direction = "RIGHT";
string direction1 = "LEFT";
string direction2 = "UP";

int malrioX = 8;
int malrioY = 6;
void printMalrio(int x, int y);
char mar1[3][3] = {
    {' ', '0', ' '},
    {'/', '|', char(209)},
    {'/', ' ', '\\'}};

void erase(int x, int y);

void playerMoveDown();
void playerMoveUp();
void playerMoveRight();
void playerMoveLeft();
void moveMalrioDown();

int bulletX[100];
int bulletY[100];
int bulletCount = 0;
void removeBulletFromArray(int index);
void generateBullet();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void moveBullet();

int masterX = 60;
int masterY = 7;
void printMaster(int x, int y);
char master1[2][2] = {{'@', '@'},
                      {'-', '-'}};
void eraseMaster(int x, int y);
int master_time = 0;
void masterMove();
void bulletCollisionWithMaster();

int guddaX = 80;
int guddaY = 14;
void printGudda(int x, int y);
char gudda1[3][3] = {
    {'o', ' ', 'o'},
    {char(254), '|', char(254)},
    {char(254), char(254), char(254)}};
void eraseGudda(int x, int y);
void moveGudda();
void bulletCollisionWithGudda();

int guddafireX[1000];
int guddafireY[1000];
int guddafireCount = 0;
void generateGuddaFire();
void printGuddaFire(int x, int y);
void eraseGuddaFire(int x, int y);
void removeGuddaFireFromArray(int index);
void moveGuddaFire();

int phuphiX = 130;
int phuphiY = 14;
void printPhuphi(int x, int y);
char phuphi1[3][3] = {{'o', '*', 'o'},
                      {char(254), '|', char(254)},
                      {char(254), char(254), char(254)}};
int phuphifireX[100];
int phuphifireY[100];
int phuphifireCount = 0;
void printPhuphiFire(int x, int y);
void erasePhuphiFire(int x, int y);
void movePhuphiFire();
void removePhuphiFireFromArray(int index);
void generatePhuphiFire();

int doorX = 110;
int doorY = 13;
void printDoor();
char door1[1][1] = {{char(176)}};

int gunEnemyX = 182;
int gunEnemyY = 6;
void printGun(int x, int y);
char gun1[1][4] = {{'<', '-', '-', char(254)}};

int fireX[100];
int fireY[100];
int fireCount = 0;
void generateFire();
void printFire(int x, int y);
void eraseFire(int x, int y);
void removeFireFromArray(int index);
void moveFire();
int gun_timer = 0;

int devilX = 3;
int devilY = 20;
void printDevil(int x, int y);
char devil1[2][4] = {{char(254), char(254), '-', '>'},
                     {char(254), char(254), ' ', ' '}};
void moveDevil();
void eraseDevil(int x, int y);

int devilFireX[1000];
int devilFireY[1000];
void removeDevilFireFromArray(int index);
void generateDevilFire();
void printDevilFire(int x, int y);
void eraseDevilFire(int x, int y);
void moveDevilFire();

void phuphifireCollisionWithMalrio();
void guddafireCollisionWithMalrio();
void fireCollisionWithMalrio();

char mazeArray[38][189];
void loadMaze();

main()
{
    system("cls");
    loadMaze();
    gotoxy(0, 30);
    printMalrio(malrioX, malrioY);
    // printGudda(guddaX,guddaY);
    printMaster(masterX,masterY);
    // printPhuphi(phuphiX,phuphiY);
    // printDevil(devilX,devilY);
    // printGun(gunEnemyX,gunEnemyY);
    gotoxy(doorX, doorY);
    cout << char(176);

    bool gameRunning = true;
    while (gameRunning)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            playerMoveLeft();
            // moveMalrioDown();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            playerMoveRight();
            // moveMalrioDown();
        }

        if (GetAsyncKeyState(VK_UP))
        {
            playerMoveUp();
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            playerMoveDown();
            // moveMalrioDown();
        }

        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet();
        }

        if (master_time == 3)
        {
            masterMove();
            master_time = 0;
        }
        moveBullet();
        master_time++;
        Sleep(20);
    }
}

void printMalrio(int x, int y)
{

    for (int idx = 0; idx < 3; idx++)
    {
        gotoxy(x, y + idx);
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout << "\033[31m" << mar1[idx][idx1];
        }
        cout << endl;
    }
}

void erase(int x, int y)
{
    for (int idx = 0; idx < 3; idx++)
    {
        gotoxy(x, y + idx);
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

// FUNCTION TO MOVE PLAYER LEFT
void playerMoveLeft()
{
    char nextLocation = mazeArray[malrioY][malrioX - 1];
    char nextLocation1 = mazeArray[malrioY + 1][malrioX - 1];
    char nextLocation2 = mazeArray[malrioY + 2][malrioX - 1];
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        erase(malrioX, malrioY);
        malrioX = malrioX - 1;
        printMalrio(malrioX, malrioY);
    }
}

// FUNCTION TO MOVE PLYER UP
void playerMoveRight()
{
    char nextLocation = mazeArray[malrioY][malrioX + 3];
    char nextLocation1 = mazeArray[malrioY + 1][malrioX + 3];
    char nextLocation2 = mazeArray[malrioY + 2][malrioX + 3];
    // if ((nextLocation1 == '+' || nextLocation == '+' ||  nextLocation2 == '+'))
    // {
    //     score++;
    // }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        erase(malrioX, malrioY);
        malrioX = malrioX + 1;
        printMalrio(malrioX, malrioY);
    }
    // else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    // {
    //     health--;
    // }

    // else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') ||  (nextLocation1 == char(254) || nextLocation == char(254) || nextLocation2 == char(254)))
    // {
    //     health--;
    // }
}

// FUNCTION TO MOVE PLAYER RIGHT
void playerMoveUp()
{
    char nextLocation = mazeArray[malrioY - 1][malrioX];
    char nextLocation1 = mazeArray[malrioY - 1][malrioX + 1];
    char nextLocation2 = mazeArray[malrioY - 1][malrioX + 2];
    // if ((nextLocation1 == '+' || nextLocation == '+' ||  nextLocation2 == '+'))
    // {
    //     score++;
    // }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        erase(malrioX, malrioY);
        malrioY = malrioY - 1;
        printMalrio(malrioX, malrioY);
    }

    // else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    // {
    //     health--;
    // }

    // else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') ||  (nextLocation1 == char(254) || nextLocation == char(254) || nextLocation2 == char(254)))
    // {
    //     health--;
    // }
}

// FUNCTION TO MOVE PLAYER DOWN
void playerMoveDown()
{
    char nextLocation = mazeArray[malrioY + 3][malrioX];
    char nextLocation1 = mazeArray[malrioY + 3][malrioX + 1];
    char nextLocation2 = mazeArray[malrioY + 3][malrioX + 2];

    // if ((nextLocation1 == '+' || nextLocation == '+' ||  nextLocation2 == '+'))
    // {
    //     score++;
    // }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        erase(malrioX, malrioY);
        malrioY = malrioY + 1;
        printMalrio(malrioX, malrioY);
    }

    // else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    // {
    //     health--;
    // }

    // else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') ||  (nextLocation1 == char(254) || nextLocation == char(254) || nextLocation2 == char(254)))
    // {
    //     health--;
    // }
}

// PRINT THE BULLETES OF player
void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
// ERASE THE BULLTE FROM THE PREVIOUS LOCATION
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

// GENERATE A BULLET FROM THE MALRIO GUN
void generateBullet()
{
    bulletX[bulletCount] = malrioX + 4;
    bulletY[bulletCount] = malrioY + 1;
    char next = getCharAtxy(bulletX[bulletCount], bulletY[bulletCount]);
    if (next != '#')
    {
        gotoxy(malrioX + 4, malrioY + 1);
        cout << ".";
        bulletCount++;
    }
}

// REMOVE BULLET FROM THE ARRAY OF MALRIO GUN
void removeBulletFromArray(int index)
{
    for (int x = index; x < bulletCount - 1; x++)
    {
        bulletX[x] = bulletX[x + 1];
        bulletY[x] = bulletY[x + 1];
    }
    bulletCount--;
}

// MOVEMENT OF MALRIO GUN BULLETES
void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
        if (next != ' ')
        {
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
        else if (next == ' ')
        {
            eraseBullet(bulletX[x], bulletY[x]);
            bulletX[x] = bulletX[x] + 1;
            printBullet(bulletX[x], bulletY[x]);
        }
    }
}

void printGudda(int x, int y)
{

    for (int idx = 0; idx < 3; idx++)
    {
        gotoxy(guddaX, guddaY + idx);
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout << gudda1[idx][idx1];
        }
        cout << endl;
    }
}

void printMaster(int x, int y)
{

    for (int idx = 0; idx < 2; idx++)
    {
        gotoxy(masterX, masterY + idx);
        for (int idx1 = 0; idx1 < 2; idx1++)
        {
            cout << master1[idx][idx1];
        }
        cout << endl;
    }
}

// FUNCTION FOR MOVEMENT OF MASTER
void masterMove()
{
    if (direction == "RIGHT")
    {
        char nextLocation =mazeArray[masterY][masterX + 2];
        char nextLocation1 = mazeArray[masterY+1][masterX + 2];
        if ((nextLocation != '#' && nextLocation1 != '#'))
        {
            eraseMaster(masterX, masterY);
            masterX = masterX + 1;
            printMaster(masterX, masterY);
        }
        if ((nextLocation == '#' || nextLocation1 == '#'))
        {
            direction = "LEFT";
        }
    }

    if (direction == "LEFT")
    {
        char nextLocation =mazeArray[masterY][masterX - 1];
        char nextLocation1 = mazeArray[masterY+1][masterX - 1];
        if ((nextLocation != '#' && nextLocation1 != '#'))
        {
            eraseMaster(masterX, masterY);
            masterX = masterX - 1;
            printMaster(masterX, masterY);
        }
        else if ((nextLocation == '#' || nextLocation1 == '#'))
        {
            direction = "RIGHT";
        }
    }
}

// ERASE MASTER FROM THE PREVIOUS LOCATION
void eraseMaster(int x, int y)
{
    gotoxy(x, y);
    for (int idx = 0; idx < 2; idx++)
    {
        cout << " ";
    }
    gotoxy(x, y + 1);
    for (int idx = 0; idx < 2; idx++)
    {
        cout << " ";
    }
}

void printPhuphi(int x, int y)
{

    for (int idx = 0; idx < 3; idx++)
    {
        gotoxy(phuphiX, phuphiY + idx);
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout << phuphi1[idx][idx1];
        }
        cout << endl;
    }
}

void printGun(int x, int y)
{

    for (int idx = 0; idx < 1; idx++)
    {
        gotoxy(gunEnemyX, gunEnemyY);
        for (int idx1 = 0; idx1 < 4; idx1++)
        {
            cout << gun1[idx][idx1];
        }
    }
}

void printDevil(int x, int y)
{

    for (int idx = 0; idx < 2; idx++)
    {
        gotoxy(devilX, devilY + idx);
        for (int idx1 = 0; idx1 < 4; idx1++)
        {
            cout << devil1[idx][idx1];
        }
        cout << endl;
    }
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void loadMaze()
{
    fstream myfile;
    string line;
    int row = 0;
    myfile.open("maze.txt", ios::in);
    while (getline(myfile, line))
    {
        for (int colom = 0; colom < 195; colom++)
        {
            mazeArray[row][colom] = line[colom];
        }
        row++;
    }
    myfile.close();
    for (int i = 0; i < 37; i++)
    {
        for (int j = 0; j < 189; j++)
        {
            cout << mazeArray[i][j];
        }
        cout << endl;
    }
}

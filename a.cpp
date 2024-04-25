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

int bullet[100][2];
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

int guddafire[100][2];
int guddafireCount = 0;
void generateGuddaFire();
void printGuddaFire(int x, int y);
void eraseGuddaFire(int x, int y);
void removeGuddaFireFromArray(int index);
void moveGuddaFire();
void guddafireCollisionWithMalrio();
void bulletCollisionWithGudda();

int phuphiX = 130;
int phuphiY = 14;
void printPhuphi(int x, int y);
char phuphi1[3][3] = {{'o', '*', 'o'},
                      {char(254), '|', char(254)},
                      {char(254), char(254), char(254)}};
void movePhuphi();
void erasePhuphi(int x, int y);
int phuphifire[100][2];
int phuphifireCount = 0;
void printPhuphiFire(int x, int y);
void erasePhuphiFire(int x, int y);
void movePhuphiFire();
void removePhuphiFireFromArray(int index);
void generatePhuphiFire();
void bulletCollisionWithPhuphi();
void phuphifireCollisionWithMalrio();

int doorX = 110;
int doorY = 13;
void printDoor();
char door1[1][1] = {{char(176)}};

int gunEnemyX = 182;
int gunEnemyY = 6;
void printGun(int x, int y);
char gun1[1][4] = {{'<', '-', '-', char(254)}};

int fire[100][2];
int fireCount = 0;
void generateFire();
void printFire(int x, int y);
void eraseFire(int x, int y);
void removeFireFromArray(int index);
void moveFire();
int gun_timer = 0;
void fireCollisionWithMalrio();

int devilX = 3;
int devilY = 20;
void printDevil(int x, int y);
char devil1[2][4] = {{char(254), char(254), '-', '>'},
                     {char(254), char(254), ' ', ' '}};
void moveDevil();
void eraseDevil(int x, int y);

int devilFire[100][2];
int devilFireCount = 0;
void removeDevilFireFromArray(int index);
void generateDevilFire();
void printDevilFire(int x, int y);
void eraseDevilFire(int x, int y);
void moveDevilFire();
void devilfireCollisionWithMalrio();




int health=20;
int score = 0;
void addScore();
void printScore();
char mazeArray[38][189];
void loadMaze();

main()
{
    system("cls");
    loadMaze();
    system("Color 09");
    gotoxy(0, 30);
    printMalrio(malrioX, malrioY);
    printGudda(guddaX, guddaY);
    printMaster(masterX, masterY);
    printPhuphi(phuphiX, phuphiY);
    printDevil(devilX, devilY);
    printGun(gunEnemyX, gunEnemyY);
    gotoxy(doorX, doorY);
    cout << char(176);

    bool gameRunning = true;
    while (gameRunning)
    {
        printScore();
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
            moveGudda();
            movePhuphi();
            moveDevil();
            master_time = 0;
        }

        if (gun_timer == 2)
        {
            generateFire();
            generateGuddaFire();
            generatePhuphiFire();
            generateDevilFire();
            gun_timer = 0;
        }
        gun_timer++;
        moveFire();
        moveBullet();
        moveGuddaFire();
        movePhuphiFire();
        moveDevilFire();
        master_time++;
        Sleep(20);
        bulletCollisionWithMaster();
        bulletCollisionWithGudda();
        guddafireCollisionWithMalrio();
        bulletCollisionWithPhuphi();
        phuphifireCollisionWithMalrio();
        fireCollisionWithMalrio();
        devilfireCollisionWithMalrio();
        // bulletCollisionWithDevil();
        
        gotoxy(20, 40);
        cout << "Health: " << health;
        if (score == 30)
        {
            gameRunning = false;
        }

        if (health == 0)
        {
            gameRunning = false;
        }
    }
}

// MALRIO
// FUCTIONS
// funtion for the printing of Malrio
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
     if ((nextLocation1 == '+' || nextLocation == '+' ||  nextLocation2 == '+'))
    {
        score++;
    }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        erase(malrioX, malrioY);
        malrioX = malrioX - 1;
        printMalrio(malrioX, malrioY);
    }
    else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') ||  (nextLocation1 == char(254) || nextLocation == char(254) || nextLocation2 == char(254)))
    {
        health--;
    }
}

// FUNCTION TO MOVE PLYER UP
void playerMoveRight()
{
    char nextLocation = mazeArray[malrioY][malrioX + 3];
    char nextLocation1 = mazeArray[malrioY + 1][malrioX + 3];
    char nextLocation2 = mazeArray[malrioY + 2][malrioX + 3];
    if ((nextLocation1 == '+' || nextLocation == '+' ||  nextLocation2 == '+'))
    {
        score++;
    }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        erase(malrioX, malrioY);
        malrioX = malrioX + 1;
        printMalrio(malrioX, malrioY);
    }
    else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        health--;
    }

    else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') ||  (nextLocation1 == char(254) || nextLocation == char(254) || nextLocation2 == char(254)))
    {
        health--;
    }
}

// FUNCTION TO MOVE PLAYER RIGHT
void playerMoveUp()
{
    char nextLocation = mazeArray[malrioY - 1][malrioX];
    char nextLocation1 = mazeArray[malrioY - 1][malrioX + 1];
    char nextLocation2 = mazeArray[malrioY - 1][malrioX + 2];
    if ((nextLocation1 == '+' || nextLocation == '+' ||  nextLocation2 == '+'))
    {
        score++;
    }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        erase(malrioX, malrioY);
        malrioY = malrioY - 1;
        printMalrio(malrioX, malrioY);
    }

    else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        health--;
    }

    else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') ||  (nextLocation1 == char(254) || nextLocation == char(254) || nextLocation2 == char(254)))
    {
        health--;
    }
}

// FUNCTION TO MOVE PLAYER DOWN
void playerMoveDown()
{
    char nextLocation = mazeArray[malrioY + 3][malrioX];
    char nextLocation1 = mazeArray[malrioY + 3][malrioX + 1];
    char nextLocation2 = mazeArray[malrioY + 3][malrioX + 2];

    if ((nextLocation1 == '+' || nextLocation == '+' ||  nextLocation2 == '+'))
    {
        score++;
    }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        erase(malrioX, malrioY);
        malrioY = malrioY + 1;
        printMalrio(malrioX, malrioY);
    }

    else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        health--;
    }

    else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') ||  (nextLocation1 == char(254) || nextLocation == char(254) || nextLocation2 == char(254)))
    {
        health--;
    }
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
    bullet[bulletCount][0] = malrioX + 4;
    bullet[bulletCount][1] = malrioY + 1;
    char next = getCharAtxy(bullet[bulletCount][0], bullet[bulletCount][1]);
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
        bullet[x][0] = bullet[x + 1][0];
        bullet[x][1] = bullet[x + 1][1];
    }
    bulletCount--;
}

// MOVEMENT OF MALRIO GUN BULLETES
void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        char next = getCharAtxy(bullet[x][0] + 1, bullet[x][1]);
        if (next != ' ')
        {
            eraseBullet(bullet[x][0], bullet[x][1]);
            removeBulletFromArray(x);
        }
        else if (next == ' ')
        {
            eraseBullet(bullet[x][0], bullet[x][1]);
            bullet[x][0] = bullet[x][0] + 1;
            printBullet(bullet[x][0], bullet[x][1]);
        }
    }
}

// MASTER
// FUCTIONS
// funtion for the printing of master
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
        char nextLocation = mazeArray[masterY][masterX + 2];
        char nextLocation1 = mazeArray[masterY + 1][masterX + 2];
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
        char nextLocation = mazeArray[masterY][masterX - 1];
        char nextLocation1 = mazeArray[masterY + 1][masterX - 1];
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

// Collision detection With the master
void bulletCollisionWithMaster()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bullet[x][0] + 1 == masterX && (bullet[x][1] == masterY || bullet[x][1] == masterY + 1 || bullet[x][1] == masterY + 2 || bullet[x][1] == masterY + 3))
        {
            addScore();
            eraseBullet(bullet[x][0], bullet[x][1]);
            removeBulletFromArray(x);
        }
    }
}

// Gudda
// Functions
// function for the printing of gudda
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

// ERASE THE GUDDA
void eraseGudda(int x, int y)
{
    gotoxy(x, y);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
    gotoxy(x, y + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
    gotoxy(x, y + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
}
// FUCTION FOR MOVEMENT OF GUDDA
void moveGudda()
{
    if (direction1 == "RIGHT")
    {
        char nextLocation = mazeArray[guddaY][guddaX + 3];
        char nextLocation1 = mazeArray[guddaY + 1][guddaX + 3];
        char nextLocation2 = mazeArray[guddaY + 2][guddaX + 3];
        if (nextLocation == ' ' && nextLocation1 == ' ' && nextLocation2 == ' ')
        {
            erase(guddaX, guddaY);
            guddaX = guddaX + 1;
            printGudda(guddaX, guddaY);
        }
        else if (nextLocation == '#' || nextLocation1 == '#' || nextLocation2 == '#')
        {
            direction1 = "LEFT";
        }
    }

    if (direction1 == "LEFT")
    {
        char nextLocation = mazeArray[guddaY][guddaX - 1];
        char nextLocation1 = mazeArray[guddaY + 1][guddaX - 1];
        char nextLocation2 = mazeArray[guddaY + 2][guddaX - 1];
        if (nextLocation != '#' && nextLocation1 != '#' && nextLocation2 != '#')
        {
            eraseGudda(guddaX, guddaY);
            guddaX = guddaX - 1;
            printGudda(guddaX, guddaY);
        }
        else if (nextLocation == '#' || nextLocation1 == '#' || nextLocation2 == '#')
        {
            direction1 = "RIGHT";
        }
    }
}

// PRINT THE BULLET OF Gudda
void printGuddaFire(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}

// ERASE THE BULLTE FROM THE PREVIOUS LOCATION
void eraseGuddaFire(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

// GENERATE A BULLET FROM THE Gudda GUN
void generateGuddaFire()
{
    guddafire[guddafireCount][0] = guddaX + 4;
    guddafire[guddafireCount][1] = guddaY;
    gotoxy(guddaX + 4, guddaY);
    cout << "-";
    guddafireCount++;
}

// REMOVE BULLET FROM THE ARRAY OF Gudda GUN
void removeGuddaFireFromArray(int index)
{
    for (int x = index; x < guddafireCount - 1; x++)
    {
        guddafire[x][0] = guddafire[x + 1][0];
        guddafire[x][1] = guddafire[x + 1][1];
    }
    guddafireCount--;
}

// MOVEMENT OF Gudda GUN BULLETES
void moveGuddaFire()
{
    for (int x = 0; x < guddafireCount; x++)
    {

        char next = getCharAtxy(guddafire[x][0] + 1, guddafire[x][1] + 1);
        if (next != ' ' || next == '#')
        {

            eraseGuddaFire(guddafire[x][0], guddafire[x][1]);
            removeGuddaFireFromArray(x);
        }
        else
        {
            eraseGuddaFire(guddafire[x][0], guddafire[x][1]);
            guddafire[x][0] = guddafire[x][0] + 1;
            printGuddaFire(guddafire[x][0], guddafire[x][1]);
        }
    }
}

// Colissions detection of gudda with player's fire
void bulletCollisionWithGudda()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bullet[x][0] + 1 == guddaX && (bullet[x][1] == guddaY || bullet[x][1] == guddaY + 1 || bullet[x][1] == guddaY + 2 || bullet[x][1] == guddaY + 3))
        {
            addScore();
            eraseBullet(bullet[x][0], bullet[x][1]);
            removeBulletFromArray(x);
        }
    }
}

// collision detection of gudda's fire with player
void guddafireCollisionWithMalrio()
{
    for (int x = 0; x < guddafireCount; x++)
    {
        if (guddafire[x][0] + 1 == malrioX && (guddafire[x][1] == malrioY || guddafire[x][1] == malrioY + 1 || guddafire[x][1] == malrioY + 2))
        {
            eraseGuddaFire(guddafire[x][0], guddafire[x][1]);
            removeGuddaFireFromArray(x);
            health--;
        }
    }
}

// Function for the printin of the phuphi
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

// ERASE THE PHUPHI
void erasePhuphi(int x, int y)
{
    gotoxy(x, y);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
    gotoxy(x, y + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
    gotoxy(x, y + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
}

// FUCTION FOR MOVEMENT OF phuphi
void movePhuphi()
{

    if (direction1 == "LEFT")
    {
        char nextLocation = mazeArray[guddaY][phuphiX - 1];
        char nextLocation1 = mazeArray[guddaY + 1][phuphiX - 1];
        char nextLocation2 = mazeArray[guddaY + 2][phuphiX - 1];
        if (nextLocation != '#' && nextLocation1 != '#' && nextLocation2 != '#')
        {
            erasePhuphi(phuphiX, phuphiY);
            phuphiX = phuphiX - 1;
            printPhuphi(phuphiX, phuphiY);
        }
        else if (nextLocation == '#' || nextLocation1 == '#' || nextLocation2 == '#')
        {
            direction1 = "RIGHT";
        }
    }

    if (direction1 == "RIGHT")
    {
        char nextLocation = mazeArray[guddaY][phuphiX + 3];
        char nextLocation1 = mazeArray[guddaY + 1][phuphiX + 3];
        char nextLocation2 = mazeArray[guddaY + 2][phuphiX + 3];
        if (nextLocation == ' ' && nextLocation1 == ' ' && nextLocation2 == ' ')
        {
            erasePhuphi(phuphiX, phuphiY);
            phuphiX = phuphiX + 1;
            printPhuphi(phuphiX, phuphiY);
        }
        else if (nextLocation == '#' || nextLocation1 == '#' || nextLocation2 == '#')
        {
            direction1 = "LEFT";
        }
    }
}

// print the phuphi fire from screen
void printPhuphiFire(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}

// EARSING OF FIRE FROM THE PREVIOUS SCREEN
void erasePhuphiFire(int phuphifireX, int phuphifireY)
{
    gotoxy(phuphifireX, phuphifireY);
    cout << " ";
}

// FUNCTION FOR MOVEMENT OF phuphi FIRE
void movePhuphiFire()
{
    for (int x = 0; x < phuphifireCount; x++)
    {
        char next = getCharAtxy(phuphifire[x][0] - 3, phuphifire[x][1] + 1);
        if (next != ' ' || next == '#')
        {

            erasePhuphiFire(phuphifire[x][0], phuphifire[x][1]);
            removePhuphiFireFromArray(x);
        }
        else
        {

            erasePhuphiFire(phuphifire[x][0], phuphifire[x][1]);
            phuphifire[x][0] = phuphifire[x][0] - 1;
            printPhuphiFire(phuphifire[x][0], phuphifire[x][1]);
        }
    }
}

// REMOVAL OF FIRE FROM THE ARRAY OF phuphi FIRE
void removePhuphiFireFromArray(int index)
{
    for (int x = index; x < phuphifireCount - 1; x++)
    {
        phuphifire[x][0] = phuphifire[x + 1][0];
        phuphifire[x][1] = phuphifire[x + 1][1];
    }
    phuphifireCount--;
}

// FUNCTION TO GENERATE phupphiFIRE ON THE CONSOLE SCREEN
void generatePhuphiFire()
{
    phuphifire[phuphifireCount][0] = phuphiX - 1;
    phuphifire[phuphifireCount][1] = phuphiY;
    gotoxy(phuphiX - 5, phuphiY);
    cout << "-";
    phuphifireCount++;
}

// collision detection with phuphi
void bulletCollisionWithPhuphi()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bullet[x][0] + 1 == phuphiX && (bullet[x][1] == phuphiY || bullet[x][1] == phuphiY + 1 || bullet[x][1] == phuphiY + 2 || bullet[x][1] == phuphiY + 3))
        {
            addScore();
            eraseBullet(bullet[x][0], bullet[x][1]);
            removeBulletFromArray(x);
        }
    }
}

// collision detection of phuphi's fire with player
void phuphifireCollisionWithMalrio()
{
    for (int x = 0; x < phuphifireCount; x++)
    {
        if (phuphifire[x][0] + 1 == malrioX && (phuphifire[x][1] == malrioY || phuphifire[x][1] == malrioY + 1 || phuphifire[x][1] == malrioY + 2))
        {
            erasePhuphiFire(phuphifire[x][0], phuphifire[x][1]);
            removePhuphiFireFromArray(x);
            health--;
        }
    }
}

// GUN
// Function details for the GunEnemy
// function Print the gun
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
// PRINT FIRE ON THE SCREEN
void printFire(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}

// EARSING OF FIRE FROM THE PREVIOUS SCREEN
void eraseFire(int fireX, int fireY)
{
    gotoxy(fireX, fireY);
    cout << " ";
}

// FUNCTION FOR MOVEMENT OF GUN FIRE
void moveFire()
{
    for (int x = 0; x < fireCount; x++)
    {
        char next = getCharAtxy(fire[x][0] - 1, fire[x][1]);
        if (next != ' ')
        {
            eraseFire(fire[x][0], fire[x][1]);
            removeFireFromArray(x);
        }
        else
        {
            eraseFire(fire[x][0], fire[x][1]);
            fire[x][0] = fire[x][0] - 1;
            printFire(fire[x][0], fire[x][1]);
        }
    }
}

// REMOVAL OF FIRE FROM THE ARRAY OF GUN FIRE
void removeFireFromArray(int index)
{
    for (int x = index; x < fireCount - 1; x++)
    {
        fire[x][0] = fire[x + 1][0];
        fire[x][1] = fire[x + 1][1];
    }
    fireCount--;
}

// FUNCTION TO GENERATE FIRE ON THE CONSOLE SCREEN
void generateFire()
{
    fire[fireCount][0] = gunEnemyX - 5;
    fire[fireCount][1] = gunEnemyY;
    gotoxy(gunEnemyX - 5, gunEnemyY);
    cout << "X";
    fireCount++;
}

// collision detection of gunEnemy's fire with player
void fireCollisionWithMalrio()
{
    for (int x = 0; x < fireCount; x++)
    {
        if (fire[x][0] + 1 == malrioX && (fire[x][1] == malrioY || fire[x][1] == malrioY + 1 || fire[x][1] == malrioY + 2))
        {
            eraseFire(fire[x][0], fire[x][1]);
            removeBulletFromArray(x);
            health--;
        }
    }
}

// function for Print the devil Enemy
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

// erase the devil to go to the vertical up down
void eraseDevil(int x, int y)
{
    gotoxy(x, y);
    for (int idx = 0; idx < 4; idx++)
    {
        cout << " ";
    }
    gotoxy(x, y + 1);
    for (int idx = 0; idx < 4; idx++)
    {
        cout << " ";
    }
}

// move the devil up and down
void moveDevil()
{
    if (direction2 == "DOWN")
    {
        char nextLocation = getCharAtxy(devilX, devilY + 2);
        char nextLocation1 = getCharAtxy(devilX + 1, devilY + 2);
        if (nextLocation != '#' && nextLocation1 != '#')
        {
            eraseDevil(devilX, devilY);
            devilY = devilY + 1;
            printDevil(devilX, devilY);
        }
        else if (nextLocation == '#' && nextLocation1 == '#')
        {
            direction2 = "UP";
        }
    }

    if (direction2 == "UP")
    {
        char nextLocation = getCharAtxy(devilX, devilY - 1);
        char nextLocation1 = getCharAtxy(devilX + 1, devilY - 1);
        if (nextLocation != '#' && nextLocation1 != '#')
        {
            eraseDevil(devilX, devilY);
            devilY = devilY - 1;
            printDevil(devilX, devilY);
        }
        else if (nextLocation == '#' && nextLocation1 == '#')
        {
            direction2 = "DOWN";
        }
    }
}

// function for Print the devil fire
void printDevilFire(int x, int y)
{
    gotoxy(x, y);
    cout << char(254);
}
// function for erase the devil fire
void eraseDevilFire(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
// function for generate the devil fire
void generateDevilFire()
{
    devilFire[devilFireCount][0] = devilX + 4;
    devilFire[devilFireCount][1] = devilY;
    gotoxy(devilX + 4, devilY);
    cout << char(254);
    devilFireCount++;
}
// function for remove the devil fire
void removeDevilFireFromArray(int index)
{
    for (int x = index; x < devilFireCount - 1; x++)
    {
        devilFire[x][0] = devilFire[x + 1][0];
        devilFire[x][1] = devilFire[x + 1][1];
    }
    devilFireCount--;
}
// function for movement the devil fire
void moveDevilFire()
{
    for (int x = 0; x < devilFireCount; x++)
    {

        char next = getCharAtxy(devilFire[x][0] + 1, devilFire[x][1]);
        if (next != ' ')
        {

            eraseDevilFire(devilFire[x][0], devilFire[x][1]);
            removeDevilFireFromArray(x);
        }
        if (next == ' ')
        {
            eraseDevilFire(devilFire[x][0], devilFire[x][1]);
            devilFire[x][0] = devilFire[x][0] + 1;
            printDevilFire(devilFire[x][0], devilFire[x][1]);
        }
    }
}

// collision detection of gudda's fire with player
void devilfireCollisionWithMalrio()
{
    for (int x = 0; x < guddafireCount; x++)
    {
        if (devilFire[x][0] + 1 == malrioX && (devilFire[x][1] == malrioY || devilFire[x][1] == malrioY + 1 || devilFire[x][1] == malrioY + 2))
        {
           eraseDevilFire(devilFire[x][0], devilFire[x][1]);
            removeDevilFireFromArray(x);
            health--;
        }
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

// FUCTION TO ADD IN SCORE OF PLAYER
void addScore()
{
    score++;
}

// PRINT SCORE ON SCREEN
void printScore()
{
    gotoxy(6, 40);
    cout << "Score: " << score;
}

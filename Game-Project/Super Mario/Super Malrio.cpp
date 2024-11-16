#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
HANDLE acolor = GetStdHandle(STD_OUTPUT_HANDLE);
char getCharAtxy(short int x, short int y); // for chack the character at x,y coordinates
void gotoxy(int x, int y);                  // check x,y at maze

// set the directions at up down right left
string direction = "RIGHT";
string direction1 = "LEFT";
string direction2 = "UP";

// malrio coordinates
int malrioX = 8;
int malrioY = 6;

void printMalrio(int x, int y); // print malrio functio in maze
char mar1[3][3] = {
    {' ', '0', ' '},
    {'/', '|', char(209)},
    {'/', ' ', '\\'}}; // array for the printing of the player

void erase(int x, int y); // erase malrio function in maze

void playerMoveDown();  // function for movement of malrio in down side
void playerMoveUp();    // function for movement of malrio in up side
void playerMoveRight(); // function for movement of malrio in right side
void playerMoveLeft();  // function for movement of malrio in left side
void moveMalrioDown();  // gravity
void moveMalrioJumpright();
void moveMalrioJumpleft();

// player bullet data
int bullet_right[100][2]; // bullet array for right fire
int bullet_left[100][2];  // bullet array for left fire

int bulletCount = 0;                         // counters of bullets
int bulletCount1 = 0;                        // counters of bullets
void removeBulletFromArray_right(int index); // remove bulltees from the arrays(right)
void removeBulletFromArray_left(int index);  // remove bulltees from the arrays(left)
void generateBulletRight();                  // generate bullutes functionn(right)
void generateBulletLeft();                   // generate bullutes functionn(left)
void printBullet(int x, int y);              // function for the printing of bulletes
void eraseBullet(int x, int y);              // function for the erasing of bulletes
void moveBulletRight();                      // movememnt of bullets in their directions(right)
void moveBulletLeft();                       // movememnt of bullets in their directions(left)

// coordinates of master
int masterX = 60;
int masterY = 7;
void printMaster(int x, int y);   // print the master in maze
char master1[2][2] = {{'@', '@'}, // array 2d for tyhe master
                      {'-', '-'}};
void eraseMaster(int x, int y); //   erasing master in the maze
int master_time = 0;
void masterMove();                      // move the master in maze
void bulletCollisionWithMaster_right(); // collission detection of master with player(right)
void bulletCollisionWithMaster_left();  // collission detection of master with player(left)

// coordinates of gudda in maze
int guddaX = 80;
int guddaY = 14;
void printGudda(int x, int y); // print the gudda in maze
char gudda1[3][3] = {
    {'o', ' ', 'o'},
    {char(254), '|', char(254)},
    {char(254), char(254), char(254)}}; // array 2d for tyhe gudda

void eraseGudda(int x, int y); //   erasing gudda in the maze
void moveGudda();              // movement of gudda in right and left
int guddafire[100][2];         // gudda fire array in the game
int guddafireCount = 0;
void generateGuddaFire();                 // gereation of gudda fire
void printGuddaFire(int x, int y);        // printing of gudda fire
void eraseGuddaFire(int x, int y);        // removal of gudda fire or erasing
void removeGuddaFireFromArray(int index); // removal of gudda fire  from array
void moveGuddaFire();                     // movement of the gudda fire
void guddafireCollisionWithMalrio();      // collission detection of gudda fire with player(right)
void bulletCollisionWithGudda_right();    // collission detection player fire with (right)
void bulletCollisionWithGudda_left();     // collission detection of master with player(left)

// phuphi coordinates
int phuphiX = 130;
int phuphiY = 14;
void printPhuphi(int x, int y); // function to print phuphi
char phuphi1[3][3] = {{'o', '*', 'o'},
                      {char(254), '|', char(254)},
                      {char(254), char(254), char(254)}}; // array 2d for the phuphi
void movePhuphi();                                        // function for the movement of phuphi
void erasePhuphi(int x, int y);                           // function for the erase of phuphi
int phuphifire[100][2];                                   // array 2d for the phuphi bulletes
int phuphifireCount = 0;                                  // variable counter for the phuphi phiphi
void printPhuphiFire(int x, int y);                       // print phuphi fire function
void erasePhuphiFire(int x, int y);                       // erase phuphi fire function
void movePhuphiFire();                                    // move phuphi fire function
void removePhuphiFireFromArray(int index);                // remove phuphi fire phuphi fire function from array
void generatePhuphiFire();                                // generate phuphi fire function
void bulletCollisionWithPhuphi_right();                   // function for the collision of player bullet with phuphi right
void bulletCollisionWithPhuphi_left();                    // function for the collision of player bullet with phuphi left;
void phuphifireCollisionWithMalrio();                     // function for the collision of phuphi bullet with player

// key door coordinates
int doorX = 110;
int doorY = 13;
void printDoor();                 // function to print door
char door1[1][1] = {{char(176)}}; // array 2d to print door

int gunEnemyX = 182;
int gunEnemyY = 6;
void printGun(int x, int y);                    // function to print enemy gun
char gun1[1][4] = {{'<', '-', '-', char(254)}}; // array 2d to print enemy gun

int fire[100][2];                    // 2d array for fire
int fireCount = 0;                   // counter for the fire of gun
void generateFire();                 // generate function of fire
void printFire(int x, int y);        // print function of fire
void eraseFire(int x, int y);        // erase function of fire
void removeFireFromArray(int index); // remove function of fire from the array
void moveFire();                     // move function of fire
int gun_timer = 0;                   // variable for the fire move timer
void fireCollisionWithMalrio();      // function for the collision of gun bullet with player

// coordinates of devil
int devilX = 3;
int devilY = 20;
void printDevil(int x, int y); // function to print devil
char devil1[2][4] = {{char(254), char(254), '-', '>'},
                     {char(254), char(254), ' ', ' '}}; // array 2d for the devil printing in maze
void moveDevil();                                       // function to move devil
void eraseDevil(int x, int y);                          // function to erase devil

int devilFire[100][2];                    // devil fire array
int devilFireCount = 0;                   // devil fire counter
void removeDevilFireFromArray(int index); // function to devil fire from array
void generateDevilFire();                 // function to generate devvil fire
void printDevilFire(int x, int y);        // function to print devil fire
void eraseDevilFire(int x, int y);        // function to erase devil fire
void moveDevilFire();                     // function to move devil fire
void devilfireCollisionWithMalrio();      // function for the collision of devil bullet with player

int health = 20;                           // health variable for the player
int score = 0;                             // score variable for player score
int masterLife = 5;                        // master starting lives
void DecreaseMasterHealth();               // function for the decreasing master health
void addScore();                           // function for the add score
void printScore();                         // function for the print score
char mazeArray[38][189];                   // array maze
void loadMaze();                           // function for the load maze
void exitDoor();                           // function for the  print exit door
void gameWin();                            // function for the game win logo
void topHeader();                          // function for the header print
void logoOfMalrio();                       // function for the malrio logo print
void clearScreen();                        // function for the clear screen
void characters();                         // function for the print charcters
void letStart();                           // function for the game  sarting
void instruction();                        // function for the instruction print
int menu();                                // function for the manu print
void keys();                               // function for the keys print
fstream record;                            // record variable for comma field itteration
void storeGameData();                      // function for store game data
void loadGameRcord();                      // function for load game data
string getField(string record, int field); // function for read comma seperated data
int tempCount = 0;
void gameOver(); // header to print game over

main()
{
    // loadGameRcord();
    storeGameData();
    system("cls");
    system("Color 09");
    topHeader();
    getch();
    system("cls");
    logoOfMalrio();
    getch();
    system("cls");
    int option = 0;

    while (option != 5)
    {
        system("cls");
        topHeader();
        option = menu();

        if (option == 1)
        {
            clearScreen();
            topHeader();
            system("cls");
            letStart();
        }

        else if (option == 2)
        {
            clearScreen();
            topHeader();
            keys();
        }

        else if (option == 3)
        {
            clearScreen();
            topHeader();
            instruction();
        }
        else if (option == 4)
        {
            clearScreen();
            topHeader();
            characters();
        }
    }
}
void letStart()
{
    SetConsoleTextAttribute(acolor, 1);
    loadMaze();
    printMalrio(malrioX, malrioY);
    printGudda(guddaX, guddaY);
    printMaster(masterX, masterY);
    printPhuphi(phuphiX, phuphiY);
    printDevil(devilX, devilY);
    printGun(gunEnemyX, gunEnemyY);
    gotoxy(doorX, doorY);
    cout << char(176);
    bool m_alive = true;
    bool gameRunning = true;
    while (gameRunning)
    {
        printScore();
        if (masterLife == 0)
        {
            m_alive = false;
            eraseMaster(masterX, masterY);
        }
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
            generateBulletRight();
        }
        if (GetAsyncKeyState(0x42))
        {
            generateBulletLeft();
        }

        if (master_time >= 3)
        {
            moveGudda();
            if (masterLife > 0 && m_alive == true)
            {
                masterMove();
            }
            else
            {
            }

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

        if (tempCount % 5 == 0)
        {
            moveMalrioDown();
        }
        tempCount++;
        gun_timer++;
        moveFire();
        moveBulletRight();
        moveBulletLeft();
        moveGuddaFire();
        movePhuphiFire();
        moveDevilFire();
        master_time++;
        Sleep(20);

        bulletCollisionWithMaster_right();
        bulletCollisionWithMaster_left();
        bulletCollisionWithGudda_left();
        bulletCollisionWithGudda_right();
        guddafireCollisionWithMalrio();
        bulletCollisionWithPhuphi_right();
        bulletCollisionWithPhuphi_left();
        phuphifireCollisionWithMalrio();
        fireCollisionWithMalrio();
        devilfireCollisionWithMalrio();

        gotoxy(20, 40);
        cout << "Health: " << health << " ";
        gotoxy(20, 41);
        cout << "Master's Life : " << masterLife << " ";
        gotoxy(181, 31);
        cout << "EXIT";

        if (masterLife == 0)
        {
            for (int idx = 0; idx < 3; idx++)
            {
                gotoxy(176, 6 + idx);
                for (int i = 0; i < 1; i++)
                {
                    cout << "#";
                }
            }
        }

        if (malrioX == doorX && (malrioY == doorY || malrioY + 1 == doorY || malrioY + 2 == doorY))
        {
            exitDoor();
        }

        if (score == 30)
        {
            storeGameData();
            gameRunning = false;
        }

        if (health == 0)
        {
            storeGameData();
            // Sleep(1000);
            // gameOver();
            gameRunning = false;
        }

        if (getCharAtxy(malrioX + 5, malrioY + 1) == char(178) || getCharAtxy(malrioX + 2, malrioY + 4) == char(178))
        {
            gameWin();
            Sleep(5000);
            getch();

            break;
        }
        storeGameData();
    }
}

void gameWin()
{
    SetConsoleTextAttribute(acolor, 10);
    system("cls");
    gotoxy(50, 20);
    Sleep(200);
    cout << "##    ##  #######  ##     ##    ##      ##  #######  ##    ## " << endl;
    Sleep(200);
    gotoxy(50, 21);
    cout << " ##  ##  ##     ## ##     ##    ##  ##  ## ##     ## ###   ## " << endl;
    Sleep(200);
    gotoxy(50, 22);
    cout << "  ####   ##     ## ##     ##    ##  ##  ## ##     ## ####  ## " << endl;
    Sleep(200);
    gotoxy(50, 23);
    cout << "   ##    ##     ## ##     ##    ##  ##  ## ##     ## ## ## ## " << endl;
    Sleep(200);
    gotoxy(50, 24);
    cout << "   ##    ##     ## ##     ##    ##  ##  ## ##     ## ##  #### " << endl;
    Sleep(200);
    gotoxy(50, 25);
    cout << "   ##    ##     ## ##     ##    ##  ##  ## ##     ## ##   ### " << endl;
    Sleep(200);
    gotoxy(50, 26);
    cout << "   ##     #######   #######      ###  ###   #######  ##    ## " << endl;
}

void instruction()
{
    SetConsoleTextAttribute(acolor, 12);
    cout << "\t"
            "                  ******************************* "
         << endl;
    cout << "\t"
            "                 |                               |"
         << endl;
    cout << "\t"
            "                 |          Instructions         |"
         << endl;
    cout << "\t"
            "                  ******************************* "
         << endl;
    cout << endl
         << endl
         << endl;
    cout << "\t"
            "    1.MALRIO is a game in which there is only one Player name as Malrio.            "
         << endl
         << endl;
    cout << "\t"
            "    2. In this game there are 5 enemies, (4 enimies and a gun). "
         << endl
         << endl;
    cout << "\t"
            "    3. Press the Space bar to release fire.                                      "
         << endl
         << endl;
    cout << "\t"
            "    4. When the bullet hits the Enemy , the score will add by '1' per bullet.    "
         << endl
         << endl;
    cout << "\t"
            "    5. MALRIO should have to eat 3 score pallets.to end the game           "
         << endl
         << endl;
    cout << "\t"
            "    6. The goal of the game is to reach the top lower  corner of th maze to eat   "
         << endl
         << endl;
    cout << "\t"
            "    7. GUDDA & PHUPHI fire on left to right and right toleft Respectively.                                             "
         << endl
         << endl;

    cout << endl;
    cout << "\t"
            "  Press Any Key to Continue .. !"
         << endl;

    getch();
}

void logoOfMalrio()
{
    SetConsoleTextAttribute(acolor, 10);
    cout << "                                                      ...                          " << endl;
    cout << "                                                     .....                         " << endl;
    cout << "                                                   ........                                 " << endl;
    cout << "                                                   :.......                               " << endl;
    cout << "                                                  ..-:.::....                            " << endl;
    cout << "                                                   :===:.::..  ..                         " << endl;
    cout << "                                                    =+=--=-...:...                         " << endl;
    cout << "                                                  ..::-++==--=:...:--:.....               " << endl;
    cout << "                                                 :=-:. =*++*+=-::-=*=:....:.              " << endl;
    cout << "                                                 -=++++***++*=++=--=::...::.              " << endl;
    cout << "                             :=+*#%%%##**+-:.     -+*##*+++++=+**+=-::..::-.              " << endl;
    cout << "                          -*%%*+===+*%%%%%%%%%*=:  =+++++++==++*+==--::::-=.              " << endl;
    cout << "                        -#@#=   =%+:  =%%%%%%@@@@@*-:=++++==++***++==----==               " << endl;
    cout << "                      .#@@=.###*%:=%#=.*%%%%%@@@@@@@%*=:-++==+**##***+++==-               " << endl;
    cout << "                     :%@@#.-%=.::  :+*:#%%%%@@@@@@@@@@@@*+==++++*###*+=-:.                " << endl;
    cout << "                    .%@@@#:*%+....:==+#%%%@@@@@@@@@@@@@@@@#**+++*+=--::::::-              " << endl;
    cout << "                    #@@@@@#+===*#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%=               " << endl;
    cout << "                   =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%:               " << endl;
    cout << "                   #@@@@@@@@@@@@@@@@@%##*@@@@%%%%#*#%%@@@@@@@@@@@@@@%%%%%%:               " << endl;
    cout << "                  .@@@@@@@@@@@@@%#***++=+@+=--=++*****#%@@@@@@@@@@@@@%%%%%.               " << endl;
    cout << "                  -@@@@@@@@@@@@@%+==-----=:..  :=+******%@@@@@@@@@@@%%%%%*                " << endl;
    cout << "                  -@@@@@@@@@@##*##=-----::-==+-..-+*****%@@@@@@@@@@@%%%%%+                " << endl;
    cout << "                  .@@@@@@@%%++=--=++==--:::%#@%-. :=+***#%@@@@@@@@@@%%%%%-                " << endl;
    cout << "                   *@@@@@#**+=::=++*==--::::-=#=: .:-#%#*#@@@@@@@@@%%%%%%.                " << endl;
    cout << "                   .%@@@@#**+=--+@*=----:::::::-.:-*%%%@*#@@@@@@@@@@@@%%#                 " << endl;
    cout << "                    .#@@@%**+=--=+====---------+*%%##%@%-+@@@@@@@@@@@@@%+                 " << endl;
    cout << "                      =%@@%**+===*++++========+###*#%@-::=@@@@@@@%@@@@@%:                 " << endl;
    cout << "                       -*%%%**==+***********####%@@@@+:--=@@@@@@@%@@@@@%                  " << endl;
    cout << "                      -###@@*@@@@@@%###%%%%@@@@@@++=-----#@@@@@@@%@@@@@*                 " << endl;
    cout << "                      -#**%%*%@@@@@@@@@@@@@%%%%#+++-=====%@@@@@@@%@@@@@-                  " << endl;
    cout << "                       =***%***#*%@@@%%%@%###*#%@@*-====+%@@@@@@@%@%@@@.                  " << endl;
    cout << "                        :+******#####**#*%@@@@@@@%--===+#%%@@@@@@%%%%%#                   " << endl;
    cout << "             ...    .:::-:-=+****####*******###*+====+*##***#%@@%%%%%@%=                  " << endl;
    cout << "            :---------:-===+:   -+*########**+***+=+*%%%#*+++*#%%%%%%%%%-                 " << endl;
    cout << "           =-.    .:-::-=+**      .:-=++#########%%%%%%%**++++#%%%%%%%%%:                " << endl;
    cout << "           ::::::::::=++**++*=         :*%%@@@@@%%%%%%%%%#**++++*%%%%%%%%%.               " << endl;
    cout << "          :=--.   .-+*+*++++++        *##*%%@@%%%%%%%%#**#**=--::-*#%%%%%%#               " << endl;
    cout << "         :::......::-=::-==*-      :*##**#%%%%%###********+------:***#%%%%=              " << endl;
    cout << "         ====--=+**++-   .:+:-   .*@%#*+********************+====+*****#%%%.             " << endl;
    cout << "          ::..   ..=*=     :: #%#*%@@#=--:+#####**********************++***#+             " << endl;
    cout << "         -==++++===-     .- =%%@@@@%+==--+***************+**********++++*****            " << endl;
    cout << "           =*###*#*=:::::-=.=%%%@@@@%**++*####*************+++*******++++*****            " << endl;
    cout << "            .-+*###******+:+%%%@@@@%##*******###****************+++++++++*****:           " << endl;
    cout << "               .:-=*###*==#@@@@@@%#*******++++********************************=           " << endl;
    cout << "                    :====*%@@@@@##******+++++++******************************#*           " << endl;
    cout << "                            :=%#*******+++++++******#************************##           " << endl;
    cout << "                            .*#******++++++++*******####********************###           " << endl;
    cout << "                    :-=+***+*#******++++++++*******##########*************####*           " << endl;
    cout << "                -*#######**********+++++++*+****#############################-           " << endl;
    cout << "              .*%%%%#####***++++*****+++++*****#####%#%%#####################            " << endl;
    cout << "               #%%%%%%%%####**+++++******+*+***#%%%%%%%%%%%%%################=            " << endl;
    cout << "              =%%%%%###***#####**+++******+****#%@%%%%%%%%%%%%%%%%%%%#######%.            " << endl;
    cout << "              +%%#######****++**##*****###*****#%%@@@@@%%%%%%%%%%%%#########*             " << endl;
    cout << "              -%%%%############***#########***#:     :=%%%%%%%%%%###########.             " << endl;
    cout << "              .%%%%%%%%%%#########**%%%%#####*#       -%%%%%%%%############=              " << endl;
    cout << "               +%%%%%%%%%%%%%%%%%#####%%%%%%%##       #%%%%%%#############*               " << endl;
    cout << "                =%%%%%%%%%%%%%%%%%%%%%#%@%%%%%-      -%%%%%###############.               " << endl;
    cout << "                 :*%%%%%%%@@@@@@@@@%%%#**%%%%%       #%%%%###############:                " << endl;
    cout << "                   .=*%@@@@@@@@%%#######***%@#      *%%%%###############.                 " << endl;
    cout << "                         *%%%%%%%%%%%%%%#####:     =%%%%##############%-                  " << endl;
    cout << "                          -*%@@@@@@%%%%%%%%%.     -%%%###############%+                   " << endl;
    cout << "                             :-+*#%@@%%#*+-      +%%%#################.                   " << endl;
    cout << "                                               :#%%%#################.                    " << endl;
    cout << "                                              .%%%%################%:                     " << endl;
    cout << "                                              *%%#################%-                      " << endl;
    cout << "                                             -%%%####****########%=                       " << endl;
    cout << "                                            .%######**********##%+                        " << endl;
    cout << "                                            *%##*******##*****##*                         " << endl;
    cout << "                                           =%##****++++=++**###%:                         " << endl;
    cout << "                                          #%##***++======+++**#.                         " << endl;
    cout << "                                           %%###***++======++*#*                          " << endl;
    cout << "                                           #%%####***+++++++**#-                          " << endl;
    cout << "                                           =%%%%%%####*******#*                           " << endl;
    cout << "                                            *%@@@@%%%%%#######.                           " << endl;
    cout << "                                             =#%@@@@@@@@@@@%+.                            " << endl;
    cout << "                                               :=*%@@@@@@*-                               " << endl;
}

void topHeader()
{
    SetConsoleTextAttribute(acolor, 3);
    gotoxy(50, 17);
    Sleep(200);
    cout << "                 __       __   ______   __        _______   ______   ______             " << endl;
    gotoxy(50, 18);
    Sleep(200);
    cout << "                / \\     /   | /     \\ /  |       /       \\ /      |/      \\            " << endl;
    gotoxy(50, 19);
    Sleep(200);
    cout << "                $$ \\   /$$  |/$$$$$$  |$$ |      $$$$$$$  |$$$$$$/ /$$$$$$  |            " << endl;
    gotoxy(50, 20);
    Sleep(200);
    cout << "                $$$ \\ /$$$  |$$ |__$$ |$$ |      $$ |__$$ |  $$ |  $$ |  $$ |            " << endl;
    gotoxy(50, 21);
    Sleep(200);
    cout << "                $$$$  /$$$$ |$$    $$ |$$ |      $$    $$<   $$ |  $$ |  $$ |            " << endl;
    gotoxy(50, 22);
    Sleep(200);
    cout << "                $$ $$ $$/$$ |$$$$$$$$ |$$ |      $$$$$$$  |  $$ |  $$ |  $$ |            " << endl;
    gotoxy(50, 23);
    Sleep(200);
    cout << "                $$ |$$$/ $$ |$$ |  $$ |$$ |_____ $$ |  $$ | _$$ |_ $$\\__ $$ |            " << endl;
    gotoxy(50, 24);
    Sleep(200);
    cout << "                $$ | $/  $$ |$$ |  $$ |$$       |$$ |  $$ |/ $$   |$$    $$/              " << endl;
    gotoxy(50, 25);
    Sleep(200);
    cout << "                $$/      $$/ $$/   $$/ $$$$$$$$/ $$/   $$/ $$$$$$/  $$$$$$/              " << endl;
}

void characters()
{
    SetConsoleTextAttribute(acolor, 4);
    cout << "MALRIO >>>>>>>>>>>>>>" << endl;
    for (int idx = 0; idx < 3; idx++)
    {
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout << mar1[idx][idx1];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(acolor, 4);
    cout << "MASTER >>>>>>>>>>>>>>>" << endl;

    for (int idx = 0; idx < 2; idx++)
    {
        for (int idx1 = 0; idx1 < 2; idx1++)
        {
            cout << master1[idx][idx1];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    SetConsoleTextAttribute(acolor, 4);

    cout << "GUDDA >>>>>>>>>>>>>>>" << endl;
    for (int idx = 0; idx < 3; idx++)
    {
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout << gudda1[idx][idx1];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(acolor, 4);

    cout << "PHUPHI >>>>>>>>>>>>>>>" << endl;
    for (int idx = 0; idx < 3; idx++)
    {
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout << phuphi1[idx][idx1];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(acolor, 4);

    cout << "Devil >>>>>>>>>>>>>>>" << endl;
    for (int idx = 0; idx < 2; idx++)
    {
        for (int idx1 = 0; idx1 < 4; idx1++)
        {
            cout << devil1[idx][idx1];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(acolor, 4);

    cout << "Gun Enemy >>>>>>>>>>>>>>>" << endl;
    for (int idx = 0; idx < 1; idx++)
    {
        for (int idx1 = 0; idx1 < 4; idx1++)
        {
            cout << gun1[idx][idx1];
        }
    }

    getch();
}

int menu()
{
    SetConsoleTextAttribute(acolor, 12);

    int option;
    gotoxy(50, 27);
    Sleep(200);
    cout << "\t"
            "      _______________________________ "
         << endl;
    gotoxy(50, 28);
    Sleep(200);
    cout << "\t"
            "     |                               |"
         << endl;
    gotoxy(50, 29);
    Sleep(200);
    cout << "\t"
            "     |           Menu                |"
         << endl;
    gotoxy(50, 30);
    Sleep(200);
    cout << "\t"
            "     |_______________________________|"
         << endl;
    gotoxy(50, 31);
    Sleep(200);
    cout << "\t"
            "                                      "
         << endl;
    gotoxy(50, 32);
    Sleep(200);
    cout << "\t"
            "      1.Start Game                    "
         << endl;
    gotoxy(50, 33);
    Sleep(200);
    cout << "\t"
            "      2.Keys                          "
         << endl;
    gotoxy(50, 34);
    Sleep(200);
    cout << "\t"
            "      3.Instructions                  "
         << endl;
    gotoxy(50, 35);
    Sleep(200);
    cout << "\t"
            "      4.Characters                    "
         << endl;
    gotoxy(50, 36);
    Sleep(200);
    cout << "\t"
            "      5.Exit                          "
         << endl;
    gotoxy(50, 37);
    Sleep(200);
    cout << endl;
    gotoxy(50, 37);
    Sleep(200);
    cout << "\t"
            " Select any option..";
    cin >> option;

    return option;
}

void keys()
{

    cout << "\t"
            "      _______________________________ "
         << endl;
    cout << "\t"
            "     |                               |"
         << endl;
    cout << "\t"
            "     |            Keys               |"
         << endl;
    cout << "\t"
            "     |_______________________________|"
         << endl;
    cout << endl;
    cout << "\t"
            "     1. Up                 Go up    "
         << endl;
    cout << "\t"
            "                  ^      "
         << endl;
    cout << "\t"
            "                  |      "
         << endl;
    cout << endl;
    cout << "\t"
            "     2. Down               Go Down  "
         << endl;
    cout << "\t"
            "                  |      "
         << endl;
    cout << "\t"
            "                  V      "
         << endl;
    cout << endl;
    cout << "\t"
            "     3. Left               Go Left  "
         << endl;
    cout << "\t"
            "                <----       "
         << endl;
    cout << endl;
    cout << "\t"
            "     4. Right              Go Right "
         << endl;
    cout << "\t"
            "                ----->     "
         << endl;
    cout << endl;
    cout << "\t"
            "     5. Space,B              Fire     "
         << endl;
    cout << endl
         << endl;
    // cout << "\t"
    //         "     6. Esc                End Game "
    //      << endl;
    // cout << endl;
    cout << "\t"
            " Press any key to continue ..!"
         << endl;

    getch();
}

void clearScreen()
{
    cout << " Press any Key to Continue ! " << endl;
    getch();
    system("cls");
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
    if ((nextLocation1 == '+' || nextLocation == '+' || nextLocation2 == '+'))
    {
        score++;
    }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        erase(malrioX, malrioY);
        malrioX = malrioX - 1;
        printMalrio(malrioX, malrioY);
    }
    else if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == char(254) || nextLocation == char(254) || nextLocation2 == char(254)))
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
    if ((nextLocation1 == '+' || nextLocation == '+' || nextLocation2 == '+'))
    {
        score++;
    }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        erase(malrioX, malrioY);
        malrioX = malrioX + 1;
        printMalrio(malrioX, malrioY);
    }
    else if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        health--;
    }

    else if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == char(254) || nextLocation == char(254) || nextLocation2 == char(254)))
    {
        health--;
    }

    if (nextLocation1 == char(178) && nextLocation == char(178) && nextLocation2 == char(178))
    {
        system("cls");
        Sleep(50);
        gameWin();
    }
}

// FUNCTION TO MOVE PLAYER RIGHT
void playerMoveUp()
{
    char nextLocation = mazeArray[malrioY - 1][malrioX];
    char nextLocation1 = mazeArray[malrioY - 1][malrioX + 1];
    char nextLocation2 = mazeArray[malrioY - 1][malrioX + 2];
    if ((nextLocation1 == '+' || nextLocation == '+' || nextLocation2 == '+'))
    {
        score++;
    }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        erase(malrioX, malrioY);
        malrioY = malrioY - 1;
        printMalrio(malrioX, malrioY);
    }

    else if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        health--;
    }

    else if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == char(254) || nextLocation == char(254) || nextLocation2 == char(254)))
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

    if ((nextLocation1 == '+' || nextLocation == '+' || nextLocation2 == '+'))
    {
        score++;
    }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        erase(malrioX, malrioY);
        malrioY = malrioY + 1;
        printMalrio(malrioX, malrioY);
    }

    else if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-') || (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        health--;
    }

    else if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == char(254) || nextLocation == char(254) || nextLocation2 == char(254)))
    {
        health--;
    }

    if ((nextLocation1 == '%' || nextLocation == '%' || nextLocation2 == '%'))
    {
        // Sleep(1000);
        // gameOver();
        exit(0);
    }
}

void moveMalrioDown()
{
    bool flag = true;
    char next;
    char next1;
    char next2;
    while (flag)
    {
        next = getCharAtxy(malrioX, malrioY + 3);
        next1 = getCharAtxy(malrioX + 1, malrioY + 3);
        next2 = getCharAtxy(malrioX + 2, malrioY + 3);

        if (next == ' ' && next1 == ' ' && next2 == ' ')
        {
            erase(malrioX, malrioY);
            malrioY = malrioY + 1;
            printMalrio(malrioX, malrioY);
        }
        else
        {
            flag = false;
        }
        if (next == '%' || next1 == '%' || next2 == '%')
            // Sleep(1000);
            // gameOver();
            exit(0);
    }
}

void gameOver()
{

    gotoxy(5, 20);
    Sleep(200);
    cout << "        GGGGGGGGGGGGG               AAA               MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE          OOOOOOOOO     VVVVVVVV           VVVVVVVVEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRRR   " << endl;
    gotoxy(5, 21);
    Sleep(200);
    cout << "     GGG::::::::::::G              A:::A              M:::::::M             M:::::::ME::::::::::::::::::::E        OO:::::::::OO   V::::::V           V::::::VE::::::::::::::::::::ER::::::::::::::::R  " << endl;
    gotoxy(5, 22);
    Sleep(200);
    cout << "   GG:::::::::::::::G             A:::::A             M::::::::M           M::::::::ME::::::::::::::::::::E      OO:::::::::::::OO V::::::V           V::::::VE::::::::::::::::::::ER::::::RRRRRR:::::R " << endl;
    gotoxy(5, 23);
    Sleep(200);
    cout << "  G:::::GGGGGGGG::::G            A:::::::A            M:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E     O:::::::OOO:::::::OV::::::V           V::::::VEE::::::EEEEEEEEE::::ERR:::::R     R:::::R" << endl;
    gotoxy(5, 24);
    Sleep(200);
    cout << " G:::::G       GGGGGG           A:::::::::A           M::::::::::M       M::::::::::M  E:::::E       EEEEEE     O::::::O   O::::::O V:::::V           V:::::V   E:::::E       EEEEEE  R::::R     R:::::R" << endl;
    gotoxy(5, 25);
    Sleep(200);
    cout << "G:::::G                        A:::::A:::::A          M:::::::::::M     M:::::::::::M  E:::::E                  O:::::O     O:::::O  V:::::V         V:::::V    E:::::E               R::::R     R:::::R" << endl;
    gotoxy(5, 26);
    Sleep(200);
    cout << "G:::::G                       A:::::A A:::::A         M:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE        O:::::O     O:::::O   V:::::V       V:::::V     E::::::EEEEEEEEEE     R::::RRRRRR:::::R " << endl;
    gotoxy(5, 27);
    Sleep(200);
    cout << "G:::::G    GGGGGGGGGG        A:::::A   A:::::A        M::::::M M::::M M::::M M::::::M  E:::::::::::::::E        O:::::O     O:::::O    V:::::V     V:::::V      E:::::::::::::::E     R:::::::::::::RR  " << endl;
    gotoxy(5, 28);
    Sleep(200);
    cout << "G:::::G    G::::::::G       A:::::A     A:::::A       M::::::M  M::::M::::M  M::::::M  E:::::::::::::::E        O:::::O     O:::::O     V:::::V   V:::::V       E:::::::::::::::E     R::::RRRRRR:::::R " << endl;
    gotoxy(5, 29);
    Sleep(200);
    cout << "G:::::G    GGGGG::::G      A:::::AAAAAAAAA:::::A      M::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE        O:::::O     O:::::O      V:::::V V:::::V        E::::::EEEEEEEEEE     R::::R     R:::::R" << endl;
    gotoxy(5, 30);
    Sleep(200);
    cout << "G:::::G        G::::G     A:::::::::::::::::::::A     M::::::M    M:::::M    M::::::M  E:::::E                  O:::::O     O:::::O       V:::::V:::::V         E:::::E               R::::R     R:::::R" << endl;
    gotoxy(5, 31);
    Sleep(200);
    cout << " G:::::G       G::::G    A:::::AAAAAAAAAAAAA:::::A    M::::::M     MMMMM     M::::::M  E:::::E       EEEEEE     O::::::O   O::::::O        V:::::::::V          E:::::E       EEEEEE  R::::R     R:::::R" << endl;
    gotoxy(5, 32);
    Sleep(200);
    cout << "  G:::::GGGGGGGG::::G   A:::::A             A:::::A   M::::::M               M::::::MEE::::::EEEEEEEE:::::E     O:::::::OOO:::::::O         V:::::::V         EE::::::EEEEEEEE:::::ERR:::::R     R:::::R" << endl;
    gotoxy(5, 33);
    Sleep(200);
    cout << "   GG:::::::::::::::G  A:::::A               A:::::A  M::::::M               M::::::ME::::::::::::::::::::E      OO:::::::::::::OO           V:::::V          E::::::::::::::::::::ER::::::R     R:::::R" << endl;
    gotoxy(5, 34);
    Sleep(200);
    cout << "     GGG::::::GGG:::G A:::::A                 A:::::A M::::::M               M::::::ME::::::::::::::::::::E        OO:::::::::OO              V:::V           E::::::::::::::::::::ER::::::R     R:::::R" << endl;
    gotoxy(5, 35);
    Sleep(200);
    cout << "        GGGGGG   GGGGAAAAAAA                   AAAAAAAMMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE          OOOOOOOOO                 VVV            EEEEEEEEEEEEEEEEEEEEEERRRRRRRR     RRRRRRR" << endl;
    gotoxy(5, 36);
    Sleep(200);
}

// }

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

// REMOVE BULLET FROM THE ARRAY OF MALRIO GUN
void removeBulletFromArray_right(int index)
{
    for (int x = index; x < bulletCount - 1; x++)
    {
        bullet_right[x][0] = bullet_right[x + 1][0];
        bullet_right[x][1] = bullet_right[x + 1][1];
    }
    bulletCount--;
}

void removeBulletFromArray_left(int index)
{
    for (int x = index; x < bulletCount1 - 1; x++)
    {
        bullet_left[x][0] = bullet_left[x + 1][0];
        bullet_left[x][1] = bullet_left[x + 1][1];
    }
    bulletCount1--;
}

// GENERATE A BULLET FROM THE MALRIO GUN
void generateBulletRight()
{
    bullet_right[bulletCount][0] = malrioX + 4;
    bullet_right[bulletCount][1] = malrioY + 1;
    char next = getCharAtxy(bullet_right[bulletCount][0], bullet_right[bulletCount][1]);
    if (next != '#')
    {
        gotoxy(malrioX + 4, malrioY + 1);
        cout << ".";
        bulletCount++;
    }
}
// MOVEMENT OF MALRIO GUN BULLETES
void moveBulletRight()
{
    for (int x = 0; x < bulletCount; x++)
    {
        char next = getCharAtxy(bullet_right[x][0] + 1, bullet_right[x][1]);
        if (next != ' ')
        {
            eraseBullet(bullet_right[x][0], bullet_right[x][1]);
            removeBulletFromArray_right(x);
        }
        else if (next == ' ')
        {
            eraseBullet(bullet_right[x][0], bullet_right[x][1]);
            bullet_right[x][0] = bullet_right[x][0] + 1;
            printBullet(bullet_right[x][0], bullet_right[x][1]);
        }
    }
}
// GENERATE A BULLET FROM THE MALRIO GUN
void generateBulletLeft()
{
    bullet_left[bulletCount1][0] = malrioX - 1;
    bullet_left[bulletCount1][1] = malrioY + 1;
    char next = getCharAtxy(bullet_left[bulletCount1][0], bullet_left[bulletCount1][1]);
    if (next != '#')
    {
        gotoxy(malrioX - 1, malrioY + 1);
        cout << ".";
        bulletCount1++;
    }
}
// MOVEMENT OF MALRIO GUN BULLETES
void moveBulletLeft()
{
    for (int x = 0; x < bulletCount1; x++)
    {
        char next = getCharAtxy(bullet_left[x][0] - 1, bullet_left[x][1]);
        if (next != ' ')
        {
            eraseBullet(bullet_left[x][0], bullet_left[x][1]);
            removeBulletFromArray_left(x);
        }
        else if (next == ' ')
        {
            eraseBullet(bullet_left[x][0], bullet_left[x][1]);
            bullet_left[x][0] = bullet_left[x][0] - 1;
            printBullet(bullet_left[x][0], bullet_left[x][1]);
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
        SetConsoleTextAttribute(acolor, 10);
        gotoxy(masterX, masterY + idx);
        for (int idx1 = 0; idx1 < 2; idx1++)
        {
            cout << master1[idx][idx1];
        }
        cout << endl;
    }
}

void masterMove()
{
    int coordinatesX = masterX - malrioX; // difference for chase
    int coordinatesY = masterY - malrioY;

    if (coordinatesX > 0) // left
    {
        char nextlocation = getCharAtxy(masterX - 1, masterY);
        char nextlocation1 = getCharAtxy(masterX - 1, masterY + 1);
        if (nextlocation == '0' || nextlocation == '\\' || nextlocation == '/' || nextlocation1 == '0' || nextlocation1 == '\\' || nextlocation1 == '/')
        {
            health--;
        }
        if (nextlocation == ' ' && nextlocation1 == ' ')
        {
            eraseMaster(masterX, masterY);
            masterX = masterX - 1;
            printMaster(masterX, masterY);
        }
    }
    if (coordinatesX < 0) // right
    {
        char nextlocation = getCharAtxy(masterX + 3, masterY);
        char nextlocation1 = getCharAtxy(masterX + 3, masterY + 1);
        if (nextlocation == 'O' || nextlocation == '\\' || nextlocation == '/' || nextlocation1 == 'O' || nextlocation1 == '\\' || nextlocation1 == '/')
        {
            health--;
        }
        if (nextlocation == ' ' && nextlocation1 == ' ')
        {
            eraseMaster(masterX, masterY);
            masterX = masterX + 1;
            printMaster(masterX, masterY);
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
void bulletCollisionWithMaster_left()
{
    for (int x = 0; x < bulletCount1; x++)
    {
        if (bullet_left[x][0] + 1 == masterX && (bullet_left[x][1] == masterY || bullet_left[x][1] == masterY + 1 || bullet_left[x][1] == masterY + 2 || bullet_left[x][1] == masterY + 3))
        {
            DecreaseMasterHealth();
            addScore();
            eraseBullet(bullet_left[x][0], bullet_left[x][1]);
            removeBulletFromArray_left(x);
        }
    }
}

void DecreaseMasterHealth()
{
    masterLife--;
}

// Collision detection With the master
void bulletCollisionWithMaster_right()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bullet_right[x][0] + 1 == masterX && (bullet_right[x][1] == masterY || bullet_right[x][1] == masterY + 1 || bullet_right[x][1] == masterY + 2 || bullet_right[x][1] == masterY + 3))
        {
            DecreaseMasterHealth();
            addScore();
            eraseBullet(bullet_right[x][0], bullet_right[x][1]);
            removeBulletFromArray_right(x);
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
    if (devilX == malrioX || (devilY - malrioY > 0 && devilY - malrioY < 6))
    {
        guddafire[guddafireCount][0] = guddaX + 4;
        guddafire[guddafireCount][1] = guddaY;
        gotoxy(guddaX + 4, guddaY);
        cout << "-";
        guddafireCount++;
    }
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
void bulletCollisionWithGudda_right()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bullet_right[x][0] + 1 == guddaX && (bullet_right[x][1] == guddaY || bullet_right[x][1] == guddaY + 1 || bullet_right[x][1] == guddaY + 2 || bullet_right[x][1] == guddaY + 3))
        {
            addScore();
            eraseBullet(bullet_right[x][0], bullet_right[x][1]);
            removeBulletFromArray_right(x);
        }
    }
}

void bulletCollisionWithGudda_left()
{
    for (int x = 0; x < bulletCount1; x++)
    {
        if (bullet_left[x][0] + 1 == guddaX && (bullet_left[x][1] == guddaY || bullet_left[x][1] == guddaY + 1 || bullet_left[x][1] == guddaY + 2 || bullet_left[x][1] == guddaY + 3))
        {
            addScore();
            eraseBullet(bullet_left[x][0], bullet_left[x][1]);
            removeBulletFromArray_left(x);
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
    if (devilX == malrioX || (devilY - malrioY > 0 && devilY - malrioY < 6))
    {
        phuphifire[phuphifireCount][0] = phuphiX - 1;
        phuphifire[phuphifireCount][1] = phuphiY;
        gotoxy(phuphiX - 5, phuphiY);
        cout << "-";
        phuphifireCount++;
    }
}

// collision detection with phuphi
void bulletCollisionWithPhuphi_left()
{
    for (int x = 0; x < bulletCount1; x++)
    {
        if (bullet_left[x][0] + 1 == phuphiX && (bullet_left[x][1] == phuphiY || bullet_left[x][1] == phuphiY + 1 || bullet_left[x][1] == phuphiY + 2 || bullet_left[x][1] == phuphiY + 3))
        {
            addScore();
            eraseBullet(bullet_left[x][0], bullet_left[x][1]);
            removeBulletFromArray_left(x);
        }
    }
}

void bulletCollisionWithPhuphi_right()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bullet_right[x][0] + 1 == phuphiX && (bullet_right[x][1] == phuphiY || bullet_right[x][1] == phuphiY + 1 || bullet_right[x][1] == phuphiY + 2 || bullet_right[x][1] == phuphiY + 3))
        {
            addScore();
            eraseBullet(bullet_right[x][0], bullet_right[x][1]);
            removeBulletFromArray_right(x);
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
        if (next != ' ' || next == '{')
        {
            eraseFire(fire[x][0], fire[x][1]);
            removeFireFromArray(x);
        }
        else if (next != '{')
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
            removeFireFromArray(x);
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

    if (devilX == malrioX || (devilY - malrioY > 0 && devilY - malrioY < 6))
    {
        devilFire[devilFireCount][0] = devilX + 4;
        devilFire[devilFireCount][1] = devilY;
        gotoxy(devilX + 4, devilY);
        cout << char(254);
        devilFireCount++;
    }
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
    for (int x = 0; x < devilFireCount; x++)
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

void exitDoor()
{
    for (int idx = 0; idx < 3; idx++)
    {
        gotoxy(183, 32 + idx);
        for (int idx = 0; idx < 3; idx++)
        {

            cout << char(178);
        }
    }
}

void storeGameData()
{
    fstream myfile1;
    myfile1.open("gameData.txt", ios::out);
    myfile1 << score << ",";
    myfile1 << health << ",";
    myfile1 << masterLife << ",";
    myfile1 << malrioX << ",";
    myfile1 << malrioY << ",";
    myfile1 << masterX << ",";
    myfile1 << masterY << ",";
    myfile1 << guddaX << ",";
    myfile1 << guddaY << ",";
    myfile1 << phuphiX << ",";
    myfile1 << phuphiY << ",";
    myfile1 << gunEnemyX << ",";
    myfile1 << gunEnemyY << ",";
    myfile1 << devilX << ",";
    myfile1 << devilY << "," << endl;
    myfile1.close();
}

string getField(string record, int field)
{
    int commaCount = 0;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount++;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

void loadGameRcord()
{
    fstream myfile1;
    string record;
    myfile1.open("gameData.txt", ios::in);
    while (getline(myfile1, record))
    {
        stringstream temp1(getField(record, 1));
        temp1 >> score;
        stringstream temp2(getField(record, 2));
        temp2 >> health;
        stringstream temp3(getField(record, 3));
        temp3 >> masterLife;
        stringstream temp4(getField(record, 4));
        temp4 >> malrioX;
        stringstream temp5(getField(record, 5));
        temp5 >> malrioY;
        stringstream temp6(getField(record, 6));
        temp6 >> masterX;
        stringstream temp7(getField(record, 7));
        temp7 >> masterY;
        stringstream temp8(getField(record, 8));
        temp8 >> guddaX;
        stringstream temp9(getField(record, 9));
        temp9 >> guddaY;
        stringstream temp10(getField(record, 10));
        temp10 >> phuphiX;
        stringstream temp11(getField(record, 11));
        temp11 >> phuphiY;
        stringstream temp12(getField(record, 12));
        temp12 >> gunEnemyX;
        stringstream temp13(getField(record, 13));
        temp13 >> gunEnemyY;
        stringstream temp14(getField(record, 15));
        temp14 >> devilX;
        stringstream temp15(getField(record, 1));
        temp15 >> devilY;
    }
    myfile1.close();
}

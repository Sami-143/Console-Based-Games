#include <iostream>
#include <windows.h>
#include<conio.h>
using namespace std;


string direction = "RIGHT";
string direction1 = "LEFT";
string direction2 = "UP";

string mazeArray[30][100];


void printMaze();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);


int malrioX = 8;
int malrioY = 6;
void printMalrio(int x, int y);
char mar1[3] = {' ', '0', ' '};
char mar2[3] = {'/', '|', char(209)};
char mar3[3] = {'/', ' ', '\\'};

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
void masterMove();
char master1[2] = {'@', '@'};
char master2[2] = {'-', '-'};
void eraseMaster(int x, int y);
int master_time = 0;
void bulletCollisionWithMaster();


int guddaX = 80;
int guddaY = 14;
void printGudda(int x, int y);
char gudda1[3] = {'o', ' ', 'o'};
char gudda2[3] = {char(254), '|', char(254)};
char gudda3[3] = {char(254), char(254), char(254)};
void eraseGudda(int x, int y);
void moveGudda();
void bulletCollisionWithGudda();


int guddafireX[1000];
int guddafireY[1000];
int guddafireCount=0;
void generateGuddaFire();
void printGuddaFire(int x, int y);
void eraseGuddaFire(int x, int y);
void removeGuddaFireFromArray(int index);
void moveGuddaFire();


int phuphiX = 130;
int phuphiY = 14;
void printPhuphi(int x, int y);
char phuphi1[3] = {'o', '*', 'o'};
char phuphi2[3] = {char(254), '|', char(254)};
char phuphi3[3] = {char(254), char(254), char(254)};
void erasePhuphi(int x, int y);
void movePhuphi();
void bulletCollisionWithPhuphi();


int phuphifireX[100];
int phuphifireY[100];
int phuphifireCount=0;
void printPhuphiFire(int x, int y);
void erasePhuphiFire(int x,int y);
void movePhuphiFire();
void removePhuphiFireFromArray(int index);
void generatePhuphiFire();



int doorX = 110;
int doorY = 13;
void printDoor(int x, int y);
char door1[1] = {char(176)};


void printGun();
char gun1[4] = {'<', '-', '-', char(254)};


int gunEnemyX = 182;
int gunEnemyY = 6;
int fireX[100];
int fireY[100];
int fireCount=0;
void generateFire();
void printFire(int x, int y);
void eraseFire(int x, int y);
void removeFireFromArray(int index);
void moveFire();
int gun_timer =0;


int devilX = 3;
int devilY = 20;
int devilFireCount=0;
void printDevil(int x, int y);
char devil1[4]={char(254),char(254), '-', '>'};
char devil2[4]={char(254),char(254),' ', ' '};
void printDevil(int x, int y);
void eraseDevil(int x, int y);
void moveDevil();

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


int score = 0;
void addScore();
void printScore();


int health=20;
void lossHeath();

void keys();
int menu();
void characters();
void topHeader();
void clearScreen();
void logoOfMalrio();
void instruction();
void letStart();
void loadMaze();

main()
{
    loadMaze();
    system("cls");
    topHeader();
    logoOfMalrio();
    getch();
    system("cls");
    int option = 0;

     while(option!=5)
    {        
     system("cls");
     topHeader();
     option = menu();

     if(option==1)
     {
      clearScreen();
      topHeader();
      system("cls");
      letStart();
     }

      else if(option == 2)
      {  
        clearScreen();
        topHeader();
        keys();
      }

      else if(option == 3)
      {  
        clearScreen();
        topHeader();
        instruction();
      }
      else if(option == 4)
      {  
        clearScreen();
        topHeader();
        characters();
      }

      

    }
    
}

void letStart()
{
    system("Color 09");
    system("cls");
    printMaze();
    printGun();
    printMaster(masterX, masterY);
    printGudda(guddaX, guddaY);
    printPhuphi(phuphiX, phuphiY);
    gotoxy(doorX,doorY);
    cout << char(176);
    printDevil(devilX,devilY);

    bool gameRunning = true;
    while (gameRunning)
    {
        printScore();
    
        if (GetAsyncKeyState(VK_LEFT))
        {
            playerMoveLeft();
            moveMalrioDown();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            playerMoveRight();
            moveMalrioDown();
        }

        if (GetAsyncKeyState(VK_UP))
        {
            playerMoveUp();
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            playerMoveDown();
            moveMalrioDown();
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

        if(gun_timer == 3)
        {
            moveFire();
            gun_timer = 0;
        }

        if(gun_timer == 2)
        {
            
            generateFire();
            generateGuddaFire();
            generatePhuphiFire();
            generateDevilFire();   
            gun_timer = 0;
        }
        if(score == 30)
        {
            gameRunning = false;
        }
        gotoxy(20,40);
        cout<<"Health: "<<health;
        
        moveBullet();
        moveGuddaFire();
        movePhuphiFire();
        moveFire();
        moveDevilFire();
        bulletCollisionWithMaster();
        bulletCollisionWithGudda();
        bulletCollisionWithPhuphi();
        phuphifireCollisionWithMalrio();
        guddafireCollisionWithMalrio();
        fireCollisionWithMalrio();
        
        master_time++;
        gun_timer++;
        Sleep(20);
         if(health==0)
        {
            gameRunning=false;
        }
    }
   
}


void instruction()
{
    cout <<"\t""                  ******************************* "<<endl;
    cout <<"\t""                 |                               |"<<endl;
    cout <<"\t""                 |          Instructions         |"<<endl;
    cout <<"\t""                  ******************************* "<<endl;
    cout <<endl<<endl<<endl;
    cout <<"\t""    1.MALRIO is a game in which there is only one Player name as Malrio.            " <<endl<<endl;
    cout <<"\t""    2. In this game there are 5 enemies, (4 enimies and a gun). " <<endl<<endl;
    cout <<"\t""    3. Press the Space bar to release fire.                                      " <<endl<<endl;
    cout <<"\t""    4. When the bullet hits the Enemy , the score will add by '1' per bullet.    " <<endl<<endl;
    cout <<"\t""    5. MALRIO should have to eat 3 score pallets.to end the game           " <<endl<<endl;
    cout <<"\t""    6. The goal of the game is to reach the top lower  corner of th maze to eat   " <<endl<<endl;
    cout <<"\t""    7. GUDDA & PHUPHI fire on left to right and right toleft Respectively.                                             " <<endl<<endl;

   cout << endl;
   cout <<"\t""  Press Any Key to Continue .. !"<<endl;

   getch();
}

void logoOfMalrio()
{
cout<< "                                                      ...                          "<<endl;     
cout<< "                                                     .....                         "<<endl;                                                                                      
cout<< "                                                   ........                                 "<<endl;        
cout<< "                                                   :.......                               "<<endl;
cout<< "                                                  ..-:.::....                            "<<endl;
cout<< "                                                   :===:.::..  ..                         "<<endl;
cout<< "                                                    =+=--=-...:...                         "<<endl;
cout<< "                                                  ..::-++==--=:...:--:.....               "<<endl;
cout<< "                                                 :=-:. =*++*+=-::-=*=:....:.              "<<endl;
cout<< "                                                 -=++++***++*=++=--=::...::.              "<<endl;
cout<< "                             :=+*#%%%##**+-:.     -+*##*+++++=+**+=-::..::-.              "<<endl;
cout<< "                          -*%%*+===+*%%%%%%%%%*=:  =+++++++==++*+==--::::-=.              "<<endl;
cout<< "                        -#@#=   =%+:  =%%%%%%@@@@@*-:=++++==++***++==----==               "<<endl;
cout<< "                      .#@@=.###*%:=%#=.*%%%%%@@@@@@@%*=:-++==+**##***+++==-               "<<endl;
cout<< "                     :%@@#.-%=.::  :+*:#%%%%@@@@@@@@@@@@*+==++++*###*+=-:.                "<<endl;
cout<< "                    .%@@@#:*%+....:==+#%%%@@@@@@@@@@@@@@@@#**+++*+=--::::::-              "<<endl;
cout<< "                    #@@@@@#+===*#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%=               "<<endl;
cout<< "                   =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%:               "<<endl;
cout<< "                   #@@@@@@@@@@@@@@@@@%##*@@@@%%%%#*#%%@@@@@@@@@@@@@@%%%%%%:               "<<endl;
cout<< "                  .@@@@@@@@@@@@@%#***++=+@+=--=++*****#%@@@@@@@@@@@@@%%%%%.               "<<endl;
cout<< "                  -@@@@@@@@@@@@@%+==-----=:..  :=+******%@@@@@@@@@@@%%%%%*                "<<endl;
cout<< "                  -@@@@@@@@@@##*##=-----::-==+-..-+*****%@@@@@@@@@@@%%%%%+                "<<endl;
cout<< "                  .@@@@@@@%%++=--=++==--:::%#@%-. :=+***#%@@@@@@@@@@%%%%%-                "<<endl;
cout<< "                   *@@@@@#**+=::=++*==--::::-=#=: .:-#%#*#@@@@@@@@@%%%%%%.                "<<endl;
cout<< "                   .%@@@@#**+=--+@*=----:::::::-.:-*%%%@*#@@@@@@@@@@@@%%#                 "<<endl;
cout<< "                    .#@@@%**+=--=+====---------+*%%##%@%-+@@@@@@@@@@@@@%+                 "<<endl;
cout<< "                      =%@@%**+===*++++========+###*#%@-::=@@@@@@@%@@@@@%:                 "<<endl;
cout<< "                       -*%%%**==+***********####%@@@@+:--=@@@@@@@%@@@@@%                  "<<endl;
cout<< "                      -###@@*@@@@@@%###%%%%@@@@@@++=-----#@@@@@@@%@@@@@*                 "<<endl;
cout<< "                      -#**%%*%@@@@@@@@@@@@@%%%%#+++-=====%@@@@@@@%@@@@@-                  "<<endl;
cout<< "                       =***%***#*%@@@%%%@%###*#%@@*-====+%@@@@@@@%@%@@@.                  "<<endl;
cout<< "                        :+******#####**#*%@@@@@@@%--===+#%%@@@@@@%%%%%#                   "<<endl;
cout<< "             ...    .:::-:-=+****####*******###*+====+*##***#%@@%%%%%@%=                  "<<endl;
cout<< "            :---------:-===+:   -+*########**+***+=+*%%%#*+++*#%%%%%%%%%-                 "<<endl;
cout<< "           =-.    .:-::-=+**      .:-=++#########%%%%%%%**++++#%%%%%%%%%:                "<<endl;
cout<< "           ::::::::::=++**++*=         :*%%@@@@@%%%%%%%%%#**++++*%%%%%%%%%.               "<<endl;
cout<< "          :=--.   .-+*+*++++++        *##*%%@@%%%%%%%%#**#**=--::-*#%%%%%%#               "<<endl;
cout<< "         :::......::-=::-==*-      :*##**#%%%%%###********+------:***#%%%%=              "<<endl;
cout<< "         ====--=+**++-   .:+:-   .*@%#*+********************+====+*****#%%%.             "<<endl;
cout<< "          ::..   ..=*=     :: #%#*%@@#=--:+#####**********************++***#+             "<<endl;
cout<< "         -==++++===-     .- =%%@@@@%+==--+***************+**********++++*****            "<<endl;
cout<< "           =*###*#*=:::::-=.=%%%@@@@%**++*####*************+++*******++++*****            "<<endl;
cout<< "            .-+*###******+:+%%%@@@@%##*******###****************+++++++++*****:           "<<endl;
cout<< "               .:-=*###*==#@@@@@@%#*******++++********************************=           "<<endl;
cout<< "                    :====*%@@@@@##******+++++++******************************#*           "<<endl;
cout<< "                            :=%#*******+++++++******#************************##           "<<endl;
cout<< "                            .*#******++++++++*******####********************###           "<<endl;
cout<< "                    :-=+***+*#******++++++++*******##########*************####*           "<<endl;
cout<< "                -*#######**********+++++++*+****#############################-           "<<endl;
cout<< "              .*%%%%#####***++++*****+++++*****#####%#%%#####################            "<<endl;
cout<< "               #%%%%%%%%####**+++++******+*+***#%%%%%%%%%%%%%################=            "<<endl;
cout<< "              =%%%%%###***#####**+++******+****#%@%%%%%%%%%%%%%%%%%%%#######%.            "<<endl;
cout<< "              +%%#######****++**##*****###*****#%%@@@@@%%%%%%%%%%%%#########*             "<<endl;
cout<< "              -%%%%############***#########***#:     :=%%%%%%%%%%###########.             "<<endl;
cout<< "              .%%%%%%%%%%#########**%%%%#####*#       -%%%%%%%%############=              "<<endl;
cout<< "               +%%%%%%%%%%%%%%%%%#####%%%%%%%##       #%%%%%%#############*               "<<endl;
cout<< "                =%%%%%%%%%%%%%%%%%%%%%#%@%%%%%-      -%%%%%###############.               "<<endl;
cout<< "                 :*%%%%%%%@@@@@@@@@%%%#**%%%%%       #%%%%###############:                "<<endl;
cout<< "                   .=*%@@@@@@@@%%#######***%@#      *%%%%###############.                 "<<endl;
cout<< "                         *%%%%%%%%%%%%%%#####:     =%%%%##############%-                  "<<endl;
cout<< "                          -*%@@@@@@%%%%%%%%%.     -%%%###############%+                   "<<endl;
cout<< "                             :-+*#%@@%%#*+-      +%%%#################.                   "<<endl;
cout<< "                                               :#%%%#################.                    "<<endl;
cout<< "                                              .%%%%################%:                     "<<endl;
cout<< "                                              *%%#################%-                      "<<endl;
cout<< "                                             -%%%####****########%=                       "<<endl;
cout<< "                                            .%######**********##%+                        "<<endl;
cout<< "                                            *%##*******##*****##*                         "<<endl;
cout<< "                                           =%##****++++=++**###%:                         "<<endl;
cout<< "                                          #%##***++======+++**#.                         "<<endl;
cout<< "                                           %%###***++======++*#*                          "<<endl;
cout<< "                                           #%%####***+++++++**#-                          "<<endl;
cout<< "                                           =%%%%%%####*******#*                           "<<endl;
cout<< "                                            *%@@@@%%%%%#######.                           "<<endl;
cout<< "                                             =#%@@@@@@@@@@@%+.                            "<<endl;
cout<< "                                               :=*%@@@@@@*-                               "<<endl;

}


void topHeader()
{
cout<< "                 __       __   ______   __        _______   ______   ______             "<<endl;
cout<< "                / \\     /  | /     \\ /  |      /       \\ /      |/     \\            "<<endl;
cout<< "                $$ \\   /$$ |/$$$$$$  |$$ |      $$$$$$$  |$$$$$$/ /$$$$$$  |            "<<endl;
cout<< "                $$$ \\ /$$$ |$$ |__$$ |$$ |      $$ |__$$ |  $$ |  $$ |  $$ |            "<<endl;
cout<< "                $$$$  /$$$$ |$$    $$ |$$ |      $$    $$<   $$ |  $$ |  $$ |            "<<endl;
cout<< "                $$ $$ $$/$$ |$$$$$$$$ |$$ |      $$$$$$$  |  $$ |  $$ |  $$ |            "<<endl;
cout<< "                $$ |$$$/ $$ |$$ |  $$ |$$ |_____ $$ |  $$ | _$$ |_ $$\\__$$ |            "<<endl;
cout<< "                $$ | $/  $$ |$$ |  $$ |$$       |$$ |  $$ |/ $$   |$$    $$/              "<<endl;
cout<< "                $$/      $$/ $$/   $$/ $$$$$$$$/ $$/   $$/ $$$$$$/  $$$$$$/              "<<endl;
}


void characters()
{
    cout<< "MALRIO >>>>>>>>>>>>>>"<<endl;
      for (int idx = 0; idx < 3; idx++)
    {
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout<< mar1[idx][idx1];
        }
        cout << endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"MASTER >>>>>>>>>>>>>>>"<<endl;
    
        for (int idx = 0; idx < 2; idx++)
        {
        for (int idx1 = 0; idx1 < 2; idx1++)
        {
            cout << master1[idx][idx1];
        }
        cout << endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
    cout<<"GUDDA >>>>>>>>>>>>>>>"<<endl;
    for (int idx = 0; idx < 3; idx++)
    {
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout << gudda1[idx][idx1];
        }
        cout << endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"PHUPHI >>>>>>>>>>>>>>>"<<endl;
    for (int idx = 0; idx < 3; idx++)
    {
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout << phuphi1[idx][idx1];
        }
        cout << endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Devil >>>>>>>>>>>>>>>"<<endl;
    for (int idx = 0; idx < 2; idx++)
    {
        for (int idx1 = 0; idx1 < 4; idx1++)
        {
            cout << devil1[idx][idx1];
        }
        cout << endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Gun Enemy >>>>>>>>>>>>>>>"<<endl;
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

    int option;
    cout <<"\t""      _______________________________ "<<endl;
    cout <<"\t""     |                               |"<<endl;
    cout <<"\t""     |           Menu                |"<<endl;
    cout <<"\t""     |_______________________________|"<<endl;
    cout <<"\t""                                      "<<endl;
    cout <<"\t""      1.Start Game                    "<<endl;
    cout <<"\t""      2.Keys                          "<<endl;
    cout <<"\t""      3.Instructions                  "<<endl;
    cout <<"\t""      4.Characters                    "<<endl;
    cout <<"\t""      5.Exit                          "<<endl;
    cout <<endl;
    cout <<"\t" " Select any option..";
    cin>>option;

 return option;   

}                                                         



void keys()
{     
    cout <<"\t""      _______________________________ "<<endl;
    cout <<"\t""     |                               |"<<endl;
    cout <<"\t""     |            Keys               |"<<endl;
    cout <<"\t""     |_______________________________|"<<endl;
    cout <<endl;
    cout << "\t""     1. Up                 Go up    "<<endl;
    cout << "\t""                  ^      "<<endl;
    cout << "\t""                  |      "<<endl;
    cout <<endl;
    cout << "\t""     2. Down               Go Down  "<<endl;
    cout << "\t""                  |      "<<endl;
    cout << "\t""                  V      "<<endl;
    cout <<endl;
    cout << "\t""     3. Left               Go Left  "<<endl;
    cout << "\t""                <----       "<<endl;
    cout <<endl;
    cout << "\t""     4. Right              Go Right "<<endl;
    cout << "\t""                ----->     "<<endl;
    cout <<endl;
    cout << "\t""     5. Space              Fire     "<<endl;
    cout <<endl<<endl;
    cout << "\t""     6. Esc                End Game "<<endl;
    cout << endl;
    cout <<"\t"" Press any key to continue ..!"<<endl;

    getch();
}



void printMaze()
{
    cout << "############################################################################################################################################################################################  " << endl;
    cout << "############################################################################################################################################################################################  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                            +                           ##  " << endl;
    cout << "##                                                                                                          ######################                #######################                 ##  " << endl;
    cout << "##                                   #########                                             #########                                                                                      ##  " << endl;
    cout << "##                                   #########                                             #########                                                                                      ##  " << endl;
    cout << "##                                   #########                                             #########                                                                                      ##  " << endl;
    cout << "## ##############################################################################################################################################################                         ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                                       ###################  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                         #######                                           ##                                             #########                     ##  " << endl;
    cout << "##                                                         #######                                           ##                                             #########                     ##  " << endl;
    cout << "##                                       +                 #######                                           ##                                             #########                     ##  " << endl;
    cout << "##              ################       #############       ###############################################################################################################                ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                 ###################################           ##########################                                                                                               ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                                                        ##  " << endl;
    cout << "##                                                                                                                                                           +                            ##  " << endl;
    cout << "##             ############################################      ##############      #########      ######################    ###############   ##############################            ##  " << endl;                                                               
    cout << "##             ############################################      ##############      #########      ######################    ###############   ##############################            ##  " << endl;
    cout << "##             ############################################      ##############      #########      ######################    ###############   ##############################            ##  " << endl;
    cout << "##             #########  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  ##########            ##  " << endl;
    cout << "############################################################################################################################################################################################  " << endl;
    cout << "############################################################################################################################################################################################  " << endl;
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

 void clearScreen()
 {
   cout <<" Press any Key to Continue ! "<<endl;
   getch();
   system("cls");
 }

// PRINT OUR MAIN HERO ON SCREEN
void printMalrio(int x, int y)
{

    gotoxy(x, y);
    for (int idx = 0; idx < 3; idx++)
    {
        cout <<"\033[31m"<< mar1[idx];
    }
    gotoxy(x, y + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout <<"\033[31m"<< mar2[idx];
    }
    gotoxy(x, y + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout <<"\033[31m"<< mar3[idx];
    }
}


// EREASE THE MALRIO FROM THE PREVIOUS LOCATION
void erase(int x, int y)
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


// FUNCTION TO MOVE PLAYER LEFT
void playerMoveLeft()
{
    char nextLocation1 = getCharAtxy(malrioX - 1, malrioY + 1);
    char nextLocation2 = getCharAtxy(malrioX - 1, malrioY + 2);
    char nextLocation = getCharAtxy(malrioX - 1, malrioY);
    if ((nextLocation1 == '+' || nextLocation == '+' ||  nextLocation2 == '+'))
    {
        score++;
    }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') && (nextLocation != '*' && nextLocation1 != '*' && nextLocation2 != '*') && (nextLocation1 != '@' && nextLocation != '@' && nextLocation2 != '@'))
    {
        erase(malrioX, malrioY);
        malrioX = malrioX - 1;
        printMalrio(malrioX, malrioY);
    }
    else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') || (nextLocation1 == '-' || nextLocation == '-' || nextLocation2 == '-')|| (nextLocation1 == '@' || nextLocation == '@' || nextLocation2 == '@'))
    {
        health--;
    }

    else if((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') ||  (nextLocation1 == char(254) || nextLocation == char(254) || nextLocation2 == char(254))) 
    {
        health--;
    }
    

}


// FUNCTION TO MOVE PLYER UP
void playerMoveRight()
{
    char nextLocation = getCharAtxy(malrioX + 3, malrioY);
    char nextLocation1 = getCharAtxy(malrioX + 3, malrioY + 1);
    char nextLocation2 = getCharAtxy(malrioX + 3, malrioY + 2);
    if ((nextLocation1 == '+' || nextLocation == '+' ||  nextLocation2 == '+'))
    {
        score++;
    }
    if ((nextLocation1 != '#' && nextLocation != '#' && nextLocation2 != '#') && (nextLocation != '*' && nextLocation1 != '*' && nextLocation2 != '*') && (nextLocation1 != '@' && nextLocation != '@' && nextLocation2 != '@'))
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
    char nextLocation = getCharAtxy(malrioX, malrioY - 1);
    char nextLocation1 = getCharAtxy(malrioX + 1, malrioY - 1);
    char nextLocation2 = getCharAtxy(malrioX + 2, malrioY - 1);
    if ((nextLocation1 == '+' || nextLocation == '+' ||  nextLocation2 == '+'))
    {
        score++;
    }
    if ((nextLocation != '#' && nextLocation1 != '#' && nextLocation2 != '#') && (nextLocation != '*' && nextLocation1 != '*' && nextLocation2 != '*') && (nextLocation1 != '@' && nextLocation != '@' && nextLocation2 != '@'))
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
    char nextLocation = getCharAtxy(malrioX, malrioY + 3);
    char nextLocation1 = getCharAtxy(malrioX + 1, malrioY + 3);
    char nextLocation2 = getCharAtxy(malrioX + 2, malrioY + 3);

    if ((nextLocation1 == '+' || nextLocation == '+' ||  nextLocation2 == '+'))
    {
        score++;
    }
    if ((nextLocation != '#' && nextLocation1 != '#' && nextLocation2 != '#') && (nextLocation != '*' && nextLocation1 != '*' && nextLocation2 != '*') && (nextLocation1 != '@' && nextLocation != '@' && nextLocation2 != '@'))
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



// GENERATE A BULLET FROM THE MALRIO GUN
void generateBullet()
{
    bulletX[bulletCount] = malrioX + 4;
    bulletY[bulletCount] = malrioY + 1;
    char next = getCharAtxy(bulletX[bulletCount],bulletY[bulletCount]);
    if(next != '#' )
    {
    gotoxy(malrioX + 4, malrioY+1);
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
        char next = getCharAtxy(bulletX[x] + 1, bulletY[x] );
        if (next != ' ')
        {
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
         if (next == ' ')
        {
            eraseBullet(bulletX[x], bulletY[x]);
            bulletX[x] = bulletX[x] + 1;
            printBullet(bulletX[x], bulletY[x]);
        }
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


void moveMalrioDown()
{
    bool flag=true;
    char space1;
    char space2;

    while(flag)
    {
        space1 = getCharAtxy(malrioX,malrioY+3);
        space2 = getCharAtxy(malrioX+3 ,malrioY+3);

        if(space1 == ' ' && space2 == ' ')
        {
            erase(malrioX, malrioY);
            malrioY=malrioY+1;
            printMalrio(malrioX, malrioY);
        }

        else
        {
            flag = false;
        }
    }
}



// start to
// PRINT A NEW ENEMY NAME MASTER WHICH IS ON THE FIRST FLOOR
void printMaster(int x, int y)
{

    gotoxy(x, y);
    for (int idx = 0; idx < 2; idx++)
    {
        cout <<"\033[32m"<< master1[idx];
    }
    gotoxy(x, y + 1);
    for (int idx = 0; idx < 2; idx++)
    {
        cout <<"\033[32m"<< master2[idx];
    }
    gotoxy(5, 5);
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


// FUNCTION FOR MOVEMENT OF MASTER
void masterMove()
{

    if (direction == "RIGHT")
    {
        char nextLocation = getCharAtxy(masterX + 2, masterY);
        char nextLocation1 = getCharAtxy(masterX + 2, masterY + 1);
        if ((nextLocation != '#' && nextLocation1 != '#'))
        {
            eraseMaster(masterX, masterY);
            masterX = masterX + 1;
            printMaster(masterX, masterY);
        }
        else if ((nextLocation == '#' || nextLocation1 == '#'))
        {
            direction = "LEFT";
        }
    }

    if (direction == "LEFT")
    {

        char nextLocation1 = getCharAtxy(masterX - 1, masterY);
        char nextLocation = getCharAtxy(masterX - 1, masterY + 1);
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


// start
// instruction of Gudda
// PRINT A ENEMY NAME AS GUDDA
void printGudda(int x, int y)
{

    gotoxy(x, y);
    for (int idx = 0; idx < 3; idx++)
    {
        cout <<"\033[34m"<< gudda1[idx];
    }
    gotoxy(x, y + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout <<"\033[34m"<< gudda2[idx];
    }
    gotoxy(x, y + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout <<"\033[34m"<< gudda3[idx];
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
        char nextLocation = getCharAtxy(guddaX + 3, guddaY);
        char nextLocation1 = getCharAtxy(guddaX + 3, guddaY + 1);
        char nextLocation2 = getCharAtxy(guddaX + 3, guddaY + 2);
        if (nextLocation == ' ' && nextLocation1 == ' ' && nextLocation2 == ' ')
        {
            erase(guddaX, guddaY);
            guddaX = guddaX + 1;
            printGudda(guddaX, guddaY);
        }
        else if (nextLocation == char(176) || nextLocation1 == char(176) || nextLocation2 == char(176))
        {
            direction1 = "LEFT";
        }
    }

    if (direction1 == "LEFT")
    {
        char nextLocation = getCharAtxy(guddaX - 1, guddaY);
        char nextLocation1 = getCharAtxy(guddaX - 1, guddaY + 1);
        char nextLocation2 = getCharAtxy(guddaX - 1, guddaY + 2);
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





void bulletCollisionWithMaster()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bulletX[x] + 1 == masterX && (bulletY[x] == masterY || bulletY[x] == masterY + 1 || bulletY[x] == masterY + 2 || bulletY[x] == masterY + 3))
        {
            addScore();
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
    }
}

void bulletCollisionWithGudda()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bulletX[x] + 1 == guddaX && (bulletY[x] == guddaY || bulletY[x] == guddaY + 1 || bulletY[x] == guddaY + 2 || bulletY[x] == guddaY + 3))
        {
            addScore();
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
    }
}


void bulletCollisionWithPhuphi()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bulletX[x] + 1 == phuphiX && (bulletY[x] == phuphiY || bulletY[x] == phuphiY + 1 || bulletY[x] == phuphiY + 2 || bulletY[x] == phuphiY + 3))
        {
            addScore();
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
    }
}



void fireCollisionWithMalrio()
{
    for (int x = 0; x < fireCount; x++)
    {
        if (fireX[x] + 1 == malrioX && (fireY[x] == malrioY || fireY[x] == malrioY + 1 || fireY[x] == malrioY + 2 ))
        {
            eraseFire(fireX[x], fireY[x]);
            removeBulletFromArray(x);
            health--;
        }
    }
}

void guddafireCollisionWithMalrio()
{
    for (int x = 0; x < guddafireCount; x++)
    {
        if (guddafireX[x] + 1 == malrioX && (guddafireY[x] == malrioY || guddafireY[x] == malrioY + 1 || guddafireY[x] == malrioY + 2))
        {
            eraseGuddaFire(guddafireX[x], guddafireY[x]);
            removeGuddaFireFromArray(x);
            health--;
        }
    }
}

void phuphifireCollisionWithMalrio()
{
    for (int x = 0; x < phuphifireCount; x++)
    {
        if (phuphifireX[x] + 1 == malrioX && (phuphifireY[x] == malrioY || phuphifireY[x] == malrioY + 1 || phuphifireY[x] == malrioY + 2 ))
        {
           
            erasePhuphiFire(phuphifireX[x], phuphifireY[x]);
            removePhuphiFireFromArray(x);
            health--;
        }
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
    guddafireX[guddafireCount] = guddaX + 4;
    guddafireY[guddafireCount] = guddaY;
    gotoxy(guddaX + 4, guddaY);
    cout << "-";
    guddafireCount++;
}


// REMOVE BULLET FROM THE ARRAY OF Gudda GUN
void removeGuddaFireFromArray(int index)
{
    for (int x = index; x < guddafireCount - 1; x++)
    {
        guddafireX[x] = guddafireX[x + 1];
        guddafireY[x] = guddafireY[x + 1];
    }
    guddafireCount--;
}


// MOVEMENT OF Gudda GUN BULLETES 
void moveGuddaFire()
{
    for (int x = 0; x < guddafireCount; x++)
    {
        
        char next = getCharAtxy(guddafireX[x] + 1, guddafireY[x] + 1);
        if (next != ' ' || next =='#')
        {
            
            eraseGuddaFire(guddafireX[x], guddafireY[x]);
            removeGuddaFireFromArray(x);
        }
        else
        {
            eraseGuddaFire(guddafireX[x], guddafireY[x]);
            guddafireX[x] = guddafireX[x] + 1;
            printGuddaFire(guddafireX[x], guddafireY[x]);
    }
    }
}





//strat for Phuphi 
// instruction of Phuphi
// PRINT FOR THE NEW ENEMY NAME AS PHUPHI
void printPhuphi(int x, int y)
{

    gotoxy(x, y);
    for (int idx = 0; idx < 3; idx++)
    {
        cout <<"\033[33m"<< phuphi1[idx];
    }
    gotoxy(x, y + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout <<"\033[33m"<< phuphi2[idx];
    }
    gotoxy(x, y + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout <<"\033[33m"<< phuphi3[idx];
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
        char nextLocation = getCharAtxy(phuphiX - 1, phuphiY);
        char nextLocation1 = getCharAtxy(phuphiX - 1, phuphiY + 1);
        char nextLocation2 = getCharAtxy(phuphiX - 1, phuphiY + 2);
        if (nextLocation != char(176) && nextLocation1 != char(176) && nextLocation2 != char(176))
        {
            erasePhuphi(phuphiX, phuphiY);
            phuphiX = phuphiX - 1;
            printPhuphi(phuphiX, phuphiY);
        }
        else if (nextLocation == char(176) || nextLocation1 == char(176) || nextLocation2 == char(176))
        {
            direction1 = "RIGHT";
        }
    }

    if (direction1 == "RIGHT")
    {
        char nextLocation = getCharAtxy(phuphiX + 3, phuphiY);
        char nextLocation1 = getCharAtxy(phuphiX + 3, phuphiY + 1);
        char nextLocation2 = getCharAtxy(phuphiX + 3, phuphiY + 2);
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
    for (int x = 0; x < phuphifireCount ; x++)
    {
        char next = getCharAtxy(phuphifireX[x] - 3, phuphifireY[x] + 1);
        if (next != ' ' || next == '#')
        {
            
            eraseFire(phuphifireX[x], phuphifireY[x]);
            removePhuphiFireFromArray(x);
        }
        else
        {
            
            erasePhuphiFire(phuphifireX[x], phuphifireY[x]);
            phuphifireX[x] = phuphifireX[x] - 1;
            printPhuphiFire(phuphifireX[x], phuphifireY[x]);
        }
    }
}

// REMOVAL OF FIRE FROM THE ARRAY OF phuphi FIRE
void removePhuphiFireFromArray(int index)
{
    for (int x = index; x < phuphifireCount - 1; x++)
    {
        phuphifireX[x] =phuphifireX[x + 1];
        phuphifireY[x] = phuphifireY[x + 1];
    }
    phuphifireCount--;
}

// FUNCTION TO GENERATE phupphiFIRE ON THE CONSOLE SCREEN
void generatePhuphiFire()
{
    phuphifireX[phuphifireCount] = phuphiX - 1;
    phuphifireY[phuphifireCount] = phuphiY;
    gotoxy(phuphiX - 5, phuphiY);
    cout << "-";
    phuphifireCount++;
}


// FUNCTION TO PRINT THE DOOR
// void printDoor(int x, int y)
// {
//     gotoxy(x, y);
//     cout << door1 << endl;
// }



// INSTRUCTION OF GUN
// PRINT THE GUN IN MAZE
void printGun()
{
    gotoxy(gunEnemyX, gunEnemyY);
    for (int idx = 0; idx < 4; idx++)
    {
    
        
        cout << gun1[idx];
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
    for (int x = 0; x < fireCount ; x++)
    {
        char next = getCharAtxy(fireX[x] - 1, fireY[x]);
        if (next != ' ')
        {
            
            eraseFire(fireX[x], fireY[x]);
            removeFireFromArray(x);
        }
        else
        {
            
            eraseFire(fireX[x], fireY[x]);
            fireX[x] = fireX[x] - 1;
            printFire(fireX[x], fireY[x]);
        }
    }
}

// REMOVAL OF FIRE FROM THE ARRAY OF GUN FIRE
void removeFireFromArray(int index)
{
    for (int x = index; x < fireCount - 1; x++)
    {
        fireX[x] =fireX[x + 1];
        fireY[x] = fireY[x + 1];
    }
    fireCount--;
}

// FUNCTION TO GENERATE FIRE ON THE CONSOLE SCREEN
void generateFire()
{
    fireX[fireCount] = gunEnemyX - 5;
    fireY[fireCount] = gunEnemyY;
    gotoxy(gunEnemyX - 5, gunEnemyY);
    cout << "X";
    fireCount++;
}




// INSTRUCTION FOR OBSTACLE
// print devil to ove up and down
void printDevil(int x, int y)
{
    gotoxy(x,y);
    for(int idx=0;idx<4;idx++)
    {
    cout << devil1[idx];
    }
    gotoxy(x,y+1);
    for(int idx=0;idx<4;idx++)
    {
    cout << devil2[idx];
    }
}


// erase the devil to go to the vertical up down
void eraseDevil(int x, int y)
{
    gotoxy(x,y);
    for(int idx=0;idx<4;idx++)
    {
    cout <<" ";
    }
    gotoxy(x,y+1);
    for(int idx=0;idx<4;idx++)
    {
    cout <<" ";
    }
}




// move the devil up and down
void moveDevil()
{
    if (direction2 == "DOWN")
    {
        char nextLocation = getCharAtxy(devilX, devilY + 2 );
        char nextLocation1 = getCharAtxy(devilX+1, devilY + 2 );
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
        char nextLocation1 = getCharAtxy(devilX+1, devilY - 1 );
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




void printDevilFire(int x, int y)
{
    gotoxy(x, y);
    cout <<char(254);
}

void eraseDevilFire(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}



void generateDevilFire()
{
    devilFireX[devilFireCount] = devilX + 4;
    devilFireY[devilFireCount] = devilY;
    gotoxy(devilX + 4, devilY);
    cout <<char(254);
    devilFireCount++;
}



void removeDevilFireFromArray(int index)
{
    for (int x = index; x < devilFireCount - 1; x++)
    {
        devilFireX[x] = devilFireX[x + 1];
        devilFireY[x] = devilFireY[x + 1];
    }
    devilFireCount--;
}



void moveDevilFire()
{
    for (int x = 0; x < devilFireCount; x++)
    {
        
        char next = getCharAtxy(devilFireX[x] + 1, devilFireY[x]);
        if (next != ' ')
        {
            
            eraseDevilFire(devilFireX[x], devilFireY[x]);
            removeDevilFireFromArray(x);
        }
        if(next == ' ')
        {
            eraseDevilFire(devilFireX[x], devilFireY[x]);
            devilFireX[x] = devilFireX[x] + 1;
            printDevilFire(devilFireX[x],devilFireY[x]);
    }
    }
}

void loadMaze()
{
    

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 100; j++) {
            cout << mazeArray[i][j];
        }
        cout << endl;
    }
}



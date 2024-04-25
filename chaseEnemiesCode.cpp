#include<iostream>
using namespace std;
main()
{
    
}
void chaseEnemy()
{
    int locationX = masterX-malrioX; // difference for chase
    int locationY = masterY- malrioY;

    if (locationX > 0) // left
    {
        char nextlocation = getCharAtxy(masterX- 1, masterY);
        char nextlocation1 = getCharAtxy(masterX - 1, masterY + 1);
        // char nextlocation2 = getCharAtxy(masterX[0] - 1, masterY + 2);
        if (nextlocation == 'O' || nextlocation == '\\' || nextlocation == '/' || nextlocation1 == 'O' || nextlocation1 == '\\' || nextlocation1 == '/' || nextlocation2 == 'O' || nextlocation2 == '\\' || nextlocation2 == '/')
        {
            Health--;
        }
        if (nextlocation == ' ' && nextlocation1 == ' ' )
        {
            eraseplayers(masterX,masterY);
            masterX = masterX - 1;
            printMaster(masterX,masterY);
        }
    }
    if (locationX < 0) // right
    {
        char nextlocation = getCharAtxy(masterX + 3, masterY);
        char nextlocation1 = getCharAtxy(masterX + 3, masterY + 1);
        // char nextlocation2 = getCharAtxy(masterX + 3, masterY[1] + 2);
        if (nextlocation == 'O' || nextlocation == '\\' || nextlocation == '/' || nextlocation1 == 'O' || nextlocation1 == '\\' || nextlocation1 == '/' || nextlocation2 == 'O' || nextlocation2 == '\\' || nextlocation2 == '/')
        {
            Health--;
        }
        if (nextlocation == ' ' && nextlocation1 == ' ' && nextlocation2 == ' ')
        {
            eraseplayers(masterX,masterY);
            masterX = masterX + 1;
            printEnemy(masterX,masterY);
        }
    }
    if (locationY < 0) // down
    {
        char nextlocation = getCharAtxy(masterX, masterY + 2);
        char nextlocation1 = getCharAtxy(masterX + 1, masterY + 2);
        // char nextlocation2 = getCharAtxy(masterX + 2, masterY + 3);
        if (nextlocation == 'O' || nextlocation == '\\' || nextlocation == '/' || nextlocation1 == 'O' || nextlocation1 == '\\' || nextlocation1 == '/' || nextlocation2 == 'O' || nextlocation2 == '\\' || nextlocation2 == '/')
        {
            Health--;
        }
        if (nextlocation == ' ' && nextlocation1 == ' ' && nextlocation2 == ' ')
        {
            eraseplayers(masterX,masterY);
            masterY = masterY + 1;
            printEnemy(masterX,masterY);
        }
    }
    if (locationY > 0) // up
    {
        char nextlocation = getCharAtxy(masterX, masterY - 1);
        char nextlocation1 = getCharAtxy(masterX + 1, masterY - 1);
        // char nextlocation2 = getCharAtxy(masterX + 2, masterY - 1);
        if (nextlocation == 'O' || nextlocation == '\\' || nextlocation == '/' || nextlocation1 == 'O' || nextlocation1 == '\\' || nextlocation1 == '/' || nextlocation2 == 'O' || nextlocation2 == '\\' || nextlocation2 == '/')
        {
            Health--;
        }
        if (nextlocation == ' ' && nextlocation1 == ' ' && nextlocation2 == ' ')
        {
            eraseplayers(masterX,masterY);
            masterY = masterY - 1;
            printEnemy(masterX,masterY);
 }
}
}
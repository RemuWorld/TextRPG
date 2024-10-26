#include <stdio.h>
#include "textPlayer.h"

int main() 
{
    int exp = 0, level = 1, mobCount = 0;
    double start, end;
    char playerName[21];

    for(int i = 0; i<3; i++)
    {
        printf("...\n");
        Sleep(333);
    }
    
    clrscr(); //clear screen

    /*
    ------------------------
    Need a start screen here
    A: how?
    B: idk.. maybe using gotoxy?

    A: Isn't gotoxy trash?
    B: idk..?
    ------------------------
    */

    printf("Enter Your name (Maximum: 10)\n\n>");

    for (;;)
    {        
        if (fgets(playerName, sizeof(playerName), stdin) != NULL)
        {
            if (nickChoose(playerName) == 0) break;
        }
    }
    
    //The code below is the code for how much time had been spent to end the game.
    start = (double)clock() / CLOCKS_PER_SEC;    

    // the code below runs till the user dies
    for (;;) 
    {
        if (level < 50) 
        {
            exp = battle(mobFinder(), level);
        }
        else break;
    }
    end = (((double)clock()) / CLOCKS_PER_SEC);

    printf("You have finished your journey.\nYou've played for [%lf] seconds.\nYou've defeated [%d] Mobs\n", (end-start), mobCount);    
    return 0;
}
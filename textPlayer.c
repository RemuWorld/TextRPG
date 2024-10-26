#include <stdio.h>
#include "textPlayer.h"

#define LEFT 75  //Left arrow
#define RIGHT 77  //Right arrow
#define ENTER 13 //Enter key


typedef struct mob 
{
    char mobName[20];
    int health;
    int damage;
    int dodge;
}mob;

void clrscr() 
{ 
    system("cls"); 
}

int nickChoose(char playerName[21]) 
{
    int nickChoosing = 1;

    //This while statement runs until the user finishes writing their nickname.
    while (nickChoosing) 
    {
        size_t len = strlen(playerName);
        if (playerName[len - 1] == '\n') 
        {
            playerName[len - 1] = '\0';
            len--;
        }

        // under 0 or above 10 is error
        if (0 >= len || len > 10) 
        {
            printf("\nWrong input. Try again\n\n>");
            while (getchar() != '\n');
            return 1;
        }
        char response;

        printf("\nYour name: %s", playerName);
        printf("\nSatisfied with your name? (y/n): ");
            
        // Finaly!!! It friking works!!! getch() your not the standard one but you are the best!!
        for (;;) 
        {
            response = _getch();
            
            if (response == 'y' || response == 'Y') 
            {
                printf("Y");
                nickChoosing = 0;
                break;
            }
            else if (response == 'n' || response == 'N') 
            {
                printf("N");
                printf("\n\n\n");
                printf("Enter Your name (Maximum: 10)\n\n>");
                return 1;
            }
        }
    }
    namePrint(playerName);
    Sleep(500);
        
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Welcome %s. Fight for mobs out there!\n", playerName);
    Sleep(500);
    return 0;
}

char* namePrint(char* playerName) 
{
    static char nameLocation[21];

    //If name is "true" return name;
    if (strcmp(playerName, "print") == 0)
    {
        return nameLocation;
    }
    else
    {
        strcpy(nameLocation, playerName);
        return NULL;
    }
}

int playerAction() 
{
    srand((unsigned)time(NULL));
    
    int ch;	// 키 입력, 회전 값 저장

	if (_kbhit()) {	// 키보드 입력이 있을 때까지 대기
		ch = _getch();
		if (ch == 0xE0 || ch == 0) {	// 확장 키(Function) 의 경우에 키를 하나 더 입력 받는다.
						// 방향키는 확장키에 포함된다.( 2바이트로 되어 있으므로 _getch()로 한번에 읽어들일 수 없다.)
						// 따라서 _getch()를 2번 호출해야 한다.
			ch = _getch();

			switch (ch) {	// 입력 값을 검사

			case LEFT:
                break;
			case RIGHT:
		    	break;
			}
		}   //1증가 or 1감소하게. if 증가 1실행 아니면 2실행 이런느낌스
		else {
	
			switch (ch) {
			
			case '@':		// @을 누르면
				_kbhit();	// 일시 정지
				break;
            case ENTER:
                break;

			}
		}// else

	}// if(_kbhit())
	
	return false;
}

int mobFinder() 
{
    srand((unsigned)time(NULL));
    int waitTime;
    int selector;

    // waitUntilBattle
    printf("Finding Mob.\n");
    waitTime = rand()%5 + 4; // 3~8   3000~8000

    for (int i = 0; i<waitTime; i++) 
    {
    Sleep(waitTime*250);
    printf("...\n");
    }

    // randomMobSelector
    selector = rand()%3; //0~2
    return selector;
}

int mobStatRandomizer(int randomMuch) 
{
    srand((unsigned)time(NULL));
    int randomNumber;

    randomNumber = (rand()%randomMuch)*randomMuch;
    return randomNumber;
}

int kashanta(int level) 
{
    int averageHealth = 300;
    int averageDamage = 20;
    int dodge = 2;

//Mob "Kashanta" characteristics
    mob kashanta = 
    {
        "Kashanta",
        averageHealth + (level*6) + mobStatRandomizer(6),
        averageDamage + (level*3) + mobStatRandomizer(5),
        dodge + mobStatRandomizer(3)
    };

    while (kashanta.health > 0) 
    {
        printf("Kashanta's HP: %d",kashanta.health);

        printf("'s HP:");
        break;
    }
    return 0;
}

int battle(int selector, int level) 
{
    int exp;
    int (*beginnerMob[])(int) = {kashanta};
    int (*intermediateMob[])(int) = {kashanta};
    int (*masterMob[])(int) = {kashanta};

    if (level < 10) 
    {
        exp = beginnerMob[selector](level);
    }
    else if (10 <= level && level <30) 
    {
        exp = intermediateMob[selector](level);
    }
    else 
    {
        exp = masterMob[selector](level);        
    }
    return exp;
}
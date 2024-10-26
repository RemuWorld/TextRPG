#ifndef TEXT_PLAYER_HEADER
#define TEXT_PLAYER_HEADER

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void clrscr();
int nickChoose(char playerName[21]);
char* namePrint(char* playerName);
int mobFinder();
int battle(int selector, int level);


#endif //TEXTPLAYER
#ifndef TEXT_PLAYER_HEADER
#define TEXT_PLAYER_HEADER

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void clrscr(); //clear screen
void gotoxy(int x, int y);  //coordinates of print methods

int nickChoose(char playerName[21]); //nickname choose
char* namePrint(char* playerName);  //name paste

int mobFinder();  //mob finder (random)
int kashanta(int level);  //mob(easy) 1 "kashanta"

int battle(int selector, int level); //battle mob


#endif //TEXTPLAYER
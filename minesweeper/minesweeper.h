#ifndef _MINESWEEPER__
#define _MINESWEEPER__

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINENUMBER 10

void Initboard(char board[ROWS][COLS],int rows,int cols,char set);
void DisplayBoard(char board[ROWS][COLS],int row,int col);
void SetMine(char board[ROWS][COLS],int row,int col,int number);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
int LinkShow(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int x,int y);



#endif
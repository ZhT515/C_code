#include<stdio.h>
#include<time.h>
#include <stdlib.h>

#define ROW 11				//展示时比实际数组小2，也就是一圈
#define COL 11

#define ROWS ROW + 2		//数组的实际大小
#define COLS COL + 2

#define Difficulty  10		//雷的数量

void InitBoard(char board[ROWS][COLS], int rows, int cols, char object);			//初始化数组

void PrintBoard(char board[ROWS][COLS], int rows, int cols);						//打印棋盘

void Setmine(char board[ROWS][COLS], int row, int col);		//布雷

void clear(char show[ROWS][COLS], char mine[ROWS][COLS], int rows, int cols, int row, int col);	//扫雷

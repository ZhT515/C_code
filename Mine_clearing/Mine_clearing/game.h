#include<stdio.h>
#include<time.h>
#include <stdlib.h>

#define ROW 11				//չʾʱ��ʵ������С2��Ҳ����һȦ
#define COL 11

#define ROWS ROW + 2		//�����ʵ�ʴ�С
#define COLS COL + 2

#define Difficulty  10		//�׵�����

void InitBoard(char board[ROWS][COLS], int rows, int cols, char object);			//��ʼ������

void PrintBoard(char board[ROWS][COLS], int rows, int cols);						//��ӡ����

void Setmine(char board[ROWS][COLS], int row, int col);		//����

void clear(char show[ROWS][COLS], char mine[ROWS][COLS], int rows, int cols, int row, int col);	//ɨ��

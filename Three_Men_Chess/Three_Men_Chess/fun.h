#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>


#define ROW 3			//行
#define COL 3			//列

void initialize_board(char board[ROW][COL],int row ,int col);		//初始化棋盘

void Print_board(char board[ROW][COL], int row, int col);			//打印棋盘

void Playermove(char board[ROW][COL], int row, int col);	    	//玩家下棋

void ComputerMove(char board[ROW][COL], int row, int col);			//电脑下棋

char Win_lose(char board[ROW][COL], int row, int col);				//判断胜负
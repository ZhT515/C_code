#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>


#define ROW 3			//��
#define COL 3			//��

void initialize_board(char board[ROW][COL],int row ,int col);		//��ʼ������

void Print_board(char board[ROW][COL], int row, int col);			//��ӡ����

void Playermove(char board[ROW][COL], int row, int col);	    	//�������

void ComputerMove(char board[ROW][COL], int row, int col);			//��������

char Win_lose(char board[ROW][COL], int row, int col);				//�ж�ʤ��
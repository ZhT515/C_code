#define _CRT_SECURE_NO_WARNINGS 1

#include"fun.h"

void menu()
{
	printf("*******************************\n");
	printf("********** 1. play ************\n");
	printf("********** 0. exit ************\n");
	printf("*******************************\n");
}
 
void game()
{
	char label = 0;							//胜负标签;胜利返回W，未胜利返回0，平局返回D
	char board[ROW][COL];
	initialize_board(board,ROW,COL);		//初始化棋盘
	Print_board(board,ROW,COL);				//打印棋盘
	while (1)
	{
		Playermove(board, ROW, COL);				//玩家下棋
		Print_board(board, ROW, COL);
		label = Win_lose(board, ROW, COL);

		if (label == 'W')
		{
			printf("*****************玩家胜利***************\n\n");
			Print_board(board, ROW, COL);
			break;
		}
		else if (label == 'D')
		{
			printf("******************平局******************\n\n");
			Print_board(board, ROW, COL);
			break;
		}

		ComputerMove(board, ROW, COL);				//电脑下棋
		Print_board(board, ROW, COL);
		label = Win_lose(board, ROW, COL);

		if (label == 'W')
		{
			printf("****************电脑胜利***************\n\n");
			Print_board(board, ROW, COL);
			break;
		}
		else if (label == 'D')
		{
			printf("******************平局******************\n\n");
			Print_board(board, ROW, COL);
			break;
		};
	}
}

int main()
{
	int input;
	srand((unsigned)time(NULL));		//srand()函数用来设置算法的种子，time(NULL)返回当前的时间，先调用srand(time(NULL))是把当前的时间作为种子，是程序每次运行产生不同的随机数序列。

	do
	{
		menu();			//每次开始，重新输出菜单
		printf("请选择模式：-->");
		scanf("%d", &input);		//录入
		switch (input)

		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("无效选择，请重新选择\n");
			break;
		}

	} while (input);			//有输入则继续循环

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("********************************\n");
	printf("*************0. exit************\n");
	printf("*************1. play************\n");
	printf("********************************\n");
}

void game()
{
	char mine[ROWS][COLS];			//存放有无雷的信息
	char show[ROWS][COLS];			//用于与用户交互

	InitBoard(mine, ROWS, COLS, '0');	//用0初始化雷
	InitBoard(show, ROWS, COLS, '*');	//用*初始化

	PrintBoard(show, ROW, COL);		//打印棋盘

	Setmine(mine, ROW, COL);		//在mine中放布雷信息，布雷区域为除外圈，所以只传输ROW

	clear(show, mine, ROWS, COLS, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));

	do 
	{
		menu();
		printf("请选择----->");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("无效输入，请重新输入\n");
				break;
		}
	} while (input);
	return 0;
}
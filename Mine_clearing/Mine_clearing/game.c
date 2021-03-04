#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char object) 				//初始化数组
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = object;							
		}
	}
}

void PrintBoard(char board[ROWS][COLS], int row, int col)								//打印棋盘，只打印中间11行11列，外面一圈只用计算
{
	int i = 1;
	int j = 1;

	printf("------------扫雷游戏----------------\n");
	for (i = 1; i <= col; i++)
	{
		printf("%d  ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf("%c  ", board[i][j]);
		}
		printf("\n");
	}
	printf("------------扫雷游戏----------------\n");

}

void Setmine(char board[ROWS][COLS], int row, int col)		//布雷
{
	int x, y, i;

	for (i = 1; i < Difficulty; i++)
	{
		x = rand() % row + 1;	//产生0到row的row+1个随机，所以需要加1 
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
		}

	}

}

int win(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)		//检查是否胜利，无未开拓元素即为胜利。
{
	int i = 1;
	int j = 1;

	for (i = 1; i < row; i++)
	{
		for (j = 1; j < col; j++)
		{
			if (show[i][j] == '*' && mine[i][j] != '1')
			{
				return 0;
			}
		}
	}

	return 1;
}
  
/*附近的雷数*/
int GetMineCont(char mine[ROWS][COLS],int x,int y)		// int+'0' 就是int转char 
{
	return mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] +
		mine[x - 1][y] + mine[x + 1][y] - 8 * '0';									//8个char型相加减去8个‘0’，就是char转int
}

void clear(char show[ROWS][COLS], char mine[ROWS][COLS], 
					int rows, int cols, int row, int col)	//扫雷
{
	int x,y,count,a,key;
	key = 0;
	while (1)
	{
		printf("请输入坐标（用空格隔开）：\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x < row + 1 && y>0 && y < col + 1)
		{

			if (mine[x][y] == '1')		//是否踩雷
			{
				count = 1;
				break;
			}
			else
			{
				key++;
				if (key == row * col - Difficulty)	//判断是否已经排出来row * col - Difficulty个安全格
				{
					count == 0;
					break;
				}
				a = GetMineCont(mine, x, y);		//附近的雷数
				show[x][y] = a + '0';				//附近的雷数

				PrintBoard(show, ROW, COL);
			}


		}
		else
		{
			printf("非法坐标重新输入\n");
		}

	}
	if (count == 1)
	{
		printf("**************踩雷喽************\n");
		PrintBoard(mine, ROW, COL);
	}
	else if(count == 0)
	{
		printf("**************赢了呦************\n");
		PrintBoard(mine, ROW, COL);
	}
}
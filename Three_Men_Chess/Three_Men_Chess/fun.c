#define _CRT_SECURE_NO_WARNINGS 1
#include"fun.h"

void initialize_board(char board[ROW][COL], int row, int col) //初始化位空格
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Print_board(char board[ROW][COL], int row, int col)	//打印棋盘:一行数据，一行分割。数据行： 0 | 0 | 0   分格行：---|---|---   共2个。
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)								//每次打印数据后打印分割，最后一列后不打印
				printf("|");
		}
		printf("\n");
		if (i < row - 1)									//每打印一行数据后打印分割，最后一行后不打印，这里不直接打印---|---|----是为了以后方便扩展
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void Playermove(char board[ROW][COL], int row, int col)			//玩家下棋
{
	int x = 0;
	int y = 0;
	printf("玩家下棋\n");

	while (1)
	{
		printf("请输入要下的坐标（用空格隔开）：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && y >= 1 && x <= row && y <= col)			//先判断坐标是否合法
		{
			if (board[x - 1][y - 1] != ' ')						//判断是否为空
			{
				printf("坐标已有棋子，请重新输入\n");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("非法坐标，请重新输入\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)		//电脑下棋
{
	int x, y;
	printf("电脑下棋\n");
	while (1)													//随机下一个位置
	{
		x = rand() % row;										//获取 0 - (row-1)中的一个数
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

static int Judge_draw(char board[ROW][COL], int row, int col)		//Judge_draw只在本源文件使用，所以加static，避免命名重复。
																	//判断是否和局，是就返回1
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char Win_lose(char board[ROW][COL], int row, int col)				//判断胜负；胜利返回W，未胜利返回L，平局返回D,否则返回0 
{
	int i = 0;

	for (i = 0; i < row; i++)										//判断三行，且都不等于空格
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')			//两两比较，不能连等
			return 'W';
	}

	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')		//判断三列，且都不等于空格
			return 'W';
	}


	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')			//判断主对角，且都不等于空格
		return 'W';
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')			//判断主对角，且都不等于空格
		return 'W';

	if (Judge_draw(board,row,col) == 1)								//判断是否和局
		return 'D';

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char object) 				//��ʼ������
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

void PrintBoard(char board[ROWS][COLS], int row, int col)								//��ӡ���̣�ֻ��ӡ�м�11��11�У�����һȦֻ�ü���
{
	int i = 1;
	int j = 1;

	printf("------------ɨ����Ϸ----------------\n");
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
	printf("------------ɨ����Ϸ----------------\n");

}

void Setmine(char board[ROWS][COLS], int row, int col)		//����
{
	int x, y, i;

	for (i = 1; i < Difficulty; i++)
	{
		x = rand() % row + 1;	//����0��row��row+1�������������Ҫ��1 
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
		}

	}

}

int win(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)		//����Ƿ�ʤ������δ����Ԫ�ؼ�Ϊʤ����
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
  
/*����������*/
int GetMineCont(char mine[ROWS][COLS],int x,int y)		// int+'0' ����intתchar 
{
	return mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] +
		mine[x - 1][y] + mine[x + 1][y] - 8 * '0';									//8��char����Ӽ�ȥ8����0��������charתint
}

void clear(char show[ROWS][COLS], char mine[ROWS][COLS], 
					int rows, int cols, int row, int col)	//ɨ��
{
	int x,y,count,a,key;
	key = 0;
	while (1)
	{
		printf("���������꣨�ÿո��������\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x < row + 1 && y>0 && y < col + 1)
		{

			if (mine[x][y] == '1')		//�Ƿ����
			{
				count = 1;
				break;
			}
			else
			{
				key++;
				if (key == row * col - Difficulty)	//�ж��Ƿ��Ѿ��ų���row * col - Difficulty����ȫ��
				{
					count == 0;
					break;
				}
				a = GetMineCont(mine, x, y);		//����������
				show[x][y] = a + '0';				//����������

				PrintBoard(show, ROW, COL);
			}


		}
		else
		{
			printf("�Ƿ�������������\n");
		}

	}
	if (count == 1)
	{
		printf("**************�����************\n");
		PrintBoard(mine, ROW, COL);
	}
	else if(count == 0)
	{
		printf("**************Ӯ����************\n");
		PrintBoard(mine, ROW, COL);
	}
}
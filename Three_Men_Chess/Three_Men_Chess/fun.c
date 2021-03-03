#define _CRT_SECURE_NO_WARNINGS 1
#include"fun.h"

void initialize_board(char board[ROW][COL], int row, int col) //��ʼ��λ�ո�
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

void Print_board(char board[ROW][COL], int row, int col)	//��ӡ����:һ�����ݣ�һ�зָ�����У� 0 | 0 | 0   �ָ��У�---|---|---   ��2����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)								//ÿ�δ�ӡ���ݺ��ӡ�ָ���һ�к󲻴�ӡ
				printf("|");
		}
		printf("\n");
		if (i < row - 1)									//ÿ��ӡһ�����ݺ��ӡ�ָ���һ�к󲻴�ӡ�����ﲻֱ�Ӵ�ӡ---|---|----��Ϊ���Ժ󷽱���չ
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

void Playermove(char board[ROW][COL], int row, int col)			//�������
{
	int x = 0;
	int y = 0;
	printf("�������\n");

	while (1)
	{
		printf("������Ҫ�µ����꣨�ÿո��������");
		scanf("%d %d", &x, &y);
		if (x >= 1 && y >= 1 && x <= row && y <= col)			//���ж������Ƿ�Ϸ�
		{
			if (board[x - 1][y - 1] != ' ')						//�ж��Ƿ�Ϊ��
			{
				printf("�����������ӣ�����������\n");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("�Ƿ����꣬����������\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)		//��������
{
	int x, y;
	printf("��������\n");
	while (1)													//�����һ��λ��
	{
		x = rand() % row;										//��ȡ 0 - (row-1)�е�һ����
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

static int Judge_draw(char board[ROW][COL], int row, int col)		//Judge_drawֻ�ڱ�Դ�ļ�ʹ�ã����Լ�static�����������ظ���
																	//�ж��Ƿ�;֣��Ǿͷ���1
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

char Win_lose(char board[ROW][COL], int row, int col)				//�ж�ʤ����ʤ������W��δʤ������L��ƽ�ַ���D,���򷵻�0 
{
	int i = 0;

	for (i = 0; i < row; i++)										//�ж����У��Ҷ������ڿո�
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')			//�����Ƚϣ���������
			return 'W';
	}

	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')		//�ж����У��Ҷ������ڿո�
			return 'W';
	}


	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')			//�ж����Խǣ��Ҷ������ڿո�
		return 'W';
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')			//�ж����Խǣ��Ҷ������ڿո�
		return 'W';

	if (Judge_draw(board,row,col) == 1)								//�ж��Ƿ�;�
		return 'D';

	return 0;
}
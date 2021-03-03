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
	char label = 0;							//ʤ����ǩ;ʤ������W��δʤ������0��ƽ�ַ���D
	char board[ROW][COL];
	initialize_board(board,ROW,COL);		//��ʼ������
	Print_board(board,ROW,COL);				//��ӡ����
	while (1)
	{
		Playermove(board, ROW, COL);				//�������
		Print_board(board, ROW, COL);
		label = Win_lose(board, ROW, COL);

		if (label == 'W')
		{
			printf("*****************���ʤ��***************\n\n");
			Print_board(board, ROW, COL);
			break;
		}
		else if (label == 'D')
		{
			printf("******************ƽ��******************\n\n");
			Print_board(board, ROW, COL);
			break;
		}

		ComputerMove(board, ROW, COL);				//��������
		Print_board(board, ROW, COL);
		label = Win_lose(board, ROW, COL);

		if (label == 'W')
		{
			printf("****************����ʤ��***************\n\n");
			Print_board(board, ROW, COL);
			break;
		}
		else if (label == 'D')
		{
			printf("******************ƽ��******************\n\n");
			Print_board(board, ROW, COL);
			break;
		};
	}
}

int main()
{
	int input;
	srand((unsigned)time(NULL));		//srand()�������������㷨�����ӣ�time(NULL)���ص�ǰ��ʱ�䣬�ȵ���srand(time(NULL))�ǰѵ�ǰ��ʱ����Ϊ���ӣ��ǳ���ÿ�����в�����ͬ����������С�

	do
	{
		menu();			//ÿ�ο�ʼ����������˵�
		printf("��ѡ��ģʽ��-->");
		scanf("%d", &input);		//¼��
		switch (input)

		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��Чѡ��������ѡ��\n");
			break;
		}

	} while (input);			//�����������ѭ��

	return 0;
}
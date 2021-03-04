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
	char mine[ROWS][COLS];			//��������׵���Ϣ
	char show[ROWS][COLS];			//�������û�����

	InitBoard(mine, ROWS, COLS, '0');	//��0��ʼ����
	InitBoard(show, ROWS, COLS, '*');	//��*��ʼ��

	PrintBoard(show, ROW, COL);		//��ӡ����

	Setmine(mine, ROW, COL);		//��mine�зŲ�����Ϣ����������Ϊ����Ȧ������ֻ����ROW

	clear(show, mine, ROWS, COLS, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));

	do 
	{
		menu();
		printf("��ѡ��----->");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("��Ч���룬����������\n");
				break;
		}
	} while (input);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
//1.�˵���0.1.��
//2.��Ϸ��Ҫ�������
#include<stdio.h>

void memu()
{
	printf("*************************\n");
	printf("*******  0 exit  ********\n");
	printf("*******  1 play  ********\n");
	printf("*************************\n");
	printf("****** ������0/1 ********\n");
}

void game()
{
	int k = 0;
	int n = rand() % 100 + 1; //1-100�������
	
	while (k != n)
	{
		printf("�������:>");
		scanf("%d", &k);
		if (k > n)
			printf("����\n");
		else if( k < n)
			printf("С��\n");
	}
	printf("���¶���");
}

int main()
{
	int a = 0;

	srand((unsigned int)time(NULL));//srand������������������ĳ�ʼ��������Ϊ�˷�ֹ�����ÿ���ظ�������ʹ��ϵͳʱ������ʼ����
	do
	{
		memu();
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("�������");
			break;
		}
	} while (a); //Ҫ��ִ�����жϣ�ѭ���ڻ�ȡ�ж�������

}
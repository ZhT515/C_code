#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()			//�������µı�����������������
//{
//	int a = 10;
//	int b = 20;
//	printf("����ǰ:a = %d b = %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("������:a = %d b = %d\n", a, b);
//
//}

/*********���������������в�ͬλ�ĸ���**********/
int Diff_bit(int a ,int b)			//�������������������õ������Ķ���������1�ĸ���
{
	int c;
	int count = 0;
	c = a ^ b;
	while (c)
	{
		c = c & (c - 1);
		count++;
	}
	return count;
}

/********��ӡ���������Ƶ�����λ��ż��λ********/
int Printbit(int num)
{
	for (int i = 31; i >= 1; i -= 2)	//����λ 1��3��5��***��29��31.��0��ʼ��λ������λ31������1Ϊֹ ��0������λ1λ���ǵ�1λ���Դ����ơ�����0-31λ��
	{
		printf("%d",(num >> i) & 1);	//num������λ i λ ����1�룬Ϊ1���ӡ1��Ϊ0��ӡ0.
	}
	printf("\n");
	for (int i = 30; i >= 0; i -= 2)	//����λ
	{
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
}

/*********ͳ�ƶ�������1�ĸ���**********/

int count_one_bit(int num)  //���ݵĶ����Ʊ���λ���м���1��ѭ����ѭ�����Σ������м������λ���㣬���������Ƚϸ�Ч
{
	int count = 0;
	while (num)
	{
		num = num & (num - 1);
		count++;
	}
	return count;
}

int count_one_bit1(int num)  //��Ҫ����32�Σ�Ч�ʽϵ�
{
	int count = 0;
	int i = 0;
	for (; i < 32; i++)
	{
		if (((num >> i)&1) == 1)		//num������λ i λ ����1�룬Ϊ1��1������ȡ��ÿһλ
			count++;
	}
	return count;
}

/*********���������������в�ͬλ�ĸ���**********/

//int main()			//���������������в�ͬλ�ĸ���
//{
//	int m, n;
//	while (scanf("%d,%d", &m, &n) == 2)		//scanf���ص�����ȷƥ��Ĳ�������
//	{
//		printf("%d", Diff_bit(m , n));		
//	}
//
//}

/***********��ӡ���������Ƶ�����λ��ż��λ************/

//int main()
//{
//	int apr = 1545646;
//	Printbit(apr);
//}

/***********ͳ�ƶ�������1�ĸ���************/

int main()
{
	int a;
	while (scanf("%d", &a) == 1)
	{
		printf("%d",count_one_bit(a));
		printf("%d",count_one_bit1(a));
	}
}
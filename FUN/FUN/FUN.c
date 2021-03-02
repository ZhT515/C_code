#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Prime_number(int a)   //判断一个数是不是素数。
{
	int b = 2;
	for (b = 2; b < a; b++)
	{
		if (0 == a % b)
			return 0;
	}
	return 1;
}

int leap_year(int a)		//判断闰年
{
	if (a % 4 == 0 && a % 100 != 0)
		return 1;
	if (a % 400 == 0)
		return 1;
	else
		return 0;
}

void Swap_int(int * ia,int * ib)//交换两个整数
{
	int c = 0;
	c = * ia;
	* ia = * ib;
	* ib = c;
}

void Mul_table(int a) // n 阶乘法表
{
	int j = 1;
	int i = 1;
	for (j = 1 ; j <= a ; j++)
	{
		for (i = 1; i <= a; i++)
		{
			printf("%2d * %2d = %3d ",i ,j , i * j);  //%2d占位
		}
		printf("\n");
	}
}

//*********函数判断素数*********//
//int main()
//{
//	int i = 100;
//	int num = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		num = Prime_number(i);
//		if (num == 1)
//			printf("%d\n",i);
//	}
//}

//***********函数判断闰年*********//
//int main()
//{
//	int year = 1000;
//	int Lyear = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		Lyear = leap_year(year);
//		if (Lyear == 1)
//			printf("%d\n",year);
//	}
//}


//*********交换两个整数******//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap_int(&a , &b);
//	printf("%d %d",a,b);
//}

//*********n 阶乘法表*********//
int main()
{
	int n = 0;
	printf("输出乘法口诀表的阶数：");
	scanf("%d" , &n);
	Mul_table(n);
	return 0;
}
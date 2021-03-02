#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()			//不创建新的变量，交换两个整数
//{
//	int a = 10;
//	int b = 20;
//	printf("交换前:a = %d b = %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("交换后:a = %d b = %d\n", a, b);
//
//}

/*********求两个数二进制中不同位的个数**********/
int Diff_bit(int a ,int b)			//先求两个数的异或，再求得到的数的二进制数中1的个数
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

/********打印整数二进制的奇数位和偶数位********/
int Printbit(int num)
{
	for (int i = 31; i >= 1; i -= 2)	//奇数位 1，3，5，***，29，31.从0开始移位，先移位31个，到1为止 ，0向右移位1位就是第1位，以此类推。共有0-31位。
	{
		printf("%d",(num >> i) & 1);	//num向右移位 i 位 ，和1与，为1则打印1，为0打印0.
	}
	printf("\n");
	for (int i = 30; i >= 0; i -= 2)	//奇数位
	{
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
}

/*********统计二进制中1的个数**********/

int count_one_bit(int num)  //数据的二进制比特位中有几个1，循环就循环几次，而且中间采用了位运算，处理起来比较高效
{
	int count = 0;
	while (num)
	{
		num = num & (num - 1);
		count++;
	}
	return count;
}

int count_one_bit1(int num)  //需要进行32次，效率较低
{
	int count = 0;
	int i = 0;
	for (; i < 32; i++)
	{
		if (((num >> i)&1) == 1)		//num向右移位 i 位 ，和1与，为1则1，方便取出每一位
			count++;
	}
	return count;
}

/*********求两个数二进制中不同位的个数**********/

//int main()			//求两个数二进制中不同位的个数
//{
//	int m, n;
//	while (scanf("%d,%d", &m, &n) == 2)		//scanf返回的是正确匹配的参数个数
//	{
//		printf("%d", Diff_bit(m , n));		
//	}
//
//}

/***********打印整数二进制的奇数位和偶数位************/

//int main()
//{
//	int apr = 1545646;
//	Printbit(apr);
//}

/***********统计二进制中1的个数************/

int main()
{
	int a;
	while (scanf("%d", &a) == 1)
	{
		printf("%d",count_one_bit(a));
		printf("%d",count_one_bit1(a));
	}
}
#define _CRT_SECURE_NO_WARNINGS 1
//1.菜单（0.1.）
//2.游戏（要随机数）
#include<stdio.h>

void memu()
{
	printf("*************************\n");
	printf("*******  0 exit  ********\n");
	printf("*******  1 play  ********\n");
	printf("*************************\n");
	printf("****** 请输入0/1 ********\n");
}

void game()
{
	int k = 0;
	int n = rand() % 100 + 1; //1-100的随机数
	
	while (k != n)
	{
		printf("请猜数字:>");
		scanf("%d", &k);
		if (k > n)
			printf("大了\n");
		else if( k < n)
			printf("小了\n");
	}
	printf("您猜对了");
}

int main()
{
	int a = 0;

	srand((unsigned int)time(NULL));//srand函数是随机数发生器的初始化函数。为了防止随机数每次重复，常常使用系统时间来初始化。
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
			printf("退出游戏");
			break;
		default:
			printf("输入错误");
			break;
		}
	} while (a); //要先执行再判断，循环内获取判断条件。

}
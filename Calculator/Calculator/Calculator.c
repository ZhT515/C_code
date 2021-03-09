#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Calcu()//计算器				//switch case显然更优
{
	double a, b, sum;
	char c;
	char e[4] = { '/','*','-','+' };
	while (scanf("%lf%c%lf", &a, &c, &b) != EOF)
	{
		if (c == e[0])
		{
			if (b == 0)
			{
				printf("Wrong!Division by zero!\n");
			}
			else
			{
				sum = a / b;
				printf("%.4f/%.4f=%.4f\n", a, b, sum);
			}
		}
		else if(c == e[1])
		{
			sum = a * b;
			printf("%.4f*%.4f=%.4f\n", a, b, sum);
		}
		else if (c == e[2])
		{
			sum = a - b;
			printf("%.4f-%.4f=%.4f\n", a, b, sum);
		}
		else if (c == e[3])
		{
			sum = a + b;
			printf("%.4f+%.4f=%.4f\n", a, b, sum);
		}
		else
		{
			printf("Invalid operation!\n");
		}
	}
}

void tri()		//空心▲   
{
	int input = 0;
	int i = 0;
	int j = 0;
	while (scanf("%d", &input) != EOF)
	{
		for (i = 0; i < input; i++)
		{
			if (i <= 1)
			{
				for (j = 0; j <= i; j++)
				{
					printf("* ");
				}
				for (j = input - 1; j > i; j--)
				{
					printf("  ");
				}
				printf(" \n");
			}
			else if (i == input - 1)
			{
				for (j = 0; j <= i; j++)
				{
					printf("* ");
				}
				printf(" \n");
			}
			else
			{
				printf("* ");
				for (j = 0; j < i - 1; j++)
				{
					printf("  ");
				}
				printf("* ");
				for (j = input - 1; j > i; j--)
				{
					printf("  ");
				}
				printf(" \n");

			}
		}
	}
}

void tri2()			//更优的思路：每行打印固定数量，判断什么时候才能输出*，否则输出空格
{
	int input = 0;
	int i = 0;
	int j = 0;
	while (scanf("%d", &input) != EOF)
	{
		for (i = 0; i < input; i++)
		{
			for (j = 0; j < input; j++)
			{
				if (j == 0 || j == i || i == input - 1)		//i = 0 不可以
					printf("* ");
				else
					printf("  ");
			}
			printf(" \n");
		}
	}
}

int main()
{
	//Calcu();
	//tri();
	tri2();
}
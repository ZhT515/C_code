#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define JIE 5					//阶数
#define N 2*JIE + 1				//（N-1）/ 2 阶杨辉三角	
#define A (N)/2					//中间位置，N要加括号

void Yanghui()
{
	int arr[JIE][N] = { 0 };
	int i, j;

	for (i = 0; i < JIE; i++)
	{
		if (i == 0)
		{
			arr[i][A] = 1;				//N/2就是正中间，从0开始
		}

		else
		{
			for (j = 0; j < N; j++)
			{
				if (j == 0 || j == N - 1)
				{
					if (i == JIE)
					{
						arr[i][j] = 1;
					}
				}
				else
				{
					arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
				}
			}
		}
	}
	for (i = 0; i < JIE; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (arr[i][j] == 0)
			{
				printf(" ");
			}
			else
			{
				printf("%d", arr[i][j]);

			}
		}
		printf("\n");
	}
}

int main()
{
	printf("%d",A);
	Yanghui();
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void array()//�����������У���С�������򣬽�һ��������������뵽�����У���֤����������������Ȼ������
{
	int n, input, temp, count;
	int arr[51] = { 0 };
	int i = 0;
	count = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &input);

    for (i = 0; i < n; i++)			
	{
		if (input < arr[i] && count == 0)		//���ڶ��С��arr[]�����
		{
			count = 1;
			printf("%d ", input);
		}
		printf("%d ", arr[i]);
	}
    if (count == 0)
    {
        printf("%d ", input);
    }
}

void Prime_number()		//ɸѡ����n���ڵ�����
{
	int n, i, a, j;
	int count = 0;
	int arr[101] = { 0 };
	int d = 3;
	int c = 3;
	
	scanf("%d",&n);

	for (i = 0; i <= n; i++)
	{
		arr[i] = i;
	}

	for (i = 2; i < n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if (arr[j] % i == 0)
			{
				arr[j] = 0;
			}
		}
	}
	for (i = 2; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			count++;
		}
		else
		{
			printf("%d ", arr[i]);
		}
	}
	printf("\n%d",count);
}

int main()
{
	//array();
	Prime_number();
}
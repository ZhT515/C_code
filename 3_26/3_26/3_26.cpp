#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct Stc
{
	int a;
	char c;
	char arr[];
};

void TEST1()
{
	int num = 0;
	scanf("%d",&num);

	int* ptr = NULL;
	ptr = (int*)malloc(num * sizeof(int));
	if (ptr != NULL)
	{
		int i = 0;
		for (i = 0; i < num; i++)
		{
			*(ptr + i) = 0;
		}
	}
	free(ptr);
	ptr = 0;
}

void TEST3()
{
	int* p = NULL;
	p = (int*)malloc(100);
	if (p != NULL)
	{
		//使用空间
	}
	else
	{
		exit(EXIT_FAILURE);
	}

	int* ptr = NULL;
	ptr = (int *)realloc(p,100);
	if (ptr != NULL)
	{
		p = ptr;		//指针要还给p
	}
	free(p);
	p = NULL;
}

void TEST2()
{
	int* p = NULL;
	p = (int*)calloc(10, sizeof(int));
	if (p != NULL)
	{
		//使用空间
	}
	free(p);
	p = NULL;
}

void TEST4()
{
	int i = 0;
	int* p = (int*)malloc(10 * sizeof(int));
	if (NULL == p)
	{
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= 10; i++)
	{
		*(p + i) = i;		//当i是10的时候越界访问
	}
	free(p);
	p = NULL;
}

void TEST4()
{
	int i = 0;
	int* p = (int*)malloc(10 * sizeof(int));
	if (NULL == p)
	{
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= 10; i++)
	{
		*(p + i) = i;		//当i是10的时候越界访问
	}
	free(p);
	p = NULL;
}

int main()
{
	Stc *s = (Stc*)malloc(sizeof(Stc) + 100 * sizeof(int));
	int vvv = 100;
	char arrr[20];
	TEST3();
	return 0;
}
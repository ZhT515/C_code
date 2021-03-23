#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int check()
{
	int i = 1;
	return (* (char * )&i);		//强制类型转为char，只取第一个字节，值为1时即为小端，为0即为大端
}

void memory()					//判断大小端存储
{
	int ret = check();
	if (ret == 1)
	{
		printf("小端");
	}
	else
	{
		printf("大端");
	}
}

void test1()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("a= %d;b = %d;c = %d", a, b, c);
}

void test2()
{
	char a = -128;
	printf("%u\n",a);		
}

void test3()
{
	char a = 128;
	printf("%u\n", a);
}

void test4()
{
	int i = -20;
	unsigned int j = 10;
	printf("%d\n",i + j);
}

void test5()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);
	}
}

void test6()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
}

void test7()
{
	unsigned char i = 0;
	for (i = 0; i <= 255; i++)
	{
		printf("aaaaaaaaa\n");
	}
}

void test8()
{
	int n = 9;
	float* pf = (float*)&n;
	printf("n = %d\n", n);
	printf("pf = %f\n", *pf);

	*pf = 9.0;
	printf("num = %d\n", n);
	printf("pf = %f\n", *pf);
}

void juxing()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//memory();
	juxing();
}
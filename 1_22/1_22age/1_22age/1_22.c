#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//************求两个数的较大值*****//
int main()
{
	int a, b;
	scanf("%d,%d",&a,&b);
	if (a > b)
		printf("较大数是%d", a);
	else
		printf("较大数是%d", b);
	return 0;

}
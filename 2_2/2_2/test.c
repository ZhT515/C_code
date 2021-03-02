#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//************将三个整数数按从大到小输出**********//
//int main()
//{
//
//	int arr[3] = {2 , 3 , 1};
//	if (arr[0] > arr[1])
//	{
//		if (arr[0] > arr[2])
//		{
//			if(arr[2] > arr[1])
//				printf("%d %d %d", arr[0], arr[2], arr[1]);
//			else
//				printf("%d %d %d", arr[0], arr[1], arr[2]);
//		}
//		else
//			printf("%d %d %d", arr[2],arr[0],arr[1]);
//	}
//	else if (arr[0] > arr[2])
//		printf("%d %d %d", arr[1], arr[0], arr[2]);
//	else
//	{
//		if (arr[1] > arr[2])
//			printf("%d %d %d", arr[1], arr[2], arr[0]);
//		else
//			printf("%d %d %d", arr[2], arr[1], arr[0]);
//	}
//
//}


//*************打印1-100之间所有3的倍数的数字*********//
//int main()
//{
//	int i = 1;
//	int a = 3;
//	for (a = 3; a < 100;a = 3 * i)
//	{
//		printf("%d ",a);
//		i++;
//	}
//}

//**********求这两个数的最大公约数********//
//int main()
//{
//	int a = 20;
//	int b = 40;
//	int c = 0;
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//
//	printf("%d\n", b);
//	return 0;
//}

//*********1000年到2000年之间的闰年******//
//四年一闰，百年不闰，四百年再闰
//int main()
//{
//	int i = 1000;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (i % 4 == 0 && i % 100 != 0)
//			printf("%d\n",i);
//
//		if (i % 400 == 0)
//			printf("%d\n",i);
//	}
//	return 0;
//}

////*****100~200之间的素数****//
//int main()
//{
//	int i = 100;
//	int n = 2;
//	int m = 0;
//	for (i; i <= 200; i++)
//	{
//		for (n; n < i; n++)   //循环内不定义变量（i/2）也可以
//		{
//			if (i % n == 0)
//				m = 1;
//		}
//		if (m == 0)
//			printf("%d ",i);
//		m = 0;
//		n = 2;   //n要复位
//	}
//}


//********* 1到 100 的所有整数中出现多少个数字9********//
//通过%的方式取当前数据的个位，检测个位数据是否为9如果是，给计数器加1通过 / 的方式取当前数据的十位，检测十位数据是否是9如果是，给计数器加1
//int main()
//{
//	int i = 1;
//	int count = 0;
//	for (i; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		if (i / 10 == 9)
//			count++; 
//	}
//	printf("%d",count);
//}

//**********计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值***/
//int main()
//{
//	int i = 0;
//	double n = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		n += flag * 1.0 / i;			//交替
//		flag = -flag;
//	}
//	printf("%f",n);
//}

//*********10 个整数中最大值****//
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)  //输入
//	{
//		scanf("%d",&arr[i]);
//	}
//
//	int max = 0;
//	for (i = 0; i < 10; i++)//逐个比较
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//	printf("最大的是 %d",max);
//	return 0;
//}

//*****乘法口诀表***//
//int main()
//{
//	int i = 1;
//	int j = 1;
//	for (i; i <= 9; i++)
//	{
//		for (j = 1; j <= 9; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i * j);    //%2d 两位
//		}
//		printf("\n");
//	}
//}

//**********二分查找*******//
int main()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int key = 6;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]);

	while (right >= left)
	{
		int i = left + (right - left) / 2;   //中点
		if (arr[i] > key) 
		{
			right = i - 1; 
		}
		else if (arr[i] < key)
		{
			left = i + 1;
		}
		else
		{
			printf("找到了，下标是：%d\n", i);
			break;
		}
	}
	if (left > right)
		printf("找不到\n");
	return 0;
}
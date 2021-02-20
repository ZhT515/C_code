#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


//************逐位打印***********
//int pr (int a)
//{
//	if (a > 9)
//	{
//		pr(a / 10);
//	}
//	printf("%d " , a%10);	
//}
//
//int main()
//{
//	int num = 1234;
//	pr(num);
//	return 0;
//}


//*************阶乘**********//
//int jc(int b)
//{
//	if (b < 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return b * jc(b - 1);
//	}
//}
//
//int main()
//{
//	int a = 5;
//	int d = jc(a);
//	printf("%d的阶乘:%d",a,d);
//	return 0;
//}


//****************实现strlen*****************//
//int strrlen(const char* str)
//{
//	if (*str == '\0')
//		return 0;
//	else 
//		return 1 + strrlen(str + 1);
//}
//int main()
//{
//	char* p = "abcde";
//	int len = strrlen(p);
//	printf("字符串长度为%d\n", len);
//	return 0;
//}

//************计算一个数的每位之和（递归实现）**********//
//int sum (int a)
//{
//	if (a > 9)
//	{
//		return  sum(a / 10) + a % 10;
//	}
//	 return  a ;
//}
//
//int main()
//{
//	int num = 1234;
//	int sum1 = sum(num);
//	printf("每位之和为：%d",sum1);
//	return 0;
//}


//************斐波那契数列*********//
//int fib(int a)			//递归
//{
//	if (a > 2)
//	{
//		return fib(a - 1) + fib(a - 2);
//	}
//	else
//		return 1;
//}
//
//int fib2(int b)			//非递归
//{
//	int num1 = 1;
//	int num2 = 1;
//	int newnum = 1;
//	while (2 < b)
//	{
//		newnum = num1 + num2;
//		num1 = num2;
//		num2 = newnum;
//		b--;
//	}
//	return newnum;
//}
//
//int main()
//{
//	int n;
//	printf("第几个斐波那契数：");
//	scanf("%d",&n);
//	int f = fib(n);
//	int g = fib2(n);
//	printf("第%d个斐波那契数是%d（递归）\n",n,f);
//	printf("第%d个斐波那契数是%d（非递归）\n", n, g);
//	return 0;
//}

//**********递归实现n的k次方********//
//int ex(int n, int k)
//{
//	if (1 < k)
//		return n * ex(n, k - 1);
//	else
//		return n;
//}
//
//int main()
//{
//	int a, b;
//	printf("底数：");
//	scanf("%d",&a);
//	printf("次数：");
//	scanf("%d", &b);
//	int c = ex(a, b);
//	printf("%d的%d次方是%d",a ,b, c);
//}

//***********字符串逆序（递归实现）**********//
int reverse(char* a)
{

		char tmp;
		int len = strlen(a);
		if (len > 1)
		{
			tmp = *a;
			*a = *(a + len - 1);
			*(a + len - 1) = '\0';   //  \0也要前移补位，切勿忘记。
			reverse(a + 1);
			*(a + len - 1) = tmp;
		}
}

int main()
{
	char arr[] = "CHDZHT";
	reverse(arr);
	printf("%s", arr);
}
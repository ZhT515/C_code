#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


//************��λ��ӡ***********
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


//*************�׳�**********//
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
//	printf("%d�Ľ׳�:%d",a,d);
//	return 0;
//}


//****************ʵ��strlen*****************//
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
//	printf("�ַ�������Ϊ%d\n", len);
//	return 0;
//}

//************����һ������ÿλ֮�ͣ��ݹ�ʵ�֣�**********//
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
//	printf("ÿλ֮��Ϊ��%d",sum1);
//	return 0;
//}


//************쳲���������*********//
//int fib(int a)			//�ݹ�
//{
//	if (a > 2)
//	{
//		return fib(a - 1) + fib(a - 2);
//	}
//	else
//		return 1;
//}
//
//int fib2(int b)			//�ǵݹ�
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
//	printf("�ڼ���쳲���������");
//	scanf("%d",&n);
//	int f = fib(n);
//	int g = fib2(n);
//	printf("��%d��쳲���������%d���ݹ飩\n",n,f);
//	printf("��%d��쳲���������%d���ǵݹ飩\n", n, g);
//	return 0;
//}

//**********�ݹ�ʵ��n��k�η�********//
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
//	printf("������");
//	scanf("%d",&a);
//	printf("������");
//	scanf("%d", &b);
//	int c = ex(a, b);
//	printf("%d��%d�η���%d",a ,b, c);
//}

//***********�ַ������򣨵ݹ�ʵ�֣�**********//
int reverse(char* a)
{

		char tmp;
		int len = strlen(a);
		if (len > 1)
		{
			tmp = *a;
			*a = *(a + len - 1);
			*(a + len - 1) = '\0';   //  \0ҲҪǰ�Ʋ�λ���������ǡ�
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
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//************���������������Ӵ�С���**********//
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


//*************��ӡ1-100֮������3�ı���������*********//
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

//**********���������������Լ��********//
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

//*********1000�굽2000��֮�������******//
//����һ�򣬰��겻���İ�������
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

////*****100~200֮�������****//
//int main()
//{
//	int i = 100;
//	int n = 2;
//	int m = 0;
//	for (i; i <= 200; i++)
//	{
//		for (n; n < i; n++)   //ѭ���ڲ����������i/2��Ҳ����
//		{
//			if (i % n == 0)
//				m = 1;
//		}
//		if (m == 0)
//			printf("%d ",i);
//		m = 0;
//		n = 2;   //nҪ��λ
//	}
//}


//********* 1�� 100 �����������г��ֶ��ٸ�����9********//
//ͨ��%�ķ�ʽȡ��ǰ���ݵĸ�λ������λ�����Ƿ�Ϊ9����ǣ�����������1ͨ�� / �ķ�ʽȡ��ǰ���ݵ�ʮλ�����ʮλ�����Ƿ���9����ǣ�����������1
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

//**********����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ***/
//int main()
//{
//	int i = 0;
//	double n = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		n += flag * 1.0 / i;			//����
//		flag = -flag;
//	}
//	printf("%f",n);
//}

//*********10 �����������ֵ****//
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)  //����
//	{
//		scanf("%d",&arr[i]);
//	}
//
//	int max = 0;
//	for (i = 0; i < 10; i++)//����Ƚ�
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//	printf("������ %d",max);
//	return 0;
//}

//*****�˷��ھ���***//
//int main()
//{
//	int i = 1;
//	int j = 1;
//	for (i; i <= 9; i++)
//	{
//		for (j = 1; j <= 9; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i * j);    //%2d ��λ
//		}
//		printf("\n");
//	}
//}

//**********���ֲ���*******//
int main()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int key = 6;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]);

	while (right >= left)
	{
		int i = left + (right - left) / 2;   //�е�
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
			printf("�ҵ��ˣ��±��ǣ�%d\n", i);
			break;
		}
	}
	if (left > right)
		printf("�Ҳ���\n");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//*******�������齻��*****//
//int main()
//{
//	int arrA[10] = {0};
//	int arrB[10] = {0};
//	int i = 0;
//	printf("������10������\n");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d",&arrA[i]);
//	}
//	printf("������10������\n");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arrB[i]);
//	}
//	int mid = 0;
//	for (i = 0; i < 10; i++)
//	{
//		mid = arrA[i];
//		arrA[i] = arrB[i];
//		arrB[i] = mid;
//	}
//	return 0;
//}

//********ʹ��ָ���ӡ��������*****//
int main()
{
	int i = 0;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int* p = arr;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		printf("%d ", *p );
		++p;
	}
}
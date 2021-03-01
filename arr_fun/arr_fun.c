#include<stdio.h>

void init(int arr1[] , int Array_length1)		//��ʼ������Ϊȫ0
{
	int i = 0;
	for (i = 0; i < Array_length1 ; i++)
	{
		arr1[i] = 0; 
	}
}

void print(int arr2[], int Array_length2)		//��ӡ�����ÿ��Ԫ��
{
	int j = 0;
	for (j = 0; j < Array_length2; j++)
	{
		printf("%d ",arr2[j]);
	}
	printf("\n");
}

void reverse(int arr3[], int Array_length3)		//�������Ԫ�ص�����
{
	int left = 0;
	int right = Array_length3 - 1;

	while (left < right)

	{
		int temp = 0;
		temp = arr3[left];
		arr3[left] = arr3[right];
		arr3[right] = temp;
		left++;
		right--;
	}
}

int main()
{
	int arr[10] = { 10 , 1 , 35 , 30 , 40 , 44 , 56 , 97 , 68 , 82 };
	int Array_length = sizeof(arr) / sizeof(arr[0]);
	printf("ԭ���飺");
	print(arr, Array_length);
	reverse(arr, Array_length);
	printf("���ú�");
	print(arr, Array_length);
	init(arr, Array_length);
	printf("��ʼ����");
	print(arr, Array_length);
	return 0;
}
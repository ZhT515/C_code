#include<stdio.h>

void init(int arr1[] , int Array_length1)		//初始化数组为全0
{
	int i = 0;
	for (i = 0; i < Array_length1 ; i++)
	{
		arr1[i] = 0; 
	}
}

void print(int arr2[], int Array_length2)		//打印数组的每个元素
{
	int j = 0;
	for (j = 0; j < Array_length2; j++)
	{
		printf("%d ",arr2[j]);
	}
	printf("\n");
}

void reverse(int arr3[], int Array_length3)		//完成数组元素的逆置
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
	printf("原数组：");
	print(arr, Array_length);
	reverse(arr, Array_length);
	printf("逆置后：");
	print(arr, Array_length);
	init(arr, Array_length);
	printf("初始化：");
	print(arr, Array_length);
	return 0;
}
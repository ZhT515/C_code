#include<stdio.h>

//整数类型 冒泡排序：比较两个相邻的元素，将值大的元素交换到右边。
void BubbleSort(int arr1[] , int Array_length1)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < Array_length1 - 1 ; i++ )   //n个元素，最多进行n - 1次排序 
	{
		int mark = 0;
		for (j = 0; j < Array_length1 - 1 - i; j++) //n个元素，每次进行 n - 1 - i次交换
		{
			int temp = 0;						
			if (arr1[j] > arr1[j + 1])
			{
				temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;
				mark = 1;		// 如果进行数据交换了，说明本次是无序的，就将mark设置为1
			}
		}
		if (!mark)	//取非
			return;	 // 元素没有交换，则本次开始冒泡时，数据已经有序了
	}
}
void Show(int arr2[], int Array_length2)
{
	int z = 0;
	for (z = 0; z < Array_length2; z++)
	{
		printf("%d ", arr2[z]);
	}
	printf("\n");
}
int main()
{
	int arr[10] = { 10 , 1 , 35 , 30 , 40 , 44 , 56 , 97 , 68 , 82 };
	int Array_length = sizeof(arr) / sizeof(arr[0]);   //数组元素个数
	Show(arr, Array_length);
	BubbleSort(arr, Array_length);
	Show(arr,Array_length);
	return 0;
}
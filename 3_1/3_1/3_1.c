#include<stdio.h>

//�������� ð�����򣺱Ƚ��������ڵ�Ԫ�أ���ֵ���Ԫ�ؽ������ұߡ�
void BubbleSort(int arr1[] , int Array_length1)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < Array_length1 - 1 ; i++ )   //n��Ԫ�أ�������n - 1������ 
	{
		int mark = 0;
		for (j = 0; j < Array_length1 - 1 - i; j++) //n��Ԫ�أ�ÿ�ν��� n - 1 - i�ν���
		{
			int temp = 0;						
			if (arr1[j] > arr1[j + 1])
			{
				temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;
				mark = 1;		// ����������ݽ����ˣ�˵������������ģ��ͽ�mark����Ϊ1
			}
		}
		if (!mark)	//ȡ��
			return;	 // Ԫ��û�н������򱾴ο�ʼð��ʱ�������Ѿ�������
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
	int Array_length = sizeof(arr) / sizeof(arr[0]);   //����Ԫ�ظ���
	Show(arr, Array_length);
	BubbleSort(arr, Array_length);
	Show(arr,Array_length);
	return 0;
}
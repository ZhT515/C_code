#include<stdio.h>
#include<stdlib.h>

void print(int arr[],int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int cmp(const void * p1 ,const void * p2)		//int�ȽϺ���,�����ָ�룬���Զ�����������������ת��
{
	return (*(int*)p1 - *(int*)p2);		//ǿ������ת��Ϊint�ͣ�*p1-2 �õ�������ֵ�����ֵ�� 
}

int cmpchar(const void* p1, const void* p2)		//char�ȽϺ���,�����ָ�룬���Զ�����������������ת��
{
	return (*(char*)p1 - *(char*)p2); 
}

void swap(void * p1 , void * p2, int size)			//����,p1 = ��ַ��*p1 = ����
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char*)p1 + i);			//void ǿ������ת��Ϊ char ;����char���׵�ַ��һ��һ���ֽڽ��н�����������size�Ρ�
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}

void myqsort(int *base,int count ,int size,int (* cmp)(void *,void *))			//ð���㷨
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)				//����n��Ԫ�أ�����n - 2�ֽ���
	{
		for (j = 0; j < count - 1 - i; j++)		// ÿ�ν���n- 1 -i�ν�����ÿ�ΰ����ķ������
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)			//charΪ��һ���ֽڵĵ�ַ������j*��ȣ����ǵ�j��Ԫ�أ�j+1���ǵ�j+1��Ԫ��.
			{
				swap((char*)base + j * size, (char*)base + (j + 1) * size, size);		//����char���׵�ַ��һ��һ���ֽڽ��н�����������size�Ρ�
			}
		}
	}
}

int main()
{
	int arr[] = { 1,9,6,7,4,2,5,8,3,0 };
	char str[] = "acsdwfgb";
	//qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp);			//�����ַ�����鳤�ȣ�����Ԫ�����ʹ�С������ָ����ָ�ıȽϺ���������ֵΪ< 0 ��elem1 less than elem2 0 elem1 equivalent to elem2 ��> 0 elem1 greater than elem2 
	qsort(str, sizeof(str) / sizeof(str[0]), sizeof(char), cmpchar);
	//myqsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp);
	/// print(arr, sizeof(arr) / sizeof(arr[0]));
}
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

int cmp(const void * p1 ,const void * p2)		//int比较函数,输入空指针，可以对其根据数据类型灵活转变
{
	return (*(int*)p1 - *(int*)p2);		//强制类型转换为int型，*p1-2 得到两个数值相减的值。 
}

int cmpchar(const void* p1, const void* p2)		//char比较函数,输入空指针，可以对其根据数据类型灵活转变
{
	return (*(char*)p1 - *(char*)p2); 
}

void swap(void * p1 , void * p2, int size)			//交换,p1 = 地址，*p1 = 内容
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char*)p1 + i);			//void 强制类型转换为 char ;传递char型首地址，一个一个字节进行交换，共交换size次。
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}

void myqsort(int *base,int count ,int size,int (* cmp)(void *,void *))			//冒泡算法
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)				//共有n个元素，进行n - 2轮交换
	{
		for (j = 0; j < count - 1 - i; j++)		// 每次进行n- 1 -i次交换，每次把最大的放在最后
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)			//char为第一个字节的地址，加上j*宽度，就是第j个元素，j+1就是第j+1个元素.
			{
				swap((char*)base + j * size, (char*)base + (j + 1) * size, size);		//传递char型首地址，一个一个字节进行交换，共交换size次。
			}
		}
	}
}

int main()
{
	int arr[] = { 1,9,6,7,4,2,5,8,3,0 };
	char str[] = "acsdwfgb";
	//qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp);			//数组地址，数组长度，数组元素类型大小，函数指针所指的比较函数，返回值为< 0 ，elem1 less than elem2 0 elem1 equivalent to elem2 ，> 0 elem1 greater than elem2 
	qsort(str, sizeof(str) / sizeof(str[0]), sizeof(char), cmpchar);
	//myqsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp);
	/// print(arr, sizeof(arr) / sizeof(arr[0]));
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>

void* my_memcpy(void* dest, void* src, int num)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	while (num--)		//num个字节
	{
		*(char * )dest = *(char *)src;			//转移强制类型转化为char(一个字节)才可以进行操纵，void不能操作；
		((char*)dest)++;						//必须加括号，分清楚优先级。
		((char*) src)++;
	}
	return ret;
}

void* my_memmove(void* dest, void* src, int num)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	if (dest > src)			//当dest 处于 src之后。应当从后向前复制，可避免不能重叠的问题，反之从前向后
	{
		while (num--)		//num个字节，直接加上，即使最后段
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	else
	{
		while (num--)		//num个字节
		{
			*(char*)dest = *(char*)src;
			((char*)dest)++;
			((char*)src) ++;
		}
	}

	return ret;
}

int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	my_memcpy(arr2, arr1, 4);
	printf("%d\n", arr2[0]);
	char arr3[] = "abcdefghijk lmnopqrstuvwxyz zyxwvutsrqponml";
	my_memmove(arr3+20, arr3+15, 11);
	puts(arr3);
}
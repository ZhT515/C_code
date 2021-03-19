#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>

void* my_memcpy(void* dest, void* src, int num)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	while (num--)		//num���ֽ�
	{
		*(char * )dest = *(char *)src;			//ת��ǿ������ת��Ϊchar(һ���ֽ�)�ſ��Խ��в��ݣ�void���ܲ�����
		((char*)dest)++;						//��������ţ���������ȼ���
		((char*) src)++;
	}
	return ret;
}

void* my_memmove(void* dest, void* src, int num)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	if (dest > src)			//��dest ���� src֮��Ӧ���Ӻ���ǰ���ƣ��ɱ��ⲻ���ص������⣬��֮��ǰ���
	{
		while (num--)		//num���ֽڣ�ֱ�Ӽ��ϣ���ʹ����
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	else
	{
		while (num--)		//num���ֽ�
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
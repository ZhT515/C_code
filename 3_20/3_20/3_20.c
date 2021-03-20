#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

char* my_strncat(const char* dest, const char * src, int num)
{
	char* ret = dest;
	char* p2 = src;
	while (*ret)
	{
		ret++;
	}
	while (num--)
	{
		if (*p2)
		{
			*ret = *p2;
			p2++;
			ret++;
		}
		else
		{
			*ret = 0;
			ret++;
		}
	}
	return dest;
}

char* my_strncpy(char* dest, const char* src, int num)
{
	char* ret = src;
	for(int i= 0;i<num;i++)
	{
		if (*ret)
		{
			dest[i] = ret[i];
		}
		else
		{
			dest[i] = 0;
		}
	}
	return dest;
}

int main()
{
	char arr1[50] = "abcd";		//¸ø´óÐ¡
	char arr2[] = "efgh";
	char arr3[50] = { 0 };
	printf("%s\n", my_strncat(arr1, arr2, 5));
	printf("%s", my_strncat(arr3, arr2, 4));
}
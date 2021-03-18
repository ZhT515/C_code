#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strcat(char * dest,const char * s2)
{
	char* p2 = (char*)s2;
	char* dest1 = (char*)dest;
	while (*dest1)
	{
		dest1++;
	}
	while (*dest1 = *p2)
	{
		dest1++;
		p2++;
	}
}

int my_strlen(const char* str)
{
	char* s = (char*)str;
	int i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return i;
}

char* my_strcpy(const char * s1,const char* s2)
{
	assert(s1 != NULL);
	assert(s2 != NULL);
	char* p1 = (char*)s1;
	char* p2 = (char*)s2;
	while (*p1 = *p2)
	{
		p1++;
		p2++;
	}
	return *s1;
}

int my_strcmp(const char* s1, const char* s2)
{
	while (((unsigned char*)s1 - (unsigned char*)s2) && *s2)
	{
		s1++;
		s2++;
	}
	return (unsigned char*)s1 - (unsigned char*)s2;
}

int main()
{
	char arr1[80] = "abcd";
	char arr2[] = "efgh";
	char arr3[10] = { 0 };
	my_strcmp(arr1, arr2);
	printf("%d\n", my_strcmp(arr2, arr2));
	my_strcpy(arr3, arr2);
	printf("%s\n", arr3);
	int a = my_strlen(arr2);
	printf("%d\n", a);
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
}
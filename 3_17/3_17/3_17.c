#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strstr(const char* s1, const char* s2)
{
	assert(s1 && s2);
	char* cp = (char*)s1;

	if (*s2 == '\0')		//Ҫ�� == '\0'
	{
		return NULL;
	}

	while (*cp)					//  ��*cpָ��\0ʱ����ѭ����\0����0������ *cp == 0��*cp�ڴ˴��ȼۡ�
	{
		char* p1 = cp;
		char* p2 = (char*)s2;
		while ((*p1 == *p2) && *p1)
		{
			p1++;
			p2++;
			if (*p2 == '\0')
			{
				return cp;
			}
		}
		cp++;
	}
	return NULL;

}

char* my_strcat() //������char��������
{

}

int main()
{
	char arr1[] = "assvvafqw";
	char arr2[] = "ssvva";
	char* ret = my_strstr(arr1, arr2);
	if (ret != NULL)
	{
		printf("%s", ret);
	}
	else
	{
		printf("û����");
	}
	return 0;
}
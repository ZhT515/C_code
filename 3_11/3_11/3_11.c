#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Unit_step_fun()		//��λ�弤������ʱ��t�ϵ�ֵ��
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			printf("%f\n", 0.5);
		}
		else if (n > 0)
		{
			printf("%d\n", 1);
		}
		else
		{
			printf("%d\n", 0);
		}
	}
}

void strr()
{
	char a = '0';
	while (scanf("%c", &a) != EOF)
	{
		if (a == '\n')			//����Ҳ��һ���ַ�
			continue;
		if (a >= 'a' && a <= 'z')
		{
			a -= 32;
		}
		if (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
		{
			printf("Vowel\n");
		}
		else
		{
			printf("Consonant\n");
		}
	}
}


int main()
{
	strr();
	Unit_step_fun();
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int Spin(const char * aa,char * bb)
{
	char tmp[256] = { 0 };
	strcpy(tmp, aa);		//strcpy����string copy���ַ������ƣ�����д��strcpy��C++���Ե�һ����׼������strcpy�Ѻ���'\0'���������ַ������Ƶ���һ����ַ�ռ䣬����ֵ������Ϊchar * ��
	strcat(tmp, aa);  //C �⺯�� char *strcat(char *dest, const char *src) �� src ��ָ����ַ���׷�ӵ� dest ��ָ����ַ����Ľ�β��
	return strstr(tmp, bb) != NULL;		//strstr��C�����еĺ����������Ƿ����ַ������״γ����Ӵ��ĵ�ַ��
}

void Spin2(const char* aa, int k)
{
	char tmp[256] = { 0 };
	strcpy(tmp, aa);
	strcat(tmp, aa);
	char bb[256] = { 0 };
	char* str = tmp;
	str = str + k;
	for (int i = 0; i < sizeof(aa); i++)
	{
		bb[i] = *str;
		str++;
	}
}

int Young_matrix(int a[][5], int x, int y, int n)			//�������Ͼ�����ص��������Ա��е���һԪ�أ��·����ҷ�������һ�������ң��󷽺��Ϸ�������һ��С�ڡ�
{
	int i = x - 1;
	int j = 0;
	while (j < y && i >= 0)
	{
		if (a[j][i] > n)
		{
			i--;
		}
		else if (a[j][i] < n)
		{
			j++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	/*char a[] = "AABCD";
	char b[] = "BCDAA";
	int ret = Spin(a, b);
	printf("%d", ret);
	Spin2(a, 2);*/

	int a[][5] = { {1, 3, 5 ,7 ,9},
					{2, 4, 6, 8, 10},
					{3, 6, 9, 12, 15},
					{4, 8, 12, 16, 20},
					{5, 10, 15, 20, 25} };
	int n = 25;
	if (Young_matrix(a, 5, 5, n) == 1)
	{
		printf("�ҵ���");
	}
	else
	{
		printf("û�ҵ�");
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

#define switch(i) (((i) & 0xaaaaaaaa) >> 1 | ((i) & 0x55555555) << 1)		//һ�������ֵ�����λ��ż��λ����;��&��λ��������
//����λ�ó���Ҫ&��010101010101������ż��λ�ó���&��101010101010��������Ӧʮ�����Ʒֱ���555������aaa
//�ֱ��������ƺ�ͻ�һ�£�

#define myoffsetof(type,mem) (size_t)&(((type *)0)->mem)	//�Ƚ�0ת��Ϊһ���ṹ�����͵�ָ�룬�൱��ĳ���ṹ����׵�ַ��0��
//ÿһ����Ա��ƫ�����ͳ������0��ƫ������
//�Ը�ָ����->�������Ա����ȡ����ַ�����ڽṹ����ʼ��ַΪ0��
//��ʱ��Աƫ����ֱ���൱�ڶ�0��ƫ����
//ȡ���ó�Ա�ĵ�ַ��ǿת��size_t����ӡ������������ƫ������

struct stc1
{
	char name;
	int a;
	char str;
};

int my_atoi(const char * str)
{
	assert(*str);
	char* s1 = str;
	int num = 0;
	int a = 1;
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	while (*s1)
	{
		if (((*s1 >= '0') && (*s1 <= '9')) || *s1 == '-')		
		{
			count = 1;				//famen kai guan
			count1++;
			if (*s1 == '-')
			{
				a = -1;
			}
			else
			{
				num = (num * 10) + (*s1 - '0');
			}
		}
		if (count == 1)				//famen
		{
			count2++;
			if (count1 != count2)
			{
				if (num != 0)
					return a * num;
				else
					return 0;
			}
		}

		s1++;
	}
	if (count == 1)
	{
		if (num != 0)
			return a * num;
		else
			return 0;
	}
	else
		return 0;
}

int main()
{
	printf("%d\n", myoffsetof(struct stc1, a));
	printf("%d\n", switch(111));
	char arr1[] = "asdsd-111";
	int ret = my_atoi(arr1);
	printf("%d", ret);
	return 0;
}
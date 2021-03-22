#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

#define switch(i) (((i) & 0xaaaaaaaa) >> 1 | ((i) & 0x55555555) << 1)		//一个整数字的奇数位和偶数位交换;用&按位与来做；
//奇数位拿出，要&上010101010101……，偶数位拿出，&上101010101010……，对应十六进制分别是555……和aaa
//分别左移右移后就或一下，

#define myoffsetof(type,mem) (size_t)&(((type *)0)->mem)	//先将0转换为一个结构体类型的指针，相当于某个结构体的首地址是0。
//每一个成员的偏移量就成了相对0的偏移量。
//对该指针用->访问其成员，并取出地址，由于结构体起始地址为0，
//此时成员偏移量直接相当于对0的偏移量
//取出该成员的地址，强转成size_t并打印，就求出了这个偏移量。

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
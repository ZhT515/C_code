#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/***********消失的数字*************/
int missingNumber1(int* nums, int numsSize)			//求和相减
{
	int n = numsSize + 1;
	int m1 = 0, m2 = 0;
	for (int i = 0; i < n; i++)
	{
		m1 += i;
		if (i < (n - 1))
		{
			m2 += nums[i];
		}
	}
	return m1 - m2;
}

int missingNumber2(int* nums, int numsSize)			//异或
{
	int m = 0;
	for (int i = 0; i < numsSize + 1; i++)		//相当于合成一个大数组，00 1 22 33，出现两次的就会消失，留下的是没有重复的，异或具有交换律
	{
		m ^= i;
	}
	for (int i = 0; i < numsSize; i++)
	{
		m ^= nums[i];
	}
	return m;
}

/*************数组中数字出现的次数*************/
int* singleNumbers(int* nums, int numsSize, int* returnSize) 
{
	int xor = 0;
	int i;
	*returnSize = 2;		//数组长度
	for (i = 0; i < numsSize; i++)
	{
		xor ^= nums[i];
	}
	int* ret = (int*)malloc(sizeof(int) * 2);
	int flag = xor &(-xor);		//去除最右侧1（复数在内存中为补码）,因为两个数不一样在这一位不同，所以会是1（随便找一位为1 的都可）

	ret[0] = 0;
	ret[1] = 0;

	for (i = 0; i < numsSize; i++)
	{
		if ((nums[i] & flag) == 0)				//分组,如0010，只有倒数第二位为1才不等于0，通过这样将两个数分开。x,y在这一位必有一个为1，一个为0,所以会被分开。
		{
			ret[0] ^= nums[i];
		}
		else
		{
			ret[1] ^= nums[i];
		}
	}
	return ret;
}


int main()
{
	int* c = NULL;
	int num[8] = {1, 2, 10, 4, 1, 4, 3, 3};
	singleNumbers(num, 8, c);
	int nums[5] = { 3,0,1,5,2 };
	int a = missingNumber1(nums, 5);
	printf("%d\n", a);

	int b = missingNumber2(nums, 5);
	printf("%d\n", b);
	return 0;
}
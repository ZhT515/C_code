#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int reverseBits(int n)			//颠倒给定的 32 位无符号整数的二进制位。
{
	unsigned int a = 0;
	int i = 32;
	while (i--)
	{
		a <<= 1;		//用a存取出的最后一位，然后左移，留出空位，取下次
		a += n & 1;		//取出最后一位
		n >>= 1;		//不断更新最后一位+
	}
	return a;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
	int *ret = (int*)malloc(sizeof(int) * 2);  //开辟空间
	*returnSize = 2;
	int i = 0, j = 0, k;
	for (i = 0; i < numsSize; i++)
	{
		//if (*nums < target)  不能做这个判断。如果和为0

		for (j = i + 1; j < numsSize; j++)
		{
			if ((nums[i] + nums[j]) == target)
			{
				ret[0] = i;
				ret[1] = j;
				return ret;
			}
		}

	}
	*returnSize = 0; //要置0
	return 0;
}

int main()	
{
	int nums[4] = { 2, 7, 11, 15 };
	int target = 9;
	int n = 101014;
	reverseBits(n);
}
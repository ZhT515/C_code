#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int reverseBits(int n)			//�ߵ������� 32 λ�޷��������Ķ�����λ��
{
	unsigned int a = 0;
	int i = 32;
	while (i--)
	{
		a <<= 1;		//��a��ȡ�������һλ��Ȼ�����ƣ�������λ��ȡ�´�
		a += n & 1;		//ȡ�����һλ
		n >>= 1;		//���ϸ������һλ+
	}
	return a;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
	int *ret = (int*)malloc(sizeof(int) * 2);  //���ٿռ�
	*returnSize = 2;
	int i = 0, j = 0, k;
	for (i = 0; i < numsSize; i++)
	{
		//if (*nums < target)  ����������жϡ������Ϊ0

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
	*returnSize = 0; //Ҫ��0
	return 0;
}

int main()	
{
	int nums[4] = { 2, 7, 11, 15 };
	int target = 9;
	int n = 101014;
	reverseBits(n);
}
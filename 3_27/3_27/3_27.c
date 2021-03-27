#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/***********��ʧ������*************/
int missingNumber1(int* nums, int numsSize)			//������
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

int missingNumber2(int* nums, int numsSize)			//���
{
	int m = 0;
	for (int i = 0; i < numsSize + 1; i++)		//�൱�ںϳ�һ�������飬00 1 22 33���������εľͻ���ʧ�����µ���û���ظ��ģ������н�����
	{
		m ^= i;
	}
	for (int i = 0; i < numsSize; i++)
	{
		m ^= nums[i];
	}
	return m;
}

/*************���������ֳ��ֵĴ���*************/
int* singleNumbers(int* nums, int numsSize, int* returnSize) 
{
	int xor = 0;
	int i;
	*returnSize = 2;		//���鳤��
	for (i = 0; i < numsSize; i++)
	{
		xor ^= nums[i];
	}
	int* ret = (int*)malloc(sizeof(int) * 2);
	int flag = xor &(-xor);		//ȥ�����Ҳ�1���������ڴ���Ϊ���룩,��Ϊ��������һ������һλ��ͬ�����Ի���1�������һλΪ1 �Ķ��ɣ�

	ret[0] = 0;
	ret[1] = 0;

	for (i = 0; i < numsSize; i++)
	{
		if ((nums[i] & flag) == 0)				//����,��0010��ֻ�е����ڶ�λΪ1�Ų�����0��ͨ���������������ֿ���x,y����һλ����һ��Ϊ1��һ��Ϊ0,���Իᱻ�ֿ���
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
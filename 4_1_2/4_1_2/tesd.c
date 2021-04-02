#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)		//更优思路;解题思路：从最大值开始合并，所以合并从两个数组的末尾元素开始合并，依次把最大的元素放到末尾即可。
{
	int i = 0, j = 0;
	int n2 = n, n1 = m;
	for (i = 0; i < n2; i++)					//遍历
	{
		for (j; j < n1; j++)			//j的值不重新开始，而是续着
		{
			if (nums1[j] >= nums2[i])			//若1的大于2的，则插入
			{
				for (int j2 = n1 - 1; j2 >= j; j2--)
				{
					nums1[j2 + 1] = nums1[j2];
				}
				nums1[j] = nums2[i];
				n1++;							//1的实时长度+1
				break;
			}
		}
	}
	int k = n1;					//nums1从n1开始，n1 -m就是实时的2的位置
	int i2 = n1 - m;
	for (k; k < n + m; k++)
	{
		nums1[k] = nums2[i2];
		i2++;
	}
}

void rotate(int* nums, int numsSize, int k)		//旋转数组
{
	int a, i = 0, j = 0;		//双重循环，更新最后一位，挪到前面
	for (i = 0; i < k; i++)
	{
		a = nums[numsSize - 1];
		for (j = numsSize - 2; j >= 0; j--)
		{
			nums[j + 1] = nums[j];
		}
		nums[0] = a;
	}
}

//void rotate2(int* nums, int numsSize, int k) 
//{
//	int a, i = 0, j = 0;
//	int mark = 0;
//	if (numsSize != k)
//	{
//		for (i = 0; i < k; i++)
//		{
//			mark = nums[i];
//			nums[i] = nums[numsSize - k + i];
//			nums[numsSize - k + i] = mark;
//		}
//
//		for (i = 0; i < k; i++)
//		{
//			mark = nums[k + i];
//			nums[k + i] = nums[numsSize - k + i];
//			nums[numsSize - k + i] = mark;
//		}
//	}
//}

int main()
{
	//int nums1[6] = { 4, 5, 6, 0, 0, 0 }, m = 3, nums2[3] = { 1, 2, 3 }, n = 3;
	//merge(nums1, 6, m, nums2, 3, n);
	int nums[2] = { 1,2 }, k = 2;
	rotate2(nums, 2, 2);
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)		//����˼·;����˼·�������ֵ��ʼ�ϲ������Ժϲ������������ĩβԪ�ؿ�ʼ�ϲ������ΰ�����Ԫ�طŵ�ĩβ���ɡ�
{
	int i = 0, j = 0;
	int n2 = n, n1 = m;
	for (i = 0; i < n2; i++)					//����
	{
		for (j; j < n1; j++)			//j��ֵ�����¿�ʼ����������
		{
			if (nums1[j] >= nums2[i])			//��1�Ĵ���2�ģ������
			{
				for (int j2 = n1 - 1; j2 >= j; j2--)
				{
					nums1[j2 + 1] = nums1[j2];
				}
				nums1[j] = nums2[i];
				n1++;							//1��ʵʱ����+1
				break;
			}
		}
	}
	int k = n1;					//nums1��n1��ʼ��n1 -m����ʵʱ��2��λ��
	int i2 = n1 - m;
	for (k; k < n + m; k++)
	{
		nums1[k] = nums2[i2];
		i2++;
	}
}

void rotate(int* nums, int numsSize, int k)		//��ת����
{
	int a, i = 0, j = 0;		//˫��ѭ�����������һλ��Ų��ǰ��
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
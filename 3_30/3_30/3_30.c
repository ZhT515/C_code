#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) //27. �Ƴ�Ԫ��,����ҳ��������һ�����棬�ܳ��ȼ�һ
{
	int i = 0;
	int ret = 0;
	int l = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == val)
		{
			if (i != (numsSize - 1))
			{
				nums[i] = nums[numsSize- 1];
				numsSize--;
				ret++;
				i--;
				l++;
			}
			else
			{
				ret++;
			}
		}
	}
	return (numsSize + l - ret);
}

int removeDuplicates(int* nums, int numsSize)
{
	if (nums == NULL || numsSize == 0) {
		return 0;
	}
	int last = nums[0];
	int ret = 1;
	for (int i = 1; i < numsSize; i++) {
		int cur = nums[i];
		if (last != cur)				//�൱��Ѱ�ҳ�ÿһ����ֵͬ������˳����������У����ڴ�1��ʼ�����ᷢ������δ�б��������
		{
			last = cur;		// ��ʼѰ����һ��
			nums[ret++] = cur;		 //��1 ��ʼ���������ظ����ǣ�����ÿ�μ��Ҳ�Ǻ�i��ͬ���ٶ�
		}
	}
	return ret;
}

int main()
{
	int nums[10] = { 0,0,1,1,1,2,2,3,3,4 };
	int len = removeDuplicates(nums, 10);
	for (int i = 0; i < len; i++) {
		printf("%d", nums[i]);
	}
}
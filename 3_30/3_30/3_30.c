#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) //27. 移除元素,逐个找出，用最后一个代替，总长度减一
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
		if (last != cur)				//相当于寻找出每一个不同值，按照顺序存在数组中，由于从1开始，不会发生覆盖未判别数的情况
		{
			last = cur;		// 开始寻找下一个
			nums[ret++] = cur;		 //从1 开始，不存在重复覆盖，即便每次激活，也是和i相同的速度
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
#include<stdio.h>

int getMinDistance(int* nums, int numsSize, int target, int start) //到目标元素的最小距离
{
    int j = numsSize;
    int ret = numsSize;
    for (int i = 0; i < j; i++)
    {
        if (nums[i] == target)
        {
            if (abs(i - start) < ret)
            {
                ret = abs(i - start);
            }
        }
    }
    return ret;
}

int main()
{

}
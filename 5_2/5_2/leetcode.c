#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int getMinDistance(int* nums, int numsSize, int target, int start)      //5746. ��Ŀ��Ԫ�ص���С����
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

int cmpfunc(const void* a, const void* b)               //��ָ Offer 03. �������ظ�������   
{
    return (*(int*)a - *(int*)b);
}

int findRepeatNumber(int* nums, int numsSize) {
    int i = numsSize;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int ret = nums[i - 1];;
    for (int j = 0; j < i; j++)
    {
        if (j == i - 1)
        {
            break;
        }
        if (nums[j] == nums[j + 1])
        {
            ret = nums[j];
            break;
        }
    }

    return ret;
}

int main()
{

}
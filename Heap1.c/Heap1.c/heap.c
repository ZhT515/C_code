#include"heap.h"

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)	//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
{
	HP hp;

	HeapInitial(&hp, arr, arrSize);

	int* retarr = (int*)malloc(sizeof(int) * k);

	for (int i = 0; i < k; i++)
	{
		retarr[i] = HeadTop(&hp);
		HeapPop(&hp);
	}

	HeapDestory(&hp);

	*returnSize = k;
	return retarr;
}

int* getLeastNumbers1(int* arr, int arrSize, int k, int* returnSize)//
{
    if (k == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int* retarr = (int*)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++)   //建堆
    {
        retarr[i] = arr[i];
    }

    for (int j = (k - 2) / 2; j >= 0; j--)    //建大堆
    {
        AdjustDown(retarr, k, j);
    }

    for (int i = k; i < arrSize; i++)
    {
        if (arr[i] < retarr[0])
        {
            retarr[0] = arr[i];             //如果当前的堆顶大于当前的值，则替换，重新堆
            AdjustDown(retarr, k, 0);         //重新排堆
        }
    }                                       //结束后就是最小的七个

    *returnSize = k;
    return retarr;
}


int main()
{
	int a[] = { 15, 18, 28, 34, 65, 19, 49, 25, 37, 27 };
	int n = sizeof(a) / sizeof(a[0]);

	HP hp;
	HeapInitial(&hp, a, n);
	HeadPrint(&hp);

	HeapPush(&hp, 1);
	HeadPrint(&hp);

	HeapPush(&hp, 111);
	HeapPop(&hp);
	HeadPrint(&hp);

	HeapDestory(&hp);
}
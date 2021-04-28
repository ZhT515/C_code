#include"heap.h"

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)	//������������ arr ���ҳ�������С�� k ���������磬����4��5��1��6��2��7��3��8��8�����֣�����С��4��������1��2��3��4��
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

    for (int i = 0; i < k; i++)   //����
    {
        retarr[i] = arr[i];
    }

    for (int j = (k - 2) / 2; j >= 0; j--)    //�����
    {
        AdjustDown(retarr, k, j);
    }

    for (int i = k; i < arrSize; i++)
    {
        if (arr[i] < retarr[0])
        {
            retarr[0] = arr[i];             //�����ǰ�ĶѶ����ڵ�ǰ��ֵ�����滻�����¶�
            AdjustDown(retarr, k, 0);         //�����Ŷ�
        }
    }                                       //�����������С���߸�

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
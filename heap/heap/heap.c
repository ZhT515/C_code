#include<stdio.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void  AdjustDown(int*a,int n,int parents)			//建小堆
{
	int child = parents * 2 + 1;	//左孩子

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])		//取较小的孩子
		{
			++child;
		}

		if (a[child] < a[parents])								//取较小的作为父亲
		{
			Swap(&a[(child)], &a[parents]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void  AdjustDown1(int* a, int n, int parents)
{
	int child = parents * 2 + 1;	//左孩子

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])		//取较小的孩子
		{
			++child;
		}

		if (a[child] > a[parents])								//取较小的作为父亲
		{
			Swap(&a[(child)], &a[parents]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)			/// 排升序，建大堆
{
	for (int i = (n - 2) / 2; i >= 0; i--)		//从最后一个根起建堆，(n - 2) / 2是最后一个根节点
	{
		AdjustDown1(a, n, i);
	}

	int end = n - 1;
	while (end)							//把最大的放在最后，然后去掉它重新建堆。
	{
		Swap(&a[0], &a[end]);			//把最大的放在最后

		AdjustDown1(a, end, 0);			//重新建堆。

		end--;							
	}
}


int main()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(a) / sizeof(a[0]);
	AdjustDown(a, n, 0);

}
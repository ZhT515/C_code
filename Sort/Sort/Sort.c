#include"Sort.h"

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* a, int* b)		//交换函数
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* a, int n)
{
	
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];		//tmp在每循环内不变
		while (end >= 0)
		{
			//int tmp = a[end + 1];   每次进来就会更新掉tmp达不到目的
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				//a[end + 1] = tmp;		
				break;
			}
		}
		a[end + 1] = tmp;				//还要考虑end<0跳出循环的情况，即tmp比a[0]还要小，所以要在循环外
	}
}

void ShellSort(int* a, int n)			// 希尔排序
{
	int gap = n;
	while (gap > 1)				//因为是进入循环后才操作gap,所以最后一次循环必然是 gap == 1.即一次直接插入排序
	{
		gap = (gap / 5 + 1);	//防止gap/5 = 0,所以需要+1，

		for (int i = 0; i < n - gap; i++)	//直接++就可以回到之前的那一组
		{
			int end = i;
			int tmp = a[end + gap];			//所有地方相当于把直接插入排序的1变成了gap
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = tmp;
		}
	}
}

void SelectSort(int* a, int n)			// 选择排序
{
	int left = 0;
	int right = n - 1;

	while (left < right)	//当错过了，或相等就结束了
	{
		int max = left;			//都设置为第一个元素,每次换完上下界都要更新
		int min = left;
		for (int i = left; i <= right; i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}

			if (a[i] < a[min])
			{
				min = i;
			}
		}

		Swap(&a[min], &a[left]);
		if (max == left)			//可能存在max == left,此时已经被换走了，所以要找当前的位置，即min
		{
			max = min;
		}
		Swap(&a[max], &a[right]);

		left++;
		right--;
	}
}

/*
* 堆是数组
n: 数组大小
root: 根位置
*/

void AdjustDown(int* a, int n, int root)	//重建大堆
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)		//保证合法性
	{
		if (child + 1 < n && a[child] < a[child + 1])		//找更大的孩子
		{
			child++;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);		//如果孩子更大，交换
			parent = child;						//交换后的子树需要重新判定
			child = 2 * parent + 1;
		}
		else									//没有发生交换，因为两个子树都是有序的，所以整个树都是有序
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)			// 堆排序1.建堆 2.排序
{
	assert(a);

	int j = (n - 2) / 2;				//最小的父亲，从最小的父亲开始，-1就是上一个父亲，从此建堆
	for (; j >= 0; j--)
	{
		AdjustDown(a, n, j);
	}

	int i = n;
	while (i--)				//排序,0位置和最后一个位置交换
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);		//还剩i个
	}
}

void BubbleSort(int* a, int n)
{
	for (int j = n; j > 0; --j)
	{
		int change = 0;
		for (int i = 0; i < j - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				change = 1;
				Swap(&a[i], &a[i + 1]);
			}
		}

		if (change == 0)
		{
			break;
		}
	}
}

int GetMid(int* a, int left, int right)			//防止有序时退化
{
	int mid = (left + right) >> 1;			//相当于除二

	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[right] > a[mid])
		{
			return mid;
		}
		else if (a[right] < a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// 快速排序hoare版本
int PartSort1(int* a, int left, int right)

{
	int midIndex = GetMid(a, left, right);
	Swap(&a[left], &a[midIndex]);				//把找到的中放在最左侧，不用改算法

	int keyi = left;

	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])			//做key的另一个先走，就一定是比key小的停下来
		{
			right--;
		}

		while (left < right && a[left] <= a[keyi])			//left < right &&防止越界
		{
			left++;
		}

		Swap(&a[right], &a[left]);
	}

	Swap(&a[keyi], &a[left]);		//交换，把key放在应在的位置

	return left;
}



// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMid(a, left, right);
	Swap(&a[left], &a[midIndex]);				//把找到的中放在最左侧，不用改算法

	int key = a[left];							//存起来


	while (left < right)
	{
		while (left < right && a[right] >= key)			//做key的另一个先走，就一定是比key小的停下来
		{
			right--;
		}

		a[left] = a[right];			//把小的放在坑里，然后自己变成坑

		while (left < right && a[left] <= key)			//left < right &&防止越界
		{
			left++;
		}

		a[right] = a[left];		//把大的放在坑里，然后自己变成坑
	}
	a[left] = key;
	return left;
}

int PartSort3(int* a, int left, int right) //前后指针
{
	int midIndex = GetMid(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int keyi = left;
	int per = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] <= a[keyi] && ++per != cur)
		{
			Swap(&a[cur], &a[per]);
		}

		cur++;
	}

	Swap(&a[keyi], &a[per]);
	return per;			//返回per,此时per才是本次排序的key
}

void QuickSort(int* a, int begin, int end )
{
	if (begin >= end)
	{
		return;
	}

	if (end - begin > 20)		//小区间优化，小于10时减少递归
	{
		int keyi = PartSort3(a, begin, end);

		QuickSort(a, begin, keyi - 1);		//左右两个子区间

		QuickSort(a, keyi + 1, end);
	}
	else
	{
		InsertSort(a + begin, end - begin + 1); //注意区间
	}
}


//快排非递归
//用栈来保存下来要处理的区间
void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, begin);				//先把初始的给进去
	StackPush(&st, end);

	while (StackEmpty(&st))				//不为空就继续
	{
		int left, right;
		right = StackTop(&st);			//将数据取出
		StackPop(&st);

		left = StackTop(&st);			//存先左后右,取时反过来
		StackPop(&st);

		int keyi = PartSort3(a, left, right);

		if (keyi - 1 > left)		//左右区间不为零
		{
			StackPush(&st, left);					//key的左侧
			StackPush(&st, keyi - 1);
		}

		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);				//key的右侧
			StackPush(&st, right);
		}
	}
}


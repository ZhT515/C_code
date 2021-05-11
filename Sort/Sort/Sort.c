#include"Sort.h"

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* a, int* b)		//��������
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
		int tmp = a[end + 1];		//tmp��ÿѭ���ڲ���
		while (end >= 0)
		{
			//int tmp = a[end + 1];   ÿ�ν����ͻ���µ�tmp�ﲻ��Ŀ��
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
		a[end + 1] = tmp;				//��Ҫ����end<0����ѭ�����������tmp��a[0]��ҪС������Ҫ��ѭ����
	}
}

void ShellSort(int* a, int n)			// ϣ������
{
	int gap = n;
	while (gap > 1)				//��Ϊ�ǽ���ѭ����Ų���gap,�������һ��ѭ����Ȼ�� gap == 1.��һ��ֱ�Ӳ�������
	{
		gap = (gap / 5 + 1);	//��ֹgap/5 = 0,������Ҫ+1��

		for (int i = 0; i < n - gap; i++)	//ֱ��++�Ϳ��Իص�֮ǰ����һ��
		{
			int end = i;
			int tmp = a[end + gap];			//���еط��൱�ڰ�ֱ�Ӳ��������1�����gap
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

void SelectSort(int* a, int n)			// ѡ������
{
	int left = 0;
	int right = n - 1;

	while (left < right)	//������ˣ�����Ⱦͽ�����
	{
		int max = left;			//������Ϊ��һ��Ԫ��,ÿ�λ������½綼Ҫ����
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
		if (max == left)			//���ܴ���max == left,��ʱ�Ѿ��������ˣ�����Ҫ�ҵ�ǰ��λ�ã���min
		{
			max = min;
		}
		Swap(&a[max], &a[right]);

		left++;
		right--;
	}
}

/*
* ��������
n: �����С
root: ��λ��
*/

void AdjustDown(int* a, int n, int root)	//�ؽ����
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)		//��֤�Ϸ���
	{
		if (child + 1 < n && a[child] < a[child + 1])		//�Ҹ���ĺ���
		{
			child++;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);		//������Ӹ��󣬽���
			parent = child;						//�������������Ҫ�����ж�
			child = 2 * parent + 1;
		}
		else									//û�з�����������Ϊ����������������ģ�������������������
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)			// ������1.���� 2.����
{
	assert(a);

	int j = (n - 2) / 2;				//��С�ĸ��ף�����С�ĸ��׿�ʼ��-1������һ�����ף��Ӵ˽���
	for (; j >= 0; j--)
	{
		AdjustDown(a, n, j);
	}

	int i = n;
	while (i--)				//����,0λ�ú����һ��λ�ý���
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);		//��ʣi��
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

int GetMid(int* a, int left, int right)			//��ֹ����ʱ�˻�
{
	int mid = (left + right) >> 1;			//�൱�ڳ���

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

// ��������hoare�汾
int PartSort1(int* a, int left, int right)

{
	int midIndex = GetMid(a, left, right);
	Swap(&a[left], &a[midIndex]);				//���ҵ����з�������࣬���ø��㷨

	int keyi = left;

	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])			//��key����һ�����ߣ���һ���Ǳ�keyС��ͣ����
		{
			right--;
		}

		while (left < right && a[left] <= a[keyi])			//left < right &&��ֹԽ��
		{
			left++;
		}

		Swap(&a[right], &a[left]);
	}

	Swap(&a[keyi], &a[left]);		//��������key����Ӧ�ڵ�λ��

	return left;
}



// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMid(a, left, right);
	Swap(&a[left], &a[midIndex]);				//���ҵ����з�������࣬���ø��㷨

	int key = left;


	while (left < right)
	{
		while (left < right && a[right] >= key)			//��key����һ�����ߣ���һ���Ǳ�keyС��ͣ����
		{
			right--;
		}

		a[left] = a[right];			//��С�ķ��ڿ��Ȼ���Լ���ɿ�

		while (left < right && a[left] <= key)			//left < right &&��ֹԽ��
		{
			left++;
		}

		a[right] = a[left];		//�Ѵ�ķ��ڿ��Ȼ���Լ���ɿ�
	}
	a[left] = key;
	return left;
}

void QuickSort(int* a, int begin, int end )
{
	if (begin >= end)
	{
		return;
	}


	int keyi = PartSort2(a, begin, end);

	QuickSort(a, begin, keyi - 1);		//��������������

	QuickSort(a, keyi + 1, end);
}
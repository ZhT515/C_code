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

	int key = a[left];							//������


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

int PartSort3(int* a, int left, int right) //ǰ��ָ��
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
	return per;			//����per,��ʱper���Ǳ��������key
}

void QuickSort(int* a, int begin, int end )
{
	if (begin >= end)
	{
		return;
	}

	if (end - begin > 20)		//С�����Ż���С��10ʱ���ٵݹ�
	{
		int keyi = PartSort3(a, begin, end);

		QuickSort(a, begin, keyi - 1);		//��������������

		QuickSort(a, keyi + 1, end);
	}
	else
	{
		InsertSort(a + begin, end - begin + 1); //ע������
	}
}


//���ŷǵݹ�
//��ջ����������Ҫ���������
void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, begin);				//�Ȱѳ�ʼ�ĸ���ȥ
	StackPush(&st, end);

	while (StackEmpty(&st))				//��Ϊ�վͼ���
	{
		int left, right;
		right = StackTop(&st);			//������ȡ��
		StackPop(&st);

		left = StackTop(&st);			//���������,ȡʱ������
		StackPop(&st);

		int keyi = PartSort3(a, left, right);

		if (keyi - 1 > left)		//�������䲻Ϊ��
		{
			StackPush(&st, left);					//key�����
			StackPush(&st, keyi - 1);
		}

		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);				//key���Ҳ�
			StackPush(&st, right);
		}
	}
}

void _Merge(int* a, int* tmp, int begin11,int end11, int begin22, int end22)			//�ϲ���������
{
	int begin1 = begin11, end1 = end11;
	int begin2 = begin22, end2 = end22;
	int i = begin11;					//tmp�±�

	while (begin1 <= end1 && begin2 <= end2)		//��һ�������������
	{
		if (a[begin1] > a[begin2])
			tmp[i++] = a[begin2++];				//�ϲ�
		else
			tmp[i++] = a[begin1++];
	}

	while (begin1 <= end1)				//��ʣ�µ�Ҳ��ӵ�����
		tmp[i++] = a[begin1++];

	while (begin2 <= end2)
		tmp[i++] = a[begin2++];

	for (int j = begin11; j <= end22; j++)			//������ԭ����,j���Ե���RIGHT
	{
		a[j] = tmp[j];
	}
}

void _MergeSrt(int* a,int* tmp, int left, int right)
{
	if (left >= right)				//��С��λ
		return;

	int mid = (left + right) >> 1;		//���м�
	_MergeSrt(a, tmp, left, mid);	//���Ұ������mid����ҲҪ��������-1
	_MergeSrt(a, tmp, mid + 1, right);

	//�鲢,��������ĺϲ�
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;

	_Merge(a, tmp, begin1, end1, begin2, end2);

}


// ʱ�临�Ӷȣ�O(N*logN)
// �ռ临�Ӷȣ�O(N)
void MergeSrt(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		exit(-1);
	}

	_MergeSrt(a, tmp, 0, n - 1);

	free(tmp);
}

//�鲢,�ǵݹ�
void MergeSrtNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		exit(-1);
	}

	int gap = 1;

	while (gap < n)		//��1��ʼ����n,���ϵغϲ����飬���й鲢���ݹ���°벿�֡�
	{
		for (int i = 0;i<n ;i += 2 * gap)			//�Ҳ�ͬ��С��
		{
			int begin1 = i, end1 = i + gap - 1;			//��һ�����䣬i- (i+gap-1)
			int begin2 = i + gap, end2 = i + 2 * gap - 1;			//�ڶ�������i + gap- i + 2 * gap - 1��i + gap+gap-1��
																	//���Եڶ���gapֱ�ӳ˶�����Ϊÿ2gap�ڶ�����Ҫ����
			if (begin2 >= n)			//1.��һ������Ͳ����ˣ�2.�ڶ������䲻���� 3.�ڶ������䲻���� �� 1��2�����һ����1��������Ȼ2�Ͳ����ڣ���ֻ���������1������������1�����ǲ���Ҫ���м�������ġ�
										//3.�������Ҫ���������ĵڶ�������й鲢��
			{
				break;					//��������Ҳ�������GAP����һ��ѭ��������ֱ����������
			}

			if (end2 >= n)
			{
				end2 = n - 1;			//����
			}

			_Merge(a, tmp, begin1, end1, begin2, end2);
		}

		gap *= 2;			//ÿ����֮ǰ��2����11һ�飬22һ�飬44һ�飬����ÿ���ڲ������ź����
	}

	free(tmp);
}

void CountSort(int* a, int n)			//��������
{
	int max = a[0], min = a[0];			//���ӳ��
	int i = 0;
	for (i = 0 ; i < n; i++)
	{
		if (max < a[i])
			max = a[i];
		if (min > a[i])
			min = a[i];
	}

	int range = max - min + 1;			//��Χ
	int* count = (int*)malloc(sizeof(int) * range);
	memset(count, 0, sizeof(int) * range);						//��ʼ��
	for (int k = 0; k < n; k++)
	{
		count[a[k] - min]++;			//���λ�ü�1
	}

	i = 0;
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)				//ͬһ��λ�õ�n��
		{
			a[i++] = j + min;
		}
	}

	free(count);
}
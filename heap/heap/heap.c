#include<stdio.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void  AdjustDown(int*a,int n,int parents)			//��С��
{
	int child = parents * 2 + 1;	//����

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])		//ȡ��С�ĺ���
		{
			++child;
		}

		if (a[child] < a[parents])								//ȡ��С����Ϊ����
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
	int child = parents * 2 + 1;	//����

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])		//ȡ��С�ĺ���
		{
			++child;
		}

		if (a[child] > a[parents])								//ȡ��С����Ϊ����
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

void HeapSort(int* a, int n)			/// �����򣬽����
{
	for (int i = (n - 2) / 2; i >= 0; i--)		//�����һ�����𽨶ѣ�(n - 2) / 2�����һ�����ڵ�
	{
		AdjustDown1(a, n, i);
	}

	int end = n - 1;
	while (end)							//�����ķ������Ȼ��ȥ�������½��ѡ�
	{
		Swap(&a[0], &a[end]);			//�����ķ������

		AdjustDown1(a, end, 0);			//���½��ѡ�

		end--;							
	}
}


int main()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(a) / sizeof(a[0]);
	AdjustDown(a, n, 0);

}
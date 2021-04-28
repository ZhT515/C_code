#include"heap.h"

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void  AdjustDown(int* a, int n, int parents)			//��da��
{
	int child = parents * 2 + 1;	//����

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])		//ȡ��da�ĺ���
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

void  AdjustUp(HP* hp, int child)
{

	int parents = (child - 1) / 2;
	while (child >0)							//parents����Ϊ��
	{
		if (hp->a[child] > hp->a[parents])			//���������ȱȽ�
		{
			Swap(&hp->a[child], &hp->a[parents]);
			child = parents;
			parents = (child - 1) / 2;
		}
		else										//���û�з�������˵���ź���
		{
			break;
		}
	}
}

void HeapInitial(HP* hp, HeapData* a, int n)
{
	assert(hp);

	hp->a = (HeapData*)malloc(sizeof(HeapData) * n);
	if (hp->a != NULL)										//��������
	{
		hp->size = 0;
		hp->capacity = n;
	}
	else
	{
		exit(-1);
	}

	memcpy(hp->a, a, sizeof(HeapData) * n);		//(void *destin, void *source, unsigned n)Ŀ������,Դ���ֽ���
	hp->size = n;

	for (int j = (hp->size - 2) / 2; j >= 0; j--)		//�����һ��������
	{
		AdjustDown(hp->a, hp->size, j);					//�𼶽���
	}
}

void HeapDestory(HP* hp)
{
	assert(hp);

	free(hp->a);
	hp->a == NULL;
	hp->capacity = hp->size = 0;
}

void HeadPrint(HP* hp)
{
	assert(hp);

	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}

void HeapPush(HP* hp, HeapData x)
{
	assert(hp);

	if (hp->size == hp->capacity)					//�ж��Ƿ���Ҫ����
	{
		HeapData* tmp = (HeapData*)realloc(hp->a, hp->capacity * 2 * sizeof(HeapData));
		if (tmp == NULL)
		{
			exit(-1);
		}
		hp->capacity *= 2;
		hp->a = tmp;
	}

	
	hp->a[hp->size] = x;
	hp->size++;

	AdjustUp(hp, hp->size - 1);				//�������ϰ����Ƚ�
}

void HeapPop(HP* hp)
{
	assert(hp);
	assert(hp->size > 0);

	Swap(&hp->a[0], &hp->a[hp->size - 1]);	//ͷβ����

	hp->size--;								//������һ

	AdjustDown(hp->a, hp->size, 0);			//��ͷ����
}

HeapData HeadTop(HP* hp)
{
	assert(hp);
	assert(hp->size > 0);

	return hp->a[0];
}

int	HeapSize(HP* hp)
{
	assert(hp);

	return hp->size;
}

bool HeapEmpty(HP* hp)
{
	assert(hp);

	return hp->size==0;
}
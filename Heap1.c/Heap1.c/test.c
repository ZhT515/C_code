#include"heap.h"

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void  AdjustDown(int* a, int n, int parents)			//建da堆
{
	int child = parents * 2 + 1;	//左孩子

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])		//取较da的孩子
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

void  AdjustUp(HP* hp, int child)
{

	int parents = (child - 1) / 2;
	while (child >0)							//parents不能为负
	{
		if (hp->a[child] > hp->a[parents])			//挨个和祖先比较
		{
			Swap(&hp->a[child], &hp->a[parents]);
			child = parents;
			parents = (child - 1) / 2;
		}
		else										//如果没有发生，则说明排好了
		{
			break;
		}
	}
}

void HeapInitial(HP* hp, HeapData* a, int n)
{
	assert(hp);

	hp->a = (HeapData*)malloc(sizeof(HeapData) * n);
	if (hp->a != NULL)										//建立数组
	{
		hp->size = 0;
		hp->capacity = n;
	}
	else
	{
		exit(-1);
	}

	memcpy(hp->a, a, sizeof(HeapData) * n);		//(void *destin, void *source, unsigned n)目标数组,源，字节数
	hp->size = n;

	for (int j = (hp->size - 2) / 2; j >= 0; j--)		//从最后一个根遍历
	{
		AdjustDown(hp->a, hp->size, j);					//逐级建立
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

	if (hp->size == hp->capacity)					//判断是否需要增容
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

	AdjustUp(hp, hp->size - 1);				//从下往上挨个比较
}

void HeapPop(HP* hp)
{
	assert(hp);
	assert(hp->size > 0);

	Swap(&hp->a[0], &hp->a[hp->size - 1]);	//头尾交换

	hp->size--;								//总数减一

	AdjustDown(hp->a, hp->size, 0);			//从头重排
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
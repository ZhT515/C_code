#include"Seqlist.h"

void SeqListInit(Seq* ps)		//初始化
{
	assert(ps);
	ps->a = NULL;
	ps->limit = 0;
	ps->size = 0;
}

void SeqListDestory(Seq* ps)  //销毁
{
	free(ps->a);
	ps->a = NULL;
	ps->limit = ps->size = 0;
}

void SeqListPrint(Seq* ps)		//打印
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

void SeqListMemorycheck(Seq* ps)	//扩容
{
	assert(ps);
	if (ps->size == ps->limit)		//扩容
	{ 
		int limit1 = ps->limit == 0 ? 4 : 2 * ps->limit;		//第一个表达式进行检验，如果为真，则返回表达式2的值；如果为假，则返回表达式3的值。
		SLDateType* newA = (SLDateType*)realloc(ps->a,limit1*sizeof(SLDateType));		//指针，个数 * 单位大小，当a为NULL时realloc和malloc的功能相同。
		if (newA == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
		else
		{
			ps->a = newA;
			ps->limit = limit1;
		}
	}

}

void SeqListPushBack(Seq* ps, SLDateType n)	//尾插
{
	assert(ps);

	SeqListMemorycheck(ps);

	ps->a[ps->size] = n;		
	ps->size++;
}

void SeqListPushFront(Seq* ps, SLDateType n)	//头插
{
	assert(ps);

	SeqListMemorycheck(ps);

	int i = ps->size - 1;		//n个数字，下标= n-1
	while (i >= 0)		//等于0时也要进
	{
		ps->a[i + 1] = ps->a[i];
		i--;
	}
	ps->a[0] = n;
	ps->size++;
}

void SeqListDelBack(Seq* ps)  //尾删
{
	assert(ps);
	ps->size--;
}

void SeqListDelFront(Seq* ps)  //头删
{
	assert(ps);

	int i = 0;
	for (i = 0; i < ps->size - 1; i++)		//等于0时也要进
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListInsert(Seq* ps, size_t pos, SLDateType n)  //顺序表在pos位置插入x
{
	assert(ps);

	SeqListMemorycheck(ps);

	int i = ps->size - 1;		//n个数字，下标= n-1
	while (i >= pos - 1)		//第pos个对应下标pos - 1
	{
		ps->a[i + 1] = ps->a[i];
		i--;
	}
	ps->a[pos - 1] = n;
	ps->size++;
}

void SeqListErase(Seq* ps, size_t pos)			// 顺序表删除pos位置的值
{
	assert(ps);

	for (int i = pos - 1; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

int SeqListFind(Seq* ps, SLDateType n)			// 顺序表查找
{
	assert(ps);

	for (int i = 0; i < ps->size - 1; i++)
	{
		if (ps->a[i] == n)
		{
			return i;
		}
	}
	return -1;
}
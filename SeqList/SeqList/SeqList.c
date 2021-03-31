#include"Seqlist.h"

void SeqListInit(Seq* ps)		//��ʼ��
{
	assert(ps);
	ps->a = NULL;
	ps->limit = 0;
	ps->size = 0;
}

void SeqListDestory(Seq* ps)  //����
{
	free(ps->a);
	ps->a = NULL;
	ps->limit = ps->size = 0;
}

void SeqListPrint(Seq* ps)		//��ӡ
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

void SeqListMemorycheck(Seq* ps)	//����
{
	assert(ps);
	if (ps->size == ps->limit)		//����
	{ 
		int limit1 = ps->limit == 0 ? 4 : 2 * ps->limit;		//��һ�����ʽ���м��飬���Ϊ�棬�򷵻ر��ʽ2��ֵ�����Ϊ�٣��򷵻ر��ʽ3��ֵ��
		SLDateType* newA = (SLDateType*)realloc(ps->a,limit1*sizeof(SLDateType));		//ָ�룬���� * ��λ��С����aΪNULLʱrealloc��malloc�Ĺ�����ͬ��
		if (newA == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
		else
		{
			ps->a = newA;
			ps->limit = limit1;
		}
	}

}

void SeqListPushBack(Seq* ps, SLDateType n)	//β��
{
	assert(ps);

	SeqListMemorycheck(ps);

	ps->a[ps->size] = n;		
	ps->size++;
}

void SeqListPushFront(Seq* ps, SLDateType n)	//ͷ��
{
	assert(ps);

	SeqListMemorycheck(ps);

	int i = ps->size - 1;		//n�����֣��±�= n-1
	while (i >= 0)		//����0ʱҲҪ��
	{
		ps->a[i + 1] = ps->a[i];
		i--;
	}
	ps->a[0] = n;
	ps->size++;
}

void SeqListDelBack(Seq* ps)  //βɾ
{
	assert(ps);
	ps->size--;
}

void SeqListDelFront(Seq* ps)  //ͷɾ
{
	assert(ps);

	int i = 0;
	for (i = 0; i < ps->size - 1; i++)		//����0ʱҲҪ��
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListInsert(Seq* ps, size_t pos, SLDateType n)  //˳�����posλ�ò���x
{
	assert(ps);

	SeqListMemorycheck(ps);

	int i = ps->size - 1;		//n�����֣��±�= n-1
	while (i >= pos - 1)		//��pos����Ӧ�±�pos - 1
	{
		ps->a[i + 1] = ps->a[i];
		i--;
	}
	ps->a[pos - 1] = n;
	ps->size++;
}

void SeqListErase(Seq* ps, size_t pos)			// ˳���ɾ��posλ�õ�ֵ
{
	assert(ps);

	for (int i = pos - 1; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

int SeqListFind(Seq* ps, SLDateType n)			// ˳������
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
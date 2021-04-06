#include"Linkedlist.h"

void SListprint(SL* plist)				//��ӡ
{
	SL* cur = plist;
	while (cur != NULL)		//������cur->next�����ӡ�������һ��
	{
		printf("%d->", cur->x);
		cur = cur->next;
	}
	printf("NULL\n");
}

SL* BuySLTNode(SLTDataType x2)		//���ٿռ䣬���ص�ַ
{
	SL* ret = (SL*)malloc(sizeof(SL));
	if (ret != NULL)
	{
		ret->x = x2;
		ret->next = NULL;		//ָ���
	}

	return ret;				//���ﷵ�ص���ret����ڵ�ĵ�ַ����������
}

void SListPushBack(SL** pplist, int x)	//β�壬�գ��ǿգ�����ָ�룬ȡ�������*plistָ��ĵ�ַ,������ж�ָ�뱾���Ƿ�Ϸ�
{
	SL* newnode = BuySLTNode(x);

	if (*pplist == NULL)		//��
	{
		*pplist = newnode;
	}
	else
	{
		SL* cur = *pplist;
		while (cur->next != NULL)		//��β
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}
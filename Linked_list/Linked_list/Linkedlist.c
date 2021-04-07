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

void SListPushBack(SL** pplist, SLTDataType x)	//β�壬�գ��ǿգ�����ָ�룬ȡ�������*plistָ��ĵ�ַ,������ж�ָ�뱾���Ƿ�Ϸ�
{
	SL* newnode = BuySLTNode(x);

	if (*pplist == NULL)		//�գ�����Ҫ�ж�plist�����ǲ���Ϊ�գ���ʼʱ��ָ��գ������Ծ�Ҫ������ָ��������ж϶���ָ��Ŀռ��Ƿ�Ϊ�գ�����ǰ�������Ҫȡ��ַ
	{
		*pplist = newnode;		//*pplist == plist
	}
	else
	{
		SL* cur = *pplist;			//������ͷ�����Ի��Ǵ�plist�ĵ�ַ��Ҳ����ͷ�ڵ�ĵ�ַ
		while (cur->next != NULL)		//��β
		{
			cur = cur->next;
		}
		cur->next = newnode;		
	}
}

void SListPushFront(SL** pplist, SLTDataType x)		//ͷ��
{
	SL* newnode = BuySLTNode(x);
	newnode->next = *pplist;			//����һ���ڵ�ĵ�ַ
	*pplist = newnode;
}

void SListPopBack(SL** pplist)			//βɾ,0,1,N���
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)		//1���ڵ㲻������һ���Ĵ�������Ҫ�����ó�����
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SL* cur = *pplist;
		SL* cur2 = NULL;
		while (cur->next != NULL)		//ֻ��Ҫ�����һ���ڵ㣬����Ҫ����
		{
			cur2 = cur;				//���浹���ڶ����ڵ�
			cur = cur->next;
		}
		free(cur);
		cur = NULL;

		cur2->next = NULL;		//����ֻ��һ���ڵ�����޽ڵ�����
	}
}

void SListPopFront(SL** pplist)		//ͷɾ
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SL* cur = (*pplist)->next;
		free(*pplist);
		*pplist = cur;
	}
}

SL* SListFind(SL* plist, SLTDataType x)		// ���������
{
	SL* cur = plist;
	while (cur->next != NULL)		//ֻ��Ҫ�����һ���ڵ㣬����Ҫ����
	{
		if (cur->x == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SL* pos, SLTDataType x)		// ��������posλ��֮�����x
{
	SL* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(SL* pos)				// ������ɾ��posλ��֮���ֵ
{
	SL* cur = pos->next;
	pos->next = cur->next;
	free(cur);
	cur = NULL;
}

void SListDestory(SL** pplist)				// �����������
{
	SL* cur = *pplist;
	SL* cur2 = NULL;
	while (cur != NULL)		//��β
	{
		cur2 = cur;
		cur = cur->next;
		free(cur2);
		cur2 = NULL;
	}
	*pplist = NULL;
}
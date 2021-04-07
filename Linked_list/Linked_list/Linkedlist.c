#include"Linkedlist.h"

void SListprint(SL* plist)				//打印
{
	SL* cur = plist;
	while (cur != NULL)		//不可以cur->next，会打印不出最后一个
	{
		printf("%d->", cur->x);
		cur = cur->next;
	}
	printf("NULL\n");
}

SL* BuySLTNode(SLTDataType x2)		//开辟空间，返回地址
{
	SL* ret = (SL*)malloc(sizeof(SL));
	if (ret != NULL)
	{
		ret->x = x2;
		ret->next = NULL;		//指向空
	}

	return ret;				//这里返回的是ret这个节点的地址，而非其他
}

void SListPushBack(SL** pplist, SLTDataType x)	//尾插，空，非空，二级指针，取得是这个*plist指针的地址,这个以判断指针本身是否合法
{
	SL* newnode = BuySLTNode(x);

	if (*pplist == NULL)		//空，这里要判断plist本身是不是为空（初始时会指向空），所以就要传二级指针过来，判断二级指向的空间是否为空，所以前面调用需要取地址
	{
		*pplist = newnode;		//*pplist == plist
	}
	else
	{
		SL* cur = *pplist;			//这里是头，所以还是传plist的地址，也就是头节点的地址
		while (cur->next != NULL)		//找尾
		{
			cur = cur->next;
		}
		cur->next = newnode;		
	}
}

void SListPushFront(SL** pplist, SLTDataType x)		//头插
{
	SL* newnode = BuySLTNode(x);
	newnode->next = *pplist;			//传第一个节点的地址
	*pplist = newnode;
}

void SListPopBack(SL** pplist)			//尾删,0,1,N情况
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)		//1个节点不考虑上一个的处理，所以要单独拿出处理。
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SL* cur = *pplist;
		SL* cur2 = NULL;
		while (cur->next != NULL)		//只需要到最后一个节点，不需要向下
		{
			cur2 = cur;				//保存倒数第二个节点
			cur = cur->next;
		}
		free(cur);
		cur = NULL;

		cur2->next = NULL;		//考虑只有一个节点或者无节点的情况
	}
}

void SListPopFront(SL** pplist)		//头删
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

SL* SListFind(SL* plist, SLTDataType x)		// 单链表查找
{
	SL* cur = plist;
	while (cur->next != NULL)		//只需要到最后一个节点，不需要向下
	{
		if (cur->x == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SL* pos, SLTDataType x)		// 单链表在pos位置之后插入x
{
	SL* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(SL* pos)				// 单链表删除pos位置之后的值
{
	SL* cur = pos->next;
	pos->next = cur->next;
	free(cur);
	cur = NULL;
}

void SListDestory(SL** pplist)				// 单链表的销毁
{
	SL* cur = *pplist;
	SL* cur2 = NULL;
	while (cur != NULL)		//找尾
	{
		cur2 = cur;
		cur = cur->next;
		free(cur2);
		cur2 = NULL;
	}
	*pplist = NULL;
}
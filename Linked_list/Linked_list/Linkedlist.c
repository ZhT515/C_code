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

void SListPushBack(SL** pplist, int x)	//尾插，空，非空，二级指针，取得是这个*plist指针的地址,这个以判断指针本身是否合法
{
	SL* newnode = BuySLTNode(x);

	if (*pplist == NULL)		//空
	{
		*pplist = newnode;
	}
	else
	{
		SL* cur = *pplist;
		while (cur->next != NULL)		//找尾
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}
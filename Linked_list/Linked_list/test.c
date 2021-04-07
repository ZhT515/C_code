#include"Linkedlist.h"

void Linkedlist()
{
	SL* plist = NULL;	//创建

	SListPushBack(&plist, 1);		//二级指针，所以要取地址
	SListDestory(&plist);
	SListprint(plist);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	

	SListprint(plist);

	SListPushFront(&plist, 0);
	//SListPopBack(&plist);

	SListprint(plist);
	SL* a = SListFind(plist, 2);
	printf("%d\n", a->x);
	SListInsertAfter(a, 7);
	SListprint(plist);
	SListEraseAfter(a);
	SListprint(plist);
	SListDestory(&plist);
	SListprint(plist);
}

int main()
{
	Linkedlist();

	return 0;
}
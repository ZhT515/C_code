#include"Linkedlist.h"

void Linkedlist()
{
	SL* plist = NULL;	//����

	SListPushBack(&plist, 1);		//����ָ�룬����Ҫȡ��ַ
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
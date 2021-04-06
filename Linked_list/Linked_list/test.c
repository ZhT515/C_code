#include"Linkedlist.h"

void Linkedlist()
{
	SL* plist = NULL;	//创建

	SListPushBack(&plist, 1);		//二级指针，所以要取地址
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListprint(plist);
}

int main()
{
	Linkedlist();

	return 0;
}
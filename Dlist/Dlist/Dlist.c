#include"DList.h"

void TEST1()
{
	DLN* head = ListCreate();

	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPopFront(head);
	//ListPopBack(head);
	DLPrint(head);

	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushFront(head, 0);
	DLN* a = ListFind(head, 1);
	/*if (a)
	{
		printf("%d", a->val);
	}*/
	//ListInsert(a, 9);
	ListErase(a);
	ListPopBack(head);

	DLPrint(head);

	ListDestor(head);

}

int main()
{
	TEST1();
}
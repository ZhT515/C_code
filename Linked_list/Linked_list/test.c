#include"Linkedlist.h"

void Linkedlist()
{
	SL* plist = NULL;	//����

	SListPushBack(&plist, 1);		//����ָ�룬����Ҫȡ��ַ
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
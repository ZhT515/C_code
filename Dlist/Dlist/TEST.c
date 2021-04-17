#include"DList.h"

DLN* BuySListNode()			//创建新节点
{
	DLN* node = (DLN*)malloc(sizeof(DLN));
	node->next = NULL;
	node->prev = NULL;

	return node;
}

DLN* ListCreate()			//创建HEAD,自带环，方便后续操作
{
	DLN* head = BuySListNode();

	head->next = head;
	head->prev = head;

	return head;
}

void DLPrint(DLN* head)
{
	DLN* cur = head->next;
	while (cur != head)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}

	printf("\n");
}

void ListPushBack(DLN* head, DLData x)
{
	assert(head);

	DLN* news = BuySListNode();
	DLN* tail = head->prev;
	news->val = x;

	news->next = head;
	news->prev = tail;
	tail->next = news;
	head->prev = news;
}

void ListPushFront(DLN* head, DLData x)
{
	assert(head);

	DLN* news = BuySListNode();
	DLN* front = head->next;
	news->val = x;

	news->prev = head;
	news->next = front;
	head->next = news;
	front->prev = news;
}

void ListPopBack(DLN* head)  //尾删
{
	assert(head);

	DLN* cur = head->prev;
	DLN* cur2 = cur->prev;

	cur2->next = head;
	head->prev = cur2;

	free(cur);
	cur = NULL;
}

void ListPopFront(DLN* head) //头删
{
	assert(head);

	DLN* cur = head->next;
	DLN* cur2 = cur->next;

	free(cur);
	cur = NULL;

	cur2->prev = head;
	head->next = cur2;
}

DLN* ListFind(DLN* head, DLData x)
{
	assert(head);

	DLN* cur = head->next;
	while (cur != head)
	{
		if(cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(DLN* pos, DLData x) //POS位插
{
	assert(pos);

	DLN* prev = pos->prev;
	DLN* news = BuySListNode();
	news->val = x;

	prev->next = news;
	news->next = pos;
	news->prev = prev;
	pos->prev = news;
}

void ListErase(DLN* pos)  //POS位删
{
	assert(pos);

	DLN* prev = pos->prev;
	DLN* next = pos->next;

	free(pos);
	pos = NULL;

	prev->next = next;
	next->prev = prev;
}

void ListDestor(DLN* head)
{
	assert(head);

	DLN* cur = head->next;
	while (cur != head)
	{
		DLN* cur1 = cur;
		cur = cur->next;

		free(cur1);
		cur1 = NULL;
		
	}
}
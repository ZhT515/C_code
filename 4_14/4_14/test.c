#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
	struct ListNode* random;
};

struct ListNode* copyRandomList(struct ListNode* head)
{
	struct ListNode* cur = head;
	//1.在每个节点后边复制一个节点
	while (cur)
	{
		struct ListNode* bol = cur->next;
		struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
		new->val = cur->val;
		cur->next = new;
		new->next = bol;
		cur = bol;
	}

	//2.复制random
	struct ListNode* cur2 = head;
	while (cur2 && cur2->next != NULL)
	{
		if (cur2->random == NULL)
			cur2->next->random = NULL;
		else
			cur2->next->random = cur2->random->next;
		cur2 = cur2->next->next;	//直接找下下一个
	}

	//3.拆解
	struct ListNode* cur3 = head;
	struct ListNode* ret = NULL;
	struct ListNode* bol2 = NULL;
	while (cur3 && cur3->next != NULL)
	{
		if (ret == NULL)				//尾插
		{
			bol2 = cur3->next;
			ret = cur3->next;
		}
			
		else
		{
			bol2->next = cur3->next;
			bol2 = bol2->next;
		}
			
		cur3->next = cur3->next->next;
		cur3 = cur3->next;
	}
	return ret;
}

void print(struct ListNode* head)
{
	while (head)
	{
		printf("%d->", head->val);
		head = head->next;
	}
	printf("NULL");
}

int  main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;

	n1->random = NULL;
	n2->random = n6;
	n3->random = n4;
	n4->random = n2;
	n5->random = n3;
	n6->random = n1;

	n1->val = 1;
	n2->val = 2;
	n3->val = 31;
	n4->val = 41;
	n5->val = 5;
	n6->val = 6;

	print(copyRandomList(n1));

}
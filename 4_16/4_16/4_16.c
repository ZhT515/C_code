#include<stdio.h>
#include<stdlib.h>

struct ListNode 
{
	int val;
	struct ListNode* next;
};


struct ListNode* insertionSortList(struct ListNode* head)		//重新建一个数组
{
	if (head == NULL && head->next == NULL)
		return head;

	struct ListNode* cur = head;
	struct ListNode* news = (struct ListNode*)malloc(sizeof(struct ListNode));
	news->next = NULL;

	while (cur)
	{
		struct ListNode* cur3 = (struct ListNode*)malloc(sizeof(struct ListNode));	//创建中转站
		if (news->next == NULL)
		{
			cur3->val = cur->val;
			news->next = cur3;
			cur3->next = NULL;
		}

		else
		{
			struct ListNode* cur2 = news;
			struct ListNode* last = NULL;

			while (cur2->next != NULL)
			{
				last = cur2;		
				cur2 = cur2->next;		//news 第一个为哨兵，所以直接取下一个

				if (cur2->val >= cur->val)		//比前面的大，头插入
				{
					cur3->val = cur->val;
					cur3->next = last->next;
					last->next = cur3;
					break;
				}

				if (cur2->next == NULL)			//最后一个尾插，
				{
					cur3->val = cur->val;
					cur3->next = NULL;
					cur2->next = cur3;
					cur2 = cur2->next;
				}
			}
		}

		cur = cur->next;
	}
	return news->next;
}

struct ListNode* insertionSortList2(struct ListNode* head)		//从头开始遍历每个节点, 将每个节点在排好序链表中找到正确的位置, 然后插入, 直至原链表遍历完成
{
	if (head == NULL && head->next == NULL)
		return head;

	struct ListNode* cur1 = head->next;		//指向实时判断位置，第一次判断头和第二个，所以指向第二个
	struct ListNode* last = head;			//指向头
	struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
	cur->val = 0;
	cur->next = head;

	while (cur1)
	{
		if (cur1->val < last->val)			//确保last之前的是排好的，小于才开始排
		{
			struct ListNode* ptr = cur;
			while (ptr->next->val <= cur1->val)		//排除掉比它小的，找位置，ptr->next->val是从头开始，为了防止第二个大于第一个的情况，所以前面放一个空位置。
			{
				ptr = ptr->next;
			}
			if (ptr->next->val > cur1->val)			//对应位插入
			{
				last->next = cur1->next;
				cur1->next = ptr->next;
				ptr->next = cur1;
			}
		}
		else										//不小于，last后移，cur1后移，这里不能last = cur1;cur1 = cur->next;因为此时cur1不一定还在原位，所以指向last下一个才可以
		{
			last = last->next;
		}
		cur1 = last->next;							//last下一个后指向last下一个才可以
	}

	return cur->next;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->next = n2;
	n2->next = NULL;

	n1->val = 3;
	n2->val = 2;

	struct ListNode* n = insertionSortList2(n1);
}
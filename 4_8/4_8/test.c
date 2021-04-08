#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)		//删除链表中等于给定值 val 的所有节点
{
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	while (cur)
	{
		if (cur->val == val)
		{
			struct ListNode* Next = cur->next;
			if (prev == NULL)					//cur没有前一个的情况
			{
				free(cur);
				head = Next;
				cur = Next;
			}
			else
			{
				prev->next = Next;
				free(cur);
				cur = Next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

struct ListNode* reverseList1(struct ListNode* head)			//反转一个单链表。两个方案：1.三个指针2.新链表头插。	
{
	struct ListNode* n1 = NULL;
	struct ListNode* n2 = head;
	struct ListNode* n3 = NULL;
	while (n2)
	{
		n3 = n2->next;
		n2->next = n1;

		n1 = n2;
		n2 = n3;
	}
	return n1;
}

struct ListNode* reverseList2(struct ListNode* head) {
	struct ListNode* new = NULL;
	struct ListNode* cur = head;
	struct ListNode* next = NULL;
	while (cur)
	{
		next = cur->next;		//指向新的
		cur->next = new;
		new = cur;

		cur = next;
	}
	return new;
}

struct ListNode* middleNode(struct ListNode* head)				//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点
{
	struct ListNode* cur = head;			//快慢指针,妙啊
	struct ListNode* fast = head;

	while (fast && fast->next)		//奇数个就fast->next = null;偶数fast=null；所以两个与一下
	{
		cur = cur->next;
		fast = fast->next->next;			//两次解引用
	}

	return cur;
}

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)		//输入一个链表，输出该链表中倒数第k个结点。
{
	struct ListNode* cur = pListHead;
	struct ListNode* fast = cur;

	while (k--)
	{
		if (fast != NULL)
			fast = fast->next;
		else
			return NULL;
	}
	while (fast)
	{
		cur = cur->next;
		fast = fast->next;
	}

	return cur;
}

int main()
{
	struct ListNode* plist = NULL;
	FindKthToTail(plist, 2);
}
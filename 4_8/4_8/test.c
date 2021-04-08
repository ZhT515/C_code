#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)		//ɾ�������е��ڸ���ֵ val �����нڵ�
{
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	while (cur)
	{
		if (cur->val == val)
		{
			struct ListNode* Next = cur->next;
			if (prev == NULL)					//curû��ǰһ�������
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

struct ListNode* reverseList1(struct ListNode* head)			//��תһ������������������1.����ָ��2.������ͷ�塣	
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
		next = cur->next;		//ָ���µ�
		cur->next = new;
		new = cur;

		cur = next;
	}
	return new;
}

struct ListNode* middleNode(struct ListNode* head)				//����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м���
{
	struct ListNode* cur = head;			//����ָ��,�
	struct ListNode* fast = head;

	while (fast && fast->next)		//��������fast->next = null;ż��fast=null������������һ��
	{
		cur = cur->next;
		fast = fast->next->next;			//���ν�����
	}

	return cur;
}

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)		//����һ����������������е�����k����㡣
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
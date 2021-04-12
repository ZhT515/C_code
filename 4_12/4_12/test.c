#include<stdio.h>
#include<stdbool.h>

struct ListNode 
{
	int val;
	struct ListNode* next;
};

bool hasCycle(struct ListNode* head) 
{
	if (head == NULL || head->next == NULL)
		return false;
	struct ListNode* fast = head->next;		//避免第一个就相同
	struct ListNode* slow = head;
	while (fast != slow)		//不使用while(fast)是因为fast = fast->next->next;会越界
	{
		if (fast == NULL || fast->next == NULL)		//不能fast == slow,因为while已经判断过了
			return false;
		fast = fast->next->next;
		slow = slow->next;
	}
	return true;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->next = n2;
	n2->next = NULL;

	n1->val = 1;
	n2->val = 2;

	if (hasCycle(n1))
		printf("1");
	else
		printf("2");
}
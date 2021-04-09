#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
	
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{ 
	struct ListNode* cur = l1;
	struct ListNode* cur2 = l2;

	if (cur == NULL)
		return cur2;
	if (cur2 == NULL)
		return cur;
	if (cur->val < cur2->val)
	{
		cur->next = mergeTwoLists(cur->next, cur2);
		return cur;
	}
	else 
	{
		cur2->next = mergeTwoLists(l1, cur2->next);
		return cur2;
	}
}

int main()
{

}
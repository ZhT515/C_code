#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

struct ListNode 
{
	int val;
	struct ListNode* next;
};

void Print(struct ListNode* pHead)
{
	struct ListNode* cur = pHead;

	while (cur)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

struct ListNode* partition(struct ListNode* pHead, int x)		//以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
{
	struct ListNode* cur = pHead;
	struct ListNode* Big = NULL, * Small = NULL, * pBig = NULL, * pSmall = NULL;
	Big = (struct ListNode*)malloc(sizeof(struct ListNode));			//开辟哨兵位置
	Small = (struct ListNode*)malloc(sizeof(struct ListNode));
	pBig = Big;															//实时的位置
	pSmall = Small;
	while (cur)
	{
		if (cur->val < x)
		{
			pSmall->next = cur;
			pSmall = pSmall->next;			//指向挪过来的cur
		}
		else if(cur->val > x)
		{
			pBig->next = cur;
			pBig = pBig->next;
		}
		cur = cur->next;
	}
	pBig->next = NULL;						//连接两个链表
	pSmall->next = Big->next;
	
	pHead = Small->next;
	return pHead;

}


bool chkPalindrome(struct ListNode* A)		//链表的回文结构:快慢指针确定中点，然后逆置后半部分，然后对比
{
	struct ListNode* fast = A;
	struct ListNode* slow = A;

	if(A == NULL)
		return false;

	while (fast && fast->next)		//找中点
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	struct ListNode* rev = slow;
	struct ListNode* mid = NULL;
	struct ListNode* news = NULL;
	while (rev)						//逆置
	{
		mid = rev->next;
		rev->next = news;
		news = rev;
		rev = mid;
	}

	struct ListNode* cpd = A;
	while (news)					//对比
	{
		if (cpd->val != news->val)
			return false;
		news = news->next;
		cpd = cpd->next;
	}
	return true;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n8 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n9 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n10 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n11 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n12 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n13 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n14 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n15 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n16 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n9;
	n9->next = n10;
	n10->next = n11;
	n11->next = n12;
	n12->next = n13;
	n13->next = n14;
	n14->next = n15;
	n15->next = n16;
	n16->next = NULL;

	n1->val = 421;
	n2->val = 305;
	n3->val = 13;
	n4->val = 425;
	n5->val = 222;
	n6->val = 609;
	n7->val = 100;
	n8->val = 579;
	n9->val = 579;
	n10->val = 100;
	n11->val = 609;
	n12->val = 222;
	n13->val = 425;
	n14->val = 13;
	n15->val = 305;
	n16->val = 421;



	if (chkPalindrome(n1))
		printf("1");
	else
		printf("2");

	//Print(partition(n1, 3));

}
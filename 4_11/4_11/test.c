#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)	//���㳤�ȣ��ó���ȥ�߲�ֵ��Ȼ���жϵ�һ�ε�ַ��ͬ���ص�ַ
{
	struct ListNode* A = headA, * B = headB;

	int a = 0, b = 0;				//�㳤��
	while (A->next)
	{
		A = A->next;
		a++;
	}
	while (B->next)
	{
		B = B->next;
		b++;
	}

	if (A->val != B->val)		//�ж��Ƿ��ཻ�����������ĩβ�ڵ㶼����ͬ����϶����ཻ��
	{
		return NULL;
	}

	struct ListNode* Long = headA;			//�ҳ���
	struct ListNode* Short = headB;			//Ĭ��A > B
	if (a < b)								//���෴���Ͱ����ݷ�����
	{
		Long = headB;
		Short = headA;
	}

	int c = abs(a - b);					//�����߲�ֵ
	while (c--)
	{
		Long = Long->next;
	}

	while (Long != Short)			//ʡȥһ��if
	{
		Long = Long->next;
		Short = Short->next;
	}
	return Long;				//һ��Ҫ�з���
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
	n6->next = n13;
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


	struct ListNode* a = getIntersectionNode(n1, n7);
	printf("%d", a->val);

}
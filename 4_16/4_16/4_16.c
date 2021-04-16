#include<stdio.h>
#include<stdlib.h>

struct ListNode 
{
	int val;
	struct ListNode* next;
};


struct ListNode* insertionSortList(struct ListNode* head)		//���½�һ������
{
	if (head == NULL && head->next == NULL)
		return head;

	struct ListNode* cur = head;
	struct ListNode* news = (struct ListNode*)malloc(sizeof(struct ListNode));
	news->next = NULL;

	while (cur)
	{
		struct ListNode* cur3 = (struct ListNode*)malloc(sizeof(struct ListNode));	//������תվ
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
				cur2 = cur2->next;		//news ��һ��Ϊ�ڱ�������ֱ��ȡ��һ��

				if (cur2->val >= cur->val)		//��ǰ��Ĵ�ͷ����
				{
					cur3->val = cur->val;
					cur3->next = last->next;
					last->next = cur3;
					break;
				}

				if (cur2->next == NULL)			//���һ��β�壬
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

struct ListNode* insertionSortList2(struct ListNode* head)		//��ͷ��ʼ����ÿ���ڵ�, ��ÿ���ڵ����ź����������ҵ���ȷ��λ��, Ȼ�����, ֱ��ԭ����������
{
	if (head == NULL && head->next == NULL)
		return head;

	struct ListNode* cur1 = head->next;		//ָ��ʵʱ�ж�λ�ã���һ���ж�ͷ�͵ڶ���������ָ��ڶ���
	struct ListNode* last = head;			//ָ��ͷ
	struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
	cur->val = 0;
	cur->next = head;

	while (cur1)
	{
		if (cur1->val < last->val)			//ȷ��last֮ǰ�����źõģ�С�ڲſ�ʼ��
		{
			struct ListNode* ptr = cur;
			while (ptr->next->val <= cur1->val)		//�ų�������С�ģ���λ�ã�ptr->next->val�Ǵ�ͷ��ʼ��Ϊ�˷�ֹ�ڶ������ڵ�һ�������������ǰ���һ����λ�á�
			{
				ptr = ptr->next;
			}
			if (ptr->next->val > cur1->val)			//��Ӧλ����
			{
				last->next = cur1->next;
				cur1->next = ptr->next;
				ptr->next = cur1;
			}
		}
		else										//��С�ڣ�last���ƣ�cur1���ƣ����ﲻ��last = cur1;cur1 = cur->next;��Ϊ��ʱcur1��һ������ԭλ������ָ��last��һ���ſ���
		{
			last = last->next;
		}
		cur1 = last->next;							//last��һ����ָ��last��һ���ſ���
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
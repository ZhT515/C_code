#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* deleteDuplication(struct ListNode* head)		//������ָ�룬����ͬ�����䣬Ȼ��������䣬Ȼ�������
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* n0 = NULL;
	struct ListNode* n1 = head;
	struct ListNode* n2 = head->next;
	struct ListNode* next = (struct ListNode*)malloc(sizeof(struct ListNode*));

	while (n2)		//head->nextΪ��ʱ��������ͬ������ֻ��Ҫ�жϵ����һ������
	{
		if (n1->val != n2->val)
		{
			n0 = n1;		//���½ڵ㣬ǰ ���� ��
			n1 = n2;
			n2 = n2->next;
		}
		else
		{
			while (n2 && n2->val == n1->val)		//ȷ������������ͬ�����䣬��ȥ������������
			{
				n2 = n2->next;
			}
			
			if (n0)					//��ǰ��n2��n1����ͬ������֮ǰ�ĺ���-------��Ӧif��n0 = n1;
				n0->next = n2;		
			else
				head = n2;

			while (n1 != n2)		//���������,���Բ�Ҫ
			{
				next = n1->next;
				free(n1);
				n1 = next;
			}

			n1 = n2;			//���£��ָ� n0-��n1-��n2 �����Ĵ���Ҫ��ʱ����-------��Ӧif��n1 = n2;

			if (n2)					//��������Ѱ�ң���Ϊ����n2=0�������������Ҫ�ж�-------��Ӧif��n2 = n2->next;
				n2 = n2->next;
		}
	}

	return head;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->next = n2;
	n2->next = NULL;

	n1->val = 1;
	n2->val = 2;
}
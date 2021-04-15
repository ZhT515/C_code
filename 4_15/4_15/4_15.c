#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* deleteDuplication(struct ListNode* head)		//用三个指针，找相同的区间，然后清空区间，然后遍历完
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* n0 = NULL;
	struct ListNode* n1 = head;
	struct ListNode* n2 = head->next;
	struct ListNode* next = (struct ListNode*)malloc(sizeof(struct ListNode*));

	while (n2)		//head->next为空时不可能相同，所以只需要判断到最后一个即可
	{
		if (n1->val != n2->val)
		{
			n0 = n1;		//更新节点，前 现在 后
			n1 = n2;
			n2 = n2->next;
		}
		else
		{
			while (n2 && n2->val == n1->val)		//确定区间跳过相同的区间，再去进行上述内容
			{
				n2 = n2->next;
			}
			
			if (n0)					//当前的n2与n1不相同，续在之前的后面-------对应if中n0 = n1;
				n0->next = n2;		
			else
				head = n2;

			while (n1 != n2)		//清除区间内,可以不要
			{
				next = n1->next;
				free(n1);
				n1 = next;
			}

			n1 = n2;			//更新，恢复 n0-》n1-》n2 三个的次序；要及时更新-------对应if中n1 = n2;

			if (n2)					//继续向下寻找，因为存在n2=0的情况，所以需要判断-------对应if中n2 = n2->next;
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
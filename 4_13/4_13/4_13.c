#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
    
};

/*
����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
�ܳ�Ϊa+b+c,aΪ���ڵ�ǰ��bΪ����ָ��������λ�ã�cΪ��һ�ε��ڵ�ľ���
����ʱslow= a + b, fast = a + b + n*(b+c)(nȦ)
���� fast = 2 * slow
������  a = (n-1)b + n*c = (n-1)(b+c) + c
�ɴ˿ɵ� a = c��
��������������������ָ��ָ��ͷ����SLOWһ�𶯣�����ʱ���ǽڵ㡣����Ϊ��ʱslow����c�͵��ڵ㣬ͷ����a��
*/

struct ListNode* detectCycle(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* ptr = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            ptr = head;
            while (ptr != slow)     //���½���ѭ��
            {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return NULL;
}


int main()
{

}
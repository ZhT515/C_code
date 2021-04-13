#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
    
};

/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
总长为a+b+c,a为进节点前，b为快慢指针相遇的位置，c为下一次到节点的距离
相遇时slow= a + b, fast = a + b + n*(b+c)(n圈)
又有 fast = 2 * slow
联立得  a = (n-1)b + n*c = (n-1)(b+c) + c
由此可得 a = c；
所以在他们相遇后设置指针指向头，和SLOW一起动，相遇时就是节点。（因为此时slow还有c就到节点，头还有a）
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
            while (ptr != slow)     //重新建立循环
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
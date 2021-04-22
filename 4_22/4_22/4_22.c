#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QueueData;

struct QueueNode					//��ʽ�ṹ����ʾ���� (��������)
{
	struct QueueNode* next;
	QueueData val;
};

typedef struct QueueNode QueueN;

struct Queue						// ���еĽṹ(ͷβָ�룩
{
	struct QueueNode* front;		//Ҫָ��ڵ㣬���Խṹ��struct QueueNode*
	struct QueueNode* back;
};

typedef struct Queue Queue;

QueueN* BuyQueueNode(QueueData x)		//�����ڵ�
{
	QueueN* ret = (Queue*)malloc(sizeof(QueueN));
	if (ret == NULL)
	{
		exit(-1);
	}

	ret->val = x;
	ret->next = NULL;
	return ret;
}

void QueueInit(Queue* q)		// ��ʼ������
{
	assert(q);

	q->back = NULL;
	q->front = NULL;
}

void QueueDestroy(Queue* q)				// ���ٶ��� 
{
	assert(q);

	Queue* cur = q;
	while (cur->front)					//��Ҫ�ж�cur->front��cur��Զ����Ϊ��
	{
		Queue* Next = cur->front->next;
		free(cur->front);
		cur->front = Next;
	}
	q->back = q->front = NULL;
}

void QueuePush(Queue* q, QueueData data)		// ��β����� 
{
	assert(q);

	QueueN* cur = BuyQueueNode(data);



	if (q->front == NULL)
	{
		q->back = q->front = cur;
	}
	else									//��β�������׳�
	{
		q->back->next = cur;
		q->back = cur;
	}
}

void QueuePop(Queue* q)					// ��ͷ������ 
{
	assert(q);

	if (q->front == NULL)
	{
		return;
	}
	QueueN* Next = q->front->next;
	free(q->front);
	q->front = Next;
}

QueueData QueueFront(Queue* q)				// ��ȡ����ͷ��Ԫ��
{
	assert(q);

	if (q->front == NULL)				//�����жϣ�Ϊ��ʱ�����ؿ�
		return;
	return q->front->val;
}

QueueData QueueBack(Queue* q)				// ��ȡ���ж�βԪ�� 
{
	assert(q);

	if (q->back == NULL)
		return;

	return q->back->val;
}

int QueueSize(Queue* q)					// ��ȡ��������ЧԪ�ظ���
{
	assert(q);

	int count = 0;
	QueueN* cur = q->front;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return count;
}

bool QueueEmpty(Queue* q)					// �������Ƿ�Ϊ�� 
{
	return q->front == NULL;
}

typedef struct {                            //ջ��������������ɣ��ڴ˶���
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* ret = (MyStack*)malloc(sizeof(MyStack));           //������MyStack ret ��Ϊ����������Ǿֲ�������Ҫ���ٿռ䡣

	QueueInit(&ret->q1);                                         //��ʼ������
	QueueInit(&ret->q2);


	return ret;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {                 //ѹ�벻�ǿյ��Ǹ�����

	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);

	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* pEmpty = &obj->q1, * pNonEmpty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		pEmpty = &obj->q2;
		pNonEmpty = &obj->q1;
	}
	while (QueueSize(pNonEmpty) > 1)
	{
		QueuePush(pEmpty, QueueFront(pNonEmpty));
		QueuePop(pNonEmpty);
	}
	// printf("%d\n",QueueBack(pNonEmpty));
	int top = QueueFront(pNonEmpty);
	//��βԪ�س���
	QueuePop(pNonEmpty);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {          //ֱ�ӷ���ջ��
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);            //ֱ�ӷ���
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

int main()
{

}
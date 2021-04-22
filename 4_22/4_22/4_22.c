#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QueueData;

struct QueueNode					//链式结构：表示队列 (被操作的)
{
	struct QueueNode* next;
	QueueData val;
};

typedef struct QueueNode QueueN;

struct Queue						// 队列的结构(头尾指针）
{
	struct QueueNode* front;		//要指向节点，所以结构是struct QueueNode*
	struct QueueNode* back;
};

typedef struct Queue Queue;

QueueN* BuyQueueNode(QueueData x)		//创建节点
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

void QueueInit(Queue* q)		// 初始化队列
{
	assert(q);

	q->back = NULL;
	q->front = NULL;
}

void QueueDestroy(Queue* q)				// 销毁队列 
{
	assert(q);

	Queue* cur = q;
	while (cur->front)					//需要判断cur->front，cur永远不会为空
	{
		Queue* Next = cur->front->next;
		free(cur->front);
		cur->front = Next;
	}
	q->back = q->front = NULL;
}

void QueuePush(Queue* q, QueueData data)		// 队尾入队列 
{
	assert(q);

	QueueN* cur = BuyQueueNode(data);



	if (q->front == NULL)
	{
		q->back = q->front = cur;
	}
	else									//队尾进，对首出
	{
		q->back->next = cur;
		q->back = cur;
	}
}

void QueuePop(Queue* q)					// 队头出队列 
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

QueueData QueueFront(Queue* q)				// 获取队列头部元素
{
	assert(q);

	if (q->front == NULL)				//不用判断，为空时，返回空
		return;
	return q->front->val;
}

QueueData QueueBack(Queue* q)				// 获取队列队尾元素 
{
	assert(q);

	if (q->back == NULL)
		return;

	return q->back->val;
}

int QueueSize(Queue* q)					// 获取队列中有效元素个数
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

bool QueueEmpty(Queue* q)					// 检测队列是否为空 
{
	return q->front == NULL;
}

typedef struct {                            //栈是由两个队列组成，在此定义
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* ret = (MyStack*)malloc(sizeof(MyStack));           //不能用MyStack ret 因为这样定义的是局部变量，要开辟空间。

	QueueInit(&ret->q1);                                         //初始化队列
	QueueInit(&ret->q2);


	return ret;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {                 //压入不是空的那个队列

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
	//队尾元素出队
	QueuePop(pNonEmpty);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {          //直接返回栈顶
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
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);            //直接返回
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

int main()
{

}
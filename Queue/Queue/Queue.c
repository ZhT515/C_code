#include"Queue.h"

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
	
	//if (q->front == NULL)				//不用判断，为空时，返回空
	//	return;

	return q->front->val;
}

QueueData QueueBack(Queue* q)				// 获取队列队尾元素 
{
	assert(q);

	//if (q->back == NULL)
	//	return;

	return q->back->val;
}

int QueueSize(Queue* q)					// 获取队列中有效元素个数
{
	assert(q);

	int count = 0;
	Queue* cur = q;
	while (cur->front)
	{
		cur->front = cur->front->next;
		count++;
	}

	return count;
}

bool QueueEmpty(Queue* q)					// 检测队列是否为空 
{
	return q->front == NULL;				
}
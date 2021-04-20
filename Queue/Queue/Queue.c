#include"Queue.h"

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
	
	//if (q->front == NULL)				//�����жϣ�Ϊ��ʱ�����ؿ�
	//	return;

	return q->front->val;
}

QueueData QueueBack(Queue* q)				// ��ȡ���ж�βԪ�� 
{
	assert(q);

	//if (q->back == NULL)
	//	return;

	return q->back->val;
}

int QueueSize(Queue* q)					// ��ȡ��������ЧԪ�ظ���
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

bool QueueEmpty(Queue* q)					// �������Ƿ�Ϊ�� 
{
	return q->front == NULL;				
}
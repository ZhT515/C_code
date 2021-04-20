#pragma once
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

void QueueInit(Queue* q);					// ��ʼ������ 

void QueuePush(Queue* q, QueueData data);		// ��β����� 

void QueuePop(Queue* q);					// ��ͷ������ 
 
QueueData QueueFront(Queue* q);				// ��ȡ����ͷ��Ԫ��

QueueData QueueBack(Queue* q);				// ��ȡ���ж�βԪ�� 
 
int QueueSize(Queue* q);					// ��ȡ��������ЧԪ�ظ���

bool QueueEmpty(Queue* q);					// �������Ƿ�Ϊ�� 

void QueueDestroy(Queue* q);				// ���ٶ��� 
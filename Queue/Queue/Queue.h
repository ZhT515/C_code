#pragma once
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

void QueueInit(Queue* q);					// 初始化队列 

void QueuePush(Queue* q, QueueData data);		// 队尾入队列 

void QueuePop(Queue* q);					// 队头出队列 
 
QueueData QueueFront(Queue* q);				// 获取队列头部元素

QueueData QueueBack(Queue* q);				// 获取队列队尾元素 
 
int QueueSize(Queue* q);					// 获取队列中有效元素个数

bool QueueEmpty(Queue* q);					// 检测队列是否为空 

void QueueDestroy(Queue* q);				// 销毁队列 
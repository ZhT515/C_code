#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int Stackdata;

struct Stack
{
	Stackdata* a;	//����
	int top;		//��
	int capacity;	//����
};

typedef struct Stack Stack;

void StackInit(Stack* ps);						// ��ʼ��ջ 
 
void StackPush(Stack* ps, Stackdata data);		// ��ջ
 
void StackPop(Stack* ps);						// ��ջ
 
Stackdata StackTop(Stack* ps);					// ��ȡջ��Ԫ��

int StackSize(Stack* ps);						// ��ȡջ����ЧԪ�ظ��� 

bool StackEmpty(Stack* ps);						// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 

void StackDestroy(Stack* ps);					// ����ջ 
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Stackdata;

struct Stack
{
	Stackdata* a;	//����
	int top;		//��
	int capacity;	//����
};

typedef struct Stack Stack;

void StackInit(Stack* ps);		// ��ʼ��ջ 
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int Stackdata;

struct Stack
{
	Stackdata* a;	//内容
	int top;		//顶
	int capacity;	//容量
};

typedef struct Stack Stack;

void StackInit(Stack* ps);						// 初始化栈 
 
void StackPush(Stack* ps, Stackdata data);		// 入栈
 
void StackPop(Stack* ps);						// 出栈
 
Stackdata StackTop(Stack* ps);					// 获取栈顶元素

int StackSize(Stack* ps);						// 获取栈中有效元素个数 

bool StackEmpty(Stack* ps);						// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 

void StackDestroy(Stack* ps);					// 销毁栈 
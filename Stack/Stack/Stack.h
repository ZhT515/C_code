#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Stackdata;

struct Stack
{
	Stackdata* a;	//内容
	int top;		//顶
	int capacity;	//容量
};

typedef struct Stack Stack;

void StackInit(Stack* ps);		// 初始化栈 
#include"Stack.h"

void StackInit(Stack* ps)		// ��ʼ��ջ 
{
	assert(ps);

	ps->a = (Stack*)malloc(sizeof(Stack) * 4);
	ps->capacity = 4;
	ps->top = 0;
}
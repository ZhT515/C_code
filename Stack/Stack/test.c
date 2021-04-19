#include"Stack.h"

void StackInit(Stack* ps)		// 初始化栈 
{
	assert(ps);

	ps->a = (Stack*)malloc(sizeof(Stack) * 2);			//给一个初始的空间方便后续翻倍
	ps->capacity = 2;		//容量
	ps->top = 0;			//栈顶
}

void StackDestroy(Stack* ps)					// 销毁栈 
{
	assert(ps);
	
	free(ps->a);
	ps->top = ps->capacity = 0;
}

bool StackEmpty(Stack* ps)						// 检测栈是否为空
{
	return ps->top != 0;
}

void StackPush(Stack* ps, Stackdata data)		// 入栈
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		ps->capacity *= 2;
		Stack* tmp = (Stack*)realloc(ps->a, sizeof(Stack) * ps->capacity);		//用中间变量更安全
		if (tmp == NULL)
		{
			exit(-1);
		}
		ps->a = tmp;
	}

	ps->a[ps->top] = data;
	ps->top++;
}

void StackPop(Stack* ps)						// 出栈
{
	assert(ps);

	if (!StackEmpty(&ps))
		return;

	ps->top--;
}

Stackdata StackTop(Stack* ps)					// 获取栈顶元素
{
	assert(ps);

	if (!StackEmpty(&ps))
		return (Stackdata)0;					
		
	return ps->a[ps->top - 1];					//-1才是栈顶
}

int StackSize(Stack* ps)						// 获取栈中有效元素个数 
{
	return ps->top;						
}
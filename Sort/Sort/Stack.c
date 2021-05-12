#include"Stack.h"

void StackInit(Stack* ps)		// ��ʼ��ջ 
{
	assert(ps);

	ps->a = (Stack*)malloc(sizeof(Stack) * 2);			//��һ����ʼ�Ŀռ䷽���������
	ps->capacity = 2;		//����
	ps->top = 0;			//ջ��
}

void StackDestroy(Stack* ps)					// ����ջ 
{
	assert(ps);
	
	free(ps->a);
	ps->top = ps->capacity = 0;
	ps->a = NULL;
}

bool StackEmpty(Stack* ps)						// ���ջ�Ƿ�Ϊ��
{
	return ps->top != 0;
}

void StackPush(Stack* ps, Stackdata data)		// ��ջ
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		ps->capacity *= 2;
		Stack* tmp = (Stack*)realloc(ps->a, sizeof(Stack) * ps->capacity);		//���м��������ȫ
		if (tmp == NULL)
		{
			exit(-1);
		}
		ps->a = tmp;
	}

	ps->a[ps->top] = data;
	ps->top++;
}

void StackPop(Stack* ps)						// ��ջ
{
	assert(ps);

	if (!StackEmpty(&ps))
		return;

	ps->top--;
}

Stackdata StackTop(Stack* ps)					// ��ȡջ��Ԫ��
{
	assert(ps);

	if (!StackEmpty(&ps))
		return (Stackdata)0;					
		
	return ps->a[ps->top - 1];					//-1����ջ��
}

int StackSize(Stack* ps)						// ��ȡջ����ЧԪ�ظ��� 
{
	return ps->top;						
}

bool isValid(char* s)
{
	Stack z;

	StackInit(&z);

	while (*s)
	{
		if (*s == '(' || *s == '{' || *s == '[')
		{
			StackPush(&z, *s);
			++s;
		}
		else
		{
			if (StackEmpty(&z))
				return false;
			char* b = StackTop(&z);
			if (b == '(' && *s != ')')
				return false;
			else if (b == '[' && *s != ']')
				return false;
			else if (b == '{' && *s != '}')
				return false;
			else
			{
				StackPop(&z);
				++s;                       //������һ��
			}
		}
	}


	bool ret = !StackEmpty(&z);
	StackDestroy(&z);

	return ret;
}
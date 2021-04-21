#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


typedef char Stackdata;

struct Stack
{
    Stackdata* a;	//����
    int top;		//��
    int capacity;	//����
};

typedef struct Stack Stack;

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
    assert(ps);

    int a = ps->top;
    if (a != 0)
    {
        return true;
    }

    else
    {
        return false;
    }

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

    ps->top--;
}

Stackdata StackTop(Stack* ps)					// ��ȡջ��Ԫ��
{
    assert(ps);

    return ps->a[ps->top - 1];					//-1����ջ��
}

int StackSize(Stack* ps)						// ��ȡջ����ЧԪ�ظ��� 
{
    return ps->top == 0;
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
            {
                char* b = StackTop(&z);
                if (b == '(' && *s != ')')
                {
                    StackDestroy(&z);
                    return false;
                }
                else if (b == '[' && *s != ']')
                {
                    StackDestroy(&z);
                    return false;
                }
                else if (b == '{' && *s != '}')
                {
                    StackDestroy(&z);
                    return false;
                }
                else
                {
                    StackPop(&z);
                    ++s;                       //������һ��
                }
            }
            else
            {
                return false;
            }
        }
    }
    int t = z.top;
    StackDestroy(&z);
    if (t == 0)
        return true;
    else
        return false;
}

int main()
{

}
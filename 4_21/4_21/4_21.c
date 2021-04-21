#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


typedef char Stackdata;

struct Stack
{
    Stackdata* a;	//内容
    int top;		//顶
    int capacity;	//容量
};

typedef struct Stack Stack;

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
    ps->a = NULL;
}

bool StackEmpty(Stack* ps)						// 检测栈是否为空
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

    ps->top--;
}

Stackdata StackTop(Stack* ps)					// 获取栈顶元素
{
    assert(ps);

    return ps->a[ps->top - 1];					//-1才是栈顶
}

int StackSize(Stack* ps)						// 获取栈中有效元素个数 
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
                    ++s;                       //访问下一个
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
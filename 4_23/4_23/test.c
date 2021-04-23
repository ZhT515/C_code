#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#define DEFSTACKSIZE 100
typedef int STDataType;

struct Stack
{
    STDataType* array;	//ÄÚÈÝ
    int size;		//¶¥
    int capacity;	//ÈÝÁ¿
};

typedef struct Stack Stack;

void CheckCapacity(Stack* ps)
{
    if (ps->size >= ps->capacity)
    {
        ps->capacity *= 2;
        ps->array = (STDataType*)realloc(ps->array, ps->capacity * sizeof(STDataType));
    }
}

void StackInit(Stack* ps)
{
    ps->array = (STDataType*)calloc(DEFSTACKSIZE, sizeof(STDataType));
    ps->capacity = DEFSTACKSIZE;
    ps->size = 0;
}

void StackPush(Stack* ps, STDataType x)
{
    CheckCapacity(ps);

    ps->array[ps->size] = x;
    ps->size++;
}

void StackPop(Stack* ps)
{
    if (ps->size == 0)
    {
        return;
    }
    ps->size--;
}

STDataType StackTop(Stack* ps)
{
    if (ps->size == 0)
    {
        return (STDataType)0;
    }
    return ps->array[ps->size - 1];
}

int StackEmpty(Stack* ps)
{
    return ps->size == 0;
}

int StackSize(Stack* ps)
{
    return ps->size;
}

void StackDestory(Stack* ps)
{
    if (ps->array)
    {
        free(ps->array);
        ps->array = NULL;
        ps->size = 0;
        ps->capacity = 0;
    }
}

typedef struct {
    Stack PushS;
    Stack PopS;

} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* ret = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&ret->PushS);
    StackInit(&ret->PopS);

    return ret;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->PushS, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {

    if (StackEmpty(&obj->PopS))
    {
        while (!StackEmpty(&obj->PushS))
        {
            StackPush(&obj->PopS, StackTop(&obj->PushS));
            StackPop(&obj->PushS);
        }
    }

    int top = StackTop(&obj->PopS);
    StackPop(&obj->PopS);
    return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (StackEmpty(&obj->PopS))
    {

        while (!StackEmpty(&obj->PushS))
        {
            StackPush(&obj->PopS, StackTop(&obj->PushS));
            StackPop(&obj->PushS);
        }
    }

    return StackTop(&obj->PopS);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {

    return StackEmpty(&obj->PushS) && StackEmpty(&obj->PopS);
}

void myQueueFree(MyQueue* obj) {
    StackDestory(&obj->PushS);
    StackDestory(&obj->PopS);
    free(obj);
}

int main()
{

}
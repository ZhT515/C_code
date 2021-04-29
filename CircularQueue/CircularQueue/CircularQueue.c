#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct {
    int* a;
    int k;          //存数据的量
    int front;      //头
    int tail;       //尾

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));      //开辟数组空间
    obj->k = k;
    obj->front = 0;
    obj->tail = 0;

    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    int tailnext = obj->tail + 1;
    if (tailnext == obj->k + 1)      //obj->tail + 1 == obj->k + 1,指向最后一个空间时为满。
    {
        tailnext = 0;           //跳到头
    }
    return tailnext == obj->front;          //等于头则满
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    int tailnext = obj->tail + 1;
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    else
    {
        obj->a[obj->tail] = value;
        obj->tail++;

        if (obj->tail == obj->k + 1)     //存在边界情况，front=tail,然后压入，然后tail=k+1，此时队列没有满，tail需要指向头，形成闭环。
            obj->tail = 0;          //指向头

        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    else
    {
        obj->front++;
        if (obj->front == obj->k + 1)        //转圈
            obj->front = 0;
        return true;
    }

}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        int ret = obj->a[obj->front];
        return ret;
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        int tailpre = obj->tail - 1;
        if (tailpre == -1)
            tailpre = obj->k;

        return obj->a[tailpre];
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);

}

int main()
{

}
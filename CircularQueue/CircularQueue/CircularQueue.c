#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct {
    int* a;
    int k;          //�����ݵ���
    int front;      //ͷ
    int tail;       //β

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));      //��������ռ�
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
    if (tailnext == obj->k + 1)      //obj->tail + 1 == obj->k + 1,ָ�����һ���ռ�ʱΪ����
    {
        tailnext = 0;           //����ͷ
    }
    return tailnext == obj->front;          //����ͷ����
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

        if (obj->tail == obj->k + 1)     //���ڱ߽������front=tail,Ȼ��ѹ�룬Ȼ��tail=k+1����ʱ����û������tail��Ҫָ��ͷ���γɱջ���
            obj->tail = 0;          //ָ��ͷ

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
        if (obj->front == obj->k + 1)        //תȦ
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
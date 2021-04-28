#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>

typedef int HeapData;

struct Heap				//堆
{
	HeapData* a;
	int size;
	int capacity;
};

typedef struct Heap HP;


void Swap(int* a, int* b);

void  AdjustDown(int* a, int n, int parents);

void  AdjustUp(HP* hp, int child);

void HeapInitial(HP* hp, HeapData* a, int n);		//初始化

void HeapDestory(HP* hp);							//销毁

void HeapPush(HP* hp, HeapData a);					//增

void HeapPop(HP* hp);								//删

HeapData HeadTop(HP* hp);							//顶

int	HeapSize(HP* hp);								//数量

bool HeapEmpty(HP* hp);								//是否为空

void HeadPrint(HP* hp);								//打印
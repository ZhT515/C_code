#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>

typedef int HeapData;

struct Heap				//��
{
	HeapData* a;
	int size;
	int capacity;
};

typedef struct Heap HP;


void Swap(int* a, int* b);

void  AdjustDown(int* a, int n, int parents);

void  AdjustUp(HP* hp, int child);

void HeapInitial(HP* hp, HeapData* a, int n);		//��ʼ��

void HeapDestory(HP* hp);							//����

void HeapPush(HP* hp, HeapData a);					//��

void HeapPop(HP* hp);								//ɾ

HeapData HeadTop(HP* hp);							//��

int	HeapSize(HP* hp);								//����

bool HeapEmpty(HP* hp);								//�Ƿ�Ϊ��

void HeadPrint(HP* hp);								//��ӡ
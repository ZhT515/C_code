#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DLData;

typedef struct DListNode
{
	struct DListNode* next;
	struct DListNode* prev;
	DLData val;
}DLN;

DLN* ListCreate();

void DLPrint(DLN* head);		//打印

void ListPushBack(DLN* head, DLData x); //尾插

void ListPopBack(DLN* head); //尾删

void ListPushFront(DLN* head, DLData x); //头插

void ListPopFront(DLN* head); //头删

DLN* ListFind(DLN* head, DLData x); //查找

void ListInsert(DLN* pos, DLData x); //POS位插

void ListErase(DLN* pos); //POS位删

void ListDestor(DLN* head); //清空
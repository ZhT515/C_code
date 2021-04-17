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

void DLPrint(DLN* head);		//��ӡ

void ListPushBack(DLN* head, DLData x); //β��

void ListPopBack(DLN* head); //βɾ

void ListPushFront(DLN* head, DLData x); //ͷ��

void ListPopFront(DLN* head); //ͷɾ

DLN* ListFind(DLN* head, DLData x); //����

void ListInsert(DLN* pos, DLData x); //POSλ��

void ListErase(DLN* pos); //POSλɾ

void ListDestor(DLN* head); //���
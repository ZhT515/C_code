#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLTDataType;		//用SLTDataType 代替

typedef struct SListNode		//单向+不带头+不循环
{
	SLTDataType x;
	struct SListNode* next;			//此时typedef struct还未生效，需要写全称。
}SL;

void SListprint(SL* plist);			//打印

void SListPushBack(SL** pplist, SLTDataType x);			//尾插

void SListPushFront(SL** pplist, SLTDataType x);		//头插

void SListPopBack(SL** pplist);				//尾删

void SListPopFront(SL** pplist);				//头删

SL* SListFind(SL* plist, SLTDataType x);		// 单链表查找

void SListInsertAfter(SL* pos, SLTDataType x);		// 单链表在pos位置之后插入x

void SListEraseAfter(SL* pos);				// 单链表删除pos位置之后的值

void SListDestory(SL* plist);				// 单链表的销毁
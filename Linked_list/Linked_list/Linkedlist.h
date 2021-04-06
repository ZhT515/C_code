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

void SListPushBack(SL** pplist, int x);			//尾插
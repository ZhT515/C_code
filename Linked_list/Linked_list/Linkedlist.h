#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLTDataType;		//��SLTDataType ����

typedef struct SListNode		//����+����ͷ+��ѭ��
{
	SLTDataType x;
	struct SListNode* next;			//��ʱtypedef struct��δ��Ч����Ҫдȫ�ơ�
}SL;

void SListprint(SL* plist);			//��ӡ

void SListPushBack(SL** pplist, int x);			//β��
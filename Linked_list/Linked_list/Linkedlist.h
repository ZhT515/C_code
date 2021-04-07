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

void SListPushBack(SL** pplist, SLTDataType x);			//β��

void SListPushFront(SL** pplist, SLTDataType x);		//ͷ��

void SListPopBack(SL** pplist);				//βɾ

void SListPopFront(SL** pplist);				//ͷɾ

SL* SListFind(SL* plist, SLTDataType x);		// ���������

void SListInsertAfter(SL* pos, SLTDataType x);		// ��������posλ��֮�����x

void SListEraseAfter(SL* pos);				// ������ɾ��posλ��֮���ֵ

void SListDestory(SL* plist);				// �����������
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;		//��������������һ������

typedef struct Seqlist
{
	SLDateType* a;	//���ڱ���˳���ʼ��ַ
	int size;		//��ǰ����
	int limit;	    //�ܳ���
}Seq;

void SeqListInit(Seq* ps);		//��ʼ��

void SeqListPrint(Seq* ps);		//��ӡ

void SeqListDestory(Seq* ps);  //����

void SeqListPushBack(Seq* ps, SLDateType n);	//β��

void SeqListPushFront(Seq* ps, SLDateType n);	//ͷ��

void SeqListDelBack(Seq* ps);  //βɾ

void SeqListDelFront(Seq* ps);  //ͷɾ

void SeqListInsert(Seq* ps, size_t pos, SLDateType x); //˳�����posλ�ò���x

void SeqListErase(Seq* ps, size_t pos);			// ˳���ɾ��posλ�õ�ֵ

int SeqListFind(Seq* ps, SLDateType x);			// ˳������
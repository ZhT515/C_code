#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;		//给数据类型起了一个别名

typedef struct Seqlist
{
	SLDateType* a;	//用于保存顺序表开始地址
	int size;		//当前长度
	int limit;	    //总长度
}Seq;

void SeqListInit(Seq* ps);		//初始化

void SeqListPrint(Seq* ps);		//打印

void SeqListDestory(Seq* ps);  //销毁

void SeqListPushBack(Seq* ps, SLDateType n);	//尾插

void SeqListPushFront(Seq* ps, SLDateType n);	//头插

void SeqListDelBack(Seq* ps);  //尾删

void SeqListDelFront(Seq* ps);  //头删

void SeqListInsert(Seq* ps, size_t pos, SLDateType x); //顺序表在pos位置插入x

void SeqListErase(Seq* ps, size_t pos);			// 顺序表删除pos位置的值

int SeqListFind(Seq* ps, SLDateType x);			// 顺序表查找
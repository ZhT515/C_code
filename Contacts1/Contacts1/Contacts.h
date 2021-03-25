#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELL_MAX 12
#define ADDRESS_MAX 30

typedef struct Personal		//个人信息结构体
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tell[TELL_MAX];
	char address[ADDRESS_MAX];
}Persona;

struct Contact		//通讯录
{
    Persona data[MAX];		//每创建一个就包含1000个 个人
	int sz;
};

void addContacts(struct Contact* Con);			//增加

void Initialize(struct Contact* Con);			//初始化函数

void delContacts(struct Contact* Con);			//删除

void modContacts(struct Contact* Con);			//修改

void showContacts(struct Contact* Con);			//展示

void findContacts(struct Contact* Con);			//查找



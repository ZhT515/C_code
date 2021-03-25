#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELL_MAX 12
#define ADDRESS_MAX 30

#define CAPACITY_SZ 3

typedef struct Personal		//������Ϣ�ṹ��
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tell[TELL_MAX];
	char address[ADDRESS_MAX];
}Persona;

//struct Contact		//ͨѶ¼
//{
//    Persona data[MAX];		//ÿ����һ���Ͱ���1000�� ����
//	int sz;
//};

struct Contact		//ͨѶ¼
{
	Persona *data;
	int sz;
	int capacity;		//�������
};

void addContacts(struct Contact* Con);			//����

void Initialize(struct Contact* Con);			//��ʼ������

void delContacts(struct Contact* Con);			//ɾ��

void modContacts(struct Contact* Con);			//�޸�

void showContacts(struct Contact* Con);			//չʾ

void findContacts(struct Contact* Con);			//����



#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#pragma pack (1)		//����Ĭ�϶�����Ϊ1

#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��
#define my_offsetof(type,mem) (size_t)&(((type *)0)->mem)

//struct Address			//ͨѶ¼����׼��
//{
//	char name[20];
//	int age;
//	char tell[11];
//	char id[11];
//};				//�������͵�ͬʱ�������a1
//
//struct						//�����ṹ������
//{
//	char name[20];
//	int age;
//	float f;
//}x;
//
//struct
//{
//	char name[20];
//	int age;
//	float f;
//}a[10],*p;
//
//struct note		//�ṹ��������
//{
//	int i;
//	struct note* a;
//};
//
//typedef struct note1
//{
//	int i;
//	struct note1* a;
//};
//
//struct xy			//ͨѶ¼����׼��
//{
//	int a;
//	int b;
//}a1;
//
//struct stu2
//{
//	char name[20];
//	int age;
//};
//
//struct note2
//{
//	int i;
//	struct note* a;
//}n2 = {20,NULL};
//
//int main()
//{
//	struct S1
//	{
//		char c1;
//		int i;
//		char c2;
//	};
//	printf("%d\n", sizeof(struct S1));
//
//	struct S2
//	{
//		char c1;
//		char c2;
//		int i;
//	};
//	printf("%d\n", sizeof(struct S2));
//
//	int x = 0;
//	int y = 0;
//	struct xy a2;		//����ṹ�����a2
//	struct xy p3 = { x, y };  //���������ͬʱ����ֵ��
//	struct stu2 b = { "asdfqwe",20 };
//	struct note2 n3 = { 20,NULL };
//}

struct Stu
{
	char name[20];
	int age;
};

struct Stu s = { "asdqwe",22 };

struct A
{
	int a : 2;
	int b : 4;
	int c : 8;
	int d : 9;
};

enum day		//����
{
	Mon,
	Tues,
	Wed,
	Thur,
	Fri,
	Sat,
	Sun
};

enum Color//��ɫ
{
	RED,
	GREEN,
	BLUE
};

union UN	//���ϱ���������
{
	int a;
	char c;
};

void print1(struct Stu s)		//�ṹ�崫��
{
	printf("%s\n", s.name);
}

void print2(struct Stu* ps)	//�ṹ���ַ����
{
	printf("%s\n", ps->name);
}

int main()
{
	union Un1
	{
		char c[5];
		int i;
	};
	union Un2
	{
		short c[7];
		int i;
	};

	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));
	union UN un;			//���ϱ����Ķ���
	printf("%d\n", sizeof(un));//���ϱ����Ĵ�С

	printf("%d\n", sizeof(struct A));
	print1(s);
	print2(&s);
}
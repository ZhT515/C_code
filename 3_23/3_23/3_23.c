#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#pragma pack (1)		//设置默认对齐数为1

#pragma pack()//取消设置的默认对齐数，还原为默认
#define my_offsetof(type,mem) (size_t)&(((type *)0)->mem)

//struct Address			//通讯录（标准）
//{
//	char name[20];
//	int age;
//	char tell[11];
//	char id[11];
//};				//声明类型的同时定义变量a1
//
//struct						//匿名结构体类型
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
//struct note		//结构的自引用
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
//struct xy			//通讯录（标准）
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
//	struct xy a2;		//定义结构体变量a2
//	struct xy p3 = { x, y };  //定义变量的同时赋初值。
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

enum day		//星期
{
	Mon,
	Tues,
	Wed,
	Thur,
	Fri,
	Sat,
	Sun
};

enum Color//颜色
{
	RED,
	GREEN,
	BLUE
};

union UN	//联合变量的声明
{
	int a;
	char c;
};

void print1(struct Stu s)		//结构体传参
{
	printf("%s\n", s.name);
}

void print2(struct Stu* ps)	//结构体地址传参
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
	union UN un;			//联合变量的定义
	printf("%d\n", sizeof(un));//联合变量的大小

	printf("%d\n", sizeof(struct A));
	print1(s);
	print2(&s);
}
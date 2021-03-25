#define _CRT_SECURE_NO_WARNINGS 1
#include"Contacts.h"
//
//写一个通讯录
//可以保存1000个人的信息
//每个人的信息：
//名字
//年龄
//性别
//电话
//住址

//功能：
//1. 增加一个人的信息
//2. 删除一个指定的联系人
//3. 查找一个指定的联系人
//4. 修改一个指定的联系人
//5. 显示通讯录中所有人的信息
//6. 排序
//0. 退出
//
//静态版本 - 一次开辟1000个元素的连续空间
//动态增长的版本 - 按需开辟
//文件的版本 - 数据可以存储到文件中，不至于丢失

enum Features
{
	Exit = 0,
	add,
	del,
	find,
	mod,
	show,
	sort,
};

void menu()
{
	printf("*****************************\n");
	printf("****1.add  ****2.  del ******\n");
	printf("****3.find ****4.  mod ******\n");
	printf("****5.show ****6. sort ******\n");
	printf("****0.exit ******************\n");
	printf("*****************************\n");
	printf("请选择--->");
}

int main()
{
	int input = 0;
	struct Contact Con;		//创建一个通讯录

	Initialize(&Con);			//初始化
	do
	{
		menu();
		scanf("%d", &input);

		switch (input)
		{
			case add:
				addContacts(&Con);
				break;
			case del:
				delContacts(&Con);
				break;
			case find:
				findContacts(&Con);
				break;
			case mod:
				modContacts(&Con);
				break;
			case show:
				showContacts(&Con);
				break;
			case sort:
				sortContacts(&Con);
				break;
			case Exit:
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
		}
	} while (input);
	return 0;
}
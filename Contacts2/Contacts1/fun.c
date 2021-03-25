#define _CRT_SECURE_NO_WARNINGS 1
#include"Contacts.h"

//void Initialize(struct Contact * Con)
//{
//	Con->sz = 0;
//	memset(Con->data, 0, sizeof(Con->data));		//void *memset(void *s, int ch, size_t n);将s中当前位置后面的n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
//}

int Expansion(struct Contact* Con)
{
	if (Con->sz == Con->capacity)			//满了才扩
	{
		//(起始地址，包含以前的大小的总大小所以是3+2)
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(Con->data, (Con->capacity + 2) * sizeof(struct Personal));
		if (ptr == NULL)
		{
			printf("扩容失败\n");
			return 0;
		}
		else
		{
			Con->data = ptr;
			Con->capacity += 2;
			printf("扩容成功\n");
			return 1;
		}
	}
	return 1;
}

void LoadContact(struct Contact* Con)		//读取文件中已经有的
{
	FILE* puin = fopen("contact.dat","rb");		//打开文件，二进制读
	if (puin == NULL)
	{
		printf("打开失败\n");
		return;
	}
	Persona tmp = { 0 };			//相当于中间变量
	while (fread(&tmp, sizeof(Persona), 1, puin))		//取出一个单位的内容到tmp的地址中
	{
		if (Expansion(Con) == 0)		//相当于增加，所以要判断容量
		{
			printf("容量不足且扩容失败\n");
			return;
		}
		Con->data[Con->sz] = tmp;			//当前位置的值
		Con->sz++;
	}
	fclose(puin);					//读完关闭文件，并将指针滞空
	puin = NULL;
}

void Initialize(struct Contact* Con)		//动态版本初始化
{
	Con->sz = 0;
	Con->capacity = CAPACITY_SZ;
	Con->data = (struct PeoInfo*)malloc(CAPACITY_SZ * sizeof(struct Personal)); // void *malloc(size_t size) 分配所需的内存空间，并返回一个指向它的无类型指针。所以强制类型转换
	if (Con->data == NULL)
	{
		printf("初始化失败\n");
		exit(1);		//exit(1)表示异常退出
	}
	LoadContact(Con);
}
void addContacts(struct Contact * Con)				//增加
{
	if (Expansion(Con) == 0)
	{
		printf("容量不足且扩容失败\n");
		return;
	}

	printf("请输入姓名：");
	scanf("%s", &(Con->data[Con->sz].name));
	printf("请输入年龄：");
	scanf("%d", &(Con->data[Con->sz].age));
	printf("请输入性别：");
	scanf("%s", &(Con->data[Con->sz].sex));
	printf("请输入电话：");
	scanf("%s", &(Con->data[Con->sz].tell));
	printf("请输入地址：");
	scanf("%s", &(Con->data[Con->sz].address));
	printf("保存成功\n");
	(Con->sz)++;
}

void showContacts(struct Contact* pc)
{
	int i = 0;
	if ((pc->sz) == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		//%-20s -靠左，占20位  \t属于转义字符。是水平制表符
		while (i < (pc->sz))			//从0向上加
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n", 
				pc->data[i].name, 
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tell,
				pc->data[i].address);
			i++;
		}
	}
}

static int FindName(char name[NAME_MAX],const struct Contact* Con)			//寻找名字对应的行数,全局变量
{
	int i = 0;
	for (i = 0; i < Con->sz; i++)
	{
		//只能用strcmp判断完全相同，STRSTR不可
		if (strcmp((Con->data[i].name), name) == 0)
		{
			return i;
		}
	}
	return -1;

}

void modContacts(struct Contact* Con)			//修改
{
	char name[NAME_MAX];
	if (Con->sz == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("请输入需要修改人的姓名:>");
		scanf("%s", &name);
		int ret = FindName(name, Con);		//这里Con本身就是指针变量，不能再取地址
		if (ret == -1)
		{
			printf("不存在\n");
		}
		else
		{
			printf("请输入姓名：");
			scanf("%s", &(Con->data[ret].name));
			printf("请输入年龄：");
			scanf("%d", &(Con->data[ret].age));
			printf("请输入性别：");
			scanf("%s", &(Con->data[ret].sex));
			printf("请输入电话：");
			scanf("%s", &(Con->data[ret].tell));
			printf("请输入地址：");
			scanf("%s", &(Con->data[ret].address));
			printf("修改成功\n");
		}
	}
}

void findContacts(struct Contact* Con)			//查找
{
	char name[NAME_MAX];
	if (Con->sz == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("请输入需要查找人的姓名:>");
		scanf("%s", &name);
		int ret = FindName(name, Con);		//这里Con本身就是指针变量，不能再取地址
		if (ret == -1)
		{
			printf("查无此人\n");
		}
		else
		{
			printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
			printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n",
				Con->data[ret].name,
				Con->data[ret].age,
				Con->data[ret].sex,
				Con->data[ret].tell,
				Con->data[ret].address);
		}
	}
}

void delContacts(struct Contact* Con)
{
	char name[NAME_MAX];

	if (Con->sz == 0)
	{
		printf("通讯录为空，没法删除\n");
	}
	else
	{
		printf("请输入需要删除人的姓名:>");
		scanf("%s", &name);
		int ret = FindName(name, Con);
		if (ret == -1)
		{
			printf("查无此人\n");
		}
		else
		{
			int j = 0;
			for (j = ret; j < (Con->sz - 1); j++)		//向前挪一个
			{
				Con->data[j] = Con->data[j + 1];
			}
			Con->sz--;			//总数减一
			printf("删除成功\n");
		}
	}
}

void sortContacts(struct Contact* Con)
{
	FILE* pout = fopen("contact.dat", "wb");		//打开文件，二进制写
	if (pout == NULL)
	{
		printf("打开失败\n");
		return;
	}

	for (int i = 0; i < Con->sz; i++)
	{
		fwrite(Con->data + i, sizeof(Persona), 1, pout);
	}
	printf("保存成功\n");
	fclose(pout);
	pout = 0;
}
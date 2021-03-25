#define _CRT_SECURE_NO_WARNINGS 1
#include"Contacts.h"

void Initialize(struct Contact * Con)
{
	Con->sz = 0;
	memset(Con->data, 0, sizeof(Con->data));		//void *memset(void *s, int ch, size_t n);��s�е�ǰλ�ú����n���ֽ� ��typedef unsigned int size_t ���� ch �滻������ s ��
}

void addContacts(struct Contact * Con)				//����
{
	if ((Con->sz) == MAX)
	{
		printf("ͨѶ¼����");
	}
	else
	{
		printf("������������");
		scanf("%s", &(Con->data[Con->sz].name));
		printf("���������䣺");
		scanf("%d", &(Con->data[Con->sz].age));
		printf("�������Ա�");
		scanf("%s", &(Con->data[Con->sz].sex));
		printf("������绰��");
		scanf("%s", &(Con->data[Con->sz].tell));
		printf("�������ַ��");
		scanf("%s", &(Con->data[Con->sz].address));
		printf("����ɹ�\n");
		(Con->sz)++;
	}
}

void showContacts(struct Contact* pc)
{
	int i = 0;
	if ((pc->sz) == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//%-20s -����ռ20λ  \t����ת���ַ�����ˮƽ�Ʊ��
		while (i < (pc->sz))			//��0���ϼ�
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

static int FindName(char name[NAME_MAX],const struct Contact* Con)			//Ѱ�����ֶ�Ӧ������,ȫ�ֱ���
{
	int i = 0;
	for (i = 0; i < Con->sz; i++)
	{
		//ֻ����strcmp�ж���ȫ��ͬ��STRSTR����
		if (strcmp((Con->data[i].name), name) == 0)
		{
			return i;
		}
	}
	return -1;

}

void modContacts(struct Contact* Con)			//�޸�
{
	char name[NAME_MAX];
	if (Con->sz == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("��������Ҫ�޸��˵�����:>");
		scanf("%s", &name);
		int ret = FindName(name, Con);		//����Con�������ָ�������������ȡ��ַ
		if (ret == -1)
		{
			printf("������\n");
		}
		else
		{
			printf("������������");
			scanf("%s", &(Con->data[ret].name));
			printf("���������䣺");
			scanf("%d", &(Con->data[ret].age));
			printf("�������Ա�");
			scanf("%s", &(Con->data[ret].sex));
			printf("������绰��");
			scanf("%s", &(Con->data[ret].tell));
			printf("�������ַ��");
			scanf("%s", &(Con->data[ret].address));
			printf("�޸ĳɹ�\n");
		}
	}
}

void findContacts(struct Contact* Con)			//����
{
	char name[NAME_MAX];
	if (Con->sz == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("��������Ҫ�����˵�����:>");
		scanf("%s", &name);
		int ret = FindName(name, Con);		//����Con�������ָ�������������ȡ��ַ
		if (ret == -1)
		{
			printf("���޴���\n");
		}
		else
		{
			printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("ͨѶ¼Ϊ�գ�û��ɾ��\n");
	}
	else
	{
		printf("��������Ҫɾ���˵�����:>");
		scanf("%s", &name);
		int ret = FindName(name, Con);
		if (ret == -1)
		{
			printf("���޴���\n");
		}
		else
		{
			int j = 0;
			for (j = ret; j < (Con->sz - 1); j++)		//��ǰŲһ��
			{
				Con->data[j] = Con->data[j + 1];
			}
			Con->sz--;			//������һ
			printf("ɾ���ɹ�");
		}
	}
}

void sortContacts(struct Contact* Con)
{
	printf("����ʵ��\n");
}
#define _CRT_SECURE_NO_WARNINGS 1
#include"Contacts.h"
//
//дһ��ͨѶ¼
//���Ա���1000���˵���Ϣ
//ÿ���˵���Ϣ��
//����
//����
//�Ա�
//�绰
//סַ

//���ܣ�
//1. ����һ���˵���Ϣ
//2. ɾ��һ��ָ������ϵ��
//3. ����һ��ָ������ϵ��
//4. �޸�һ��ָ������ϵ��
//5. ��ʾͨѶ¼�������˵���Ϣ
//6. ����
//0. �˳�
//
//��̬�汾 - һ�ο���1000��Ԫ�ص������ռ�
//��̬�����İ汾 - ���迪��
//�ļ��İ汾 - ���ݿ��Դ洢���ļ��У������ڶ�ʧ

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
	printf("��ѡ��--->");
}

int main()
{
	int input = 0;
	struct Contact Con;		//����һ��ͨѶ¼

	Initialize(&Con);			//��ʼ��
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
				printf("�����������������\n");
				break;
		}
	} while (input);
	return 0;
}
#include"Seqlist.h"

void TestSeqList1()
{
	Seq s;		//�����ṹ��
	SeqListInit(&s);	//��ʼ��

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListDelBack(&s);
	SeqListDelFront(&s);
	SeqListInsert(&s, 9, 4);
	SeqListErase(&s, 5);
	int ret = SeqListFind(&s, 1);
	printf("%d\n", ret);
	SeqListPrint(&s);

	SeqListDestory(&s);
}

int main()
{
	TestSeqList1();			//˳������ɾ���

	return 0;
}
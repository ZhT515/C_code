#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

typedef char Treetype;

struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	Treetype data;
};

typedef struct BinaryTreeNode BTN;

void PrevOrder(BTN* root)		//ǰ�򣬸�����
{
	if (root == NULL)			//���򷵻�
	{
		printf("NULL ");
		return;
	}

	printf("%c ",root->data);	//������
	PrevOrder(root->left);		//��
	PrevOrder(root->right);		//��
}

void InOrder(BTN* root)		//ǰ�򣬸�����
{
	if (root == NULL)			//���򷵻�
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);		//��
	printf("%c ", root->data);	//������
	InOrder(root->right);		//��
}

void PostOrder(BTN* root)		//ǰ�򣬸�����
{
	if (root == NULL)			//���򷵻�
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);		//��
	PostOrder(root->right);		//��
	printf("%c ", root->data);	//������
}

void TreeSize(BTN* root, int* psize)		//��������
{
	if (root == NULL)			//���򷵻�
	{
		return;
	}

	++(*psize);
	TreeSize(root->left,psize);		//��
	TreeSize(root->right, psize);		//��
}

int TreeSize2(BTN* root)		//�ݹ�
{
	return root == NULL ? 0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;   //Ϊ�շ���0����Ϊ�շ�����������+1���Լ���
}

int TreeLeafSize(BTN* root)		//�ݹ�Ҷ����
{
	if (root == NULL)			//���򷵻�
	{
		return 0;
	}
	if (root->left  == NULL &&root->right==NULL)			//����Ϊ����ΪҶ��
	{
		return 1;
	}

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);		//�ڵ㷵������������Ҷ������
}

int TreeKLSize(BTN* root, int k)		//K��������ݹ�
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}

	return TreeKLSize(root->left, k - 1)+TreeKLSize(root->right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTN* BinaryTreeFind(BTN* root, Treetype x)
{
	if (root == NULL)			//���򷵻�
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	BTN* tmp = BinaryTreeFind(root->right, x);
	if (tmp != NULL)
		return tmp;
	
	return BinaryTreeFind(root->left, x);

		
}

void BinaryTreeLevelOrder(BTN* root)			//����ͨ������ʵ�֣����洢BTN*��
{

	Queue q;
	QueueInit(&q);					//��ʼ��
	if (root)						//ͷ��Ϊ�վͽ���
	{
		QueuePush(&q, root);
	}
	
	while (!QueueEmpty(&q))			//����Ϊ�գ��ͼ���
	{
		BTN* front = QueueFront(&q);	//����
		QueuePop(&q);					

		printf("%c ",front->data);
		if (front->left != NULL)		//�����������Ӳ�Ϊ�վ���� 
		{
			QueuePush(&q, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&q, front->right);
		}
	}
	QueueDestroy(&q);

}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTN* root)		//���򣬽ڵ��������ɣ�������ֿպ��зǿ���Ϊ����ȫ
{
	Queue q;
	QueueInit(&q);					//��ʼ��
	if (root)						//ͷ��Ϊ�վͽ���
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))			//����Ϊ�գ��ͼ���
	{
		BTN* front = QueueFront(&q);	//����
		QueuePop(&q);

		if (front == NULL)				//�������գ�ֹͣ���ӣ���ѭ��
		{
			break;
		}

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))			//����Ϊ�գ��ͼ�������������������
	{
		BTN* front = QueueFront(&q);
		QueuePop(&q);

		if (front)					//����Ӧ��ʣ�µĶ�Ϊ�գ�������Ϊ����˵��������ȫ������
			return false;
	}

	QueueDestroy(&q);
	return true;
}

int BinaryTreeDestry(BTN* root)			//����
{
	if (root == NULL)
		return;

	BinaryTreeDestry(root->left);				//�����������
	BinaryTreeDestry(root->right);
	free(NULL);
}

int main()
{
	BTN* A = (BTN*)malloc(sizeof(BTN));
	BTN* B = (BTN*)malloc(sizeof(BTN));
	BTN* C = (BTN*)malloc(sizeof(BTN));
	BTN* D = (BTN*)malloc(sizeof(BTN));
	BTN* E = (BTN*)malloc(sizeof(BTN));
	BTN* F = (BTN*)malloc(sizeof(BTN));


	A->left = B;
	B->left = D;
	C->left = E;
	D->left = NULL;
	E->left = NULL;
	F->left = NULL;

	A->right = C;
	B->right = NULL;
	C->right = F;
	D->right = NULL;
	E->right = NULL;
	F->right = NULL;

	A->data = 'A';
	B->data = 'B';
	C->data = 'C';
	D->data = 'D';
	E->data = 'E';
	F->data = 'F';

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	int size = 0;
	TreeSize(A, &size);
	printf("%d\n", size);

	printf("%d\n", TreeSize2(A));
	printf("%d\n", TreeLeafSize(A));
	printf("%d\n", TreeKLSize(A, 4));
	BTN* Q = BinaryTreeFind(A, 'B');
	if(Q != NULL)
		printf("%c\n", Q->data);
	BinaryTreeLevelOrder(A);
	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(A));
}
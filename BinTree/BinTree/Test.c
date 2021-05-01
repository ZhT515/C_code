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

void PrevOrder(BTN* root)		//前序，根左右
{
	if (root == NULL)			//空则返回
	{
		printf("NULL ");
		return;
	}

	printf("%c ",root->data);	//根操作
	PrevOrder(root->left);		//左
	PrevOrder(root->right);		//右
}

void InOrder(BTN* root)		//前序，根左右
{
	if (root == NULL)			//空则返回
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);		//左
	printf("%c ", root->data);	//根操作
	InOrder(root->right);		//右
}

void PostOrder(BTN* root)		//前序，根左右
{
	if (root == NULL)			//空则返回
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);		//左
	PostOrder(root->right);		//右
	printf("%c ", root->data);	//根操作
}

void TreeSize(BTN* root, int* psize)		//遍历计数
{
	if (root == NULL)			//空则返回
	{
		return;
	}

	++(*psize);
	TreeSize(root->left,psize);		//左
	TreeSize(root->right, psize);		//右
}

int TreeSize2(BTN* root)		//递归
{
	return root == NULL ? 0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;   //为空返回0；不为空返回左数右树+1（自己）
}

int TreeLeafSize(BTN* root)		//递归叶子数
{
	if (root == NULL)			//空则返回
	{
		return 0;
	}
	if (root->left  == NULL &&root->right==NULL)			//左右为空则为叶子
	{
		return 1;
	}

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);		//节点返回两个子树的叶子数量
}

int TreeKLSize(BTN* root, int k)		//K层的数量递归
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

// 二叉树查找值为x的节点
BTN* BinaryTreeFind(BTN* root, Treetype x)
{
	if (root == NULL)			//空则返回
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

void BinaryTreeLevelOrder(BTN* root)			//层序，通过队列实现，（存储BTN*）
{

	Queue q;
	QueueInit(&q);					//初始化
	if (root)						//头不为空就进队
	{
		QueuePush(&q, root);
	}
	
	while (!QueueEmpty(&q))			//树不为空，就继续
	{
		BTN* front = QueueFront(&q);	//出队
		QueuePop(&q);					

		printf("%c ",front->data);
		if (front->left != NULL)		//左右两个孩子不为空就入队 
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
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTN* root)		//层序，节点连续即可，如果出现空后有非空则为非完全
{
	Queue q;
	QueueInit(&q);					//初始化
	if (root)						//头不为空就进队
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))			//树不为空，就继续
	{
		BTN* front = QueueFront(&q);	//出队
		QueuePop(&q);

		if (front == NULL)				//当遇到空，停止进队，出循环
		{
			break;
		}

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))			//树不为空，就继续，把整个树遍历完
	{
		BTN* front = QueueFront(&q);
		QueuePop(&q);

		if (front)					//理论应该剩下的都为空，遇到不为空则说明不是完全二叉树
			return false;
	}

	QueueDestroy(&q);
	return true;
}

int BinaryTreeDestry(BTN* root)			//销毁
{
	if (root == NULL)
		return;

	BinaryTreeDestry(root->left);				//后序遍历销毁
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
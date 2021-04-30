#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};
//***************���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������*/

/*ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��****************/
bool PrevOrder(struct TreeNode* root, int x)
{
	if (root == NULL)
	{
		return true;
	}

	if (root->val != x)
	{
		return false;
	}

	return PrevOrder(root->left, x) && PrevOrder(root->right, x);
}

bool isUnivalTree(struct TreeNode* root) {
	if (root == NULL)
	{
		return true;
	}

	int val = root->val;
	return PrevOrder(root, val);
}
/*//////////////////////////************///////////////////////////

/************************����һ�����������ҳ���������**************************/
int maxDepth2(struct TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int maxDepth(struct TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	int left = maxDepth2(root->left);
	int right = maxDepth2(root->right);

	return left > right ? left + 1 : right + 1;
}

int main()
{

}
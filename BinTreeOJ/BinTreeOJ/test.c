#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};
//***************如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。*/

/*只有给定的树是单值二叉树时，才返回 true；否则返回 false。****************/
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

/************************给定一个二叉树，找出其最大深度**************************/
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
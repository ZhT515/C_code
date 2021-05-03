#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

 struct TreeNode {
      int val;
     struct TreeNode *left;
      struct TreeNode *right;
  };


int Size(struct TreeNode* root)
{
    return root == NULL ? 0 : Size(root->right) + Size(root->left) + 1;
}

void _preorder(struct TreeNode* root, int* arr, int* pi)      //不能每次递归都分配新空间，所以再增加一个子函数
{
    if (root == NULL)
    {
        return NULL;
    }

    arr[(*pi)++] = root->val;
    _preorder(root->left, arr, pi);
    _preorder(root->right, arr, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) //二叉树的前序遍历
{
    *returnSize = Size(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _preorder(root, arr, &i);      //i需要传指针
    return arr;
}

void _inorder(struct TreeNode* root, int* arr, int* pi)      //不能每次递归都分配新空间，所以再增加一个子函数
{
    if (root == NULL)
    {
        return NULL;
    }

    _inorder(root->left, arr, pi);
    arr[(*pi)++] = root->val;
    _inorder(root->right, arr, pi);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)       //二叉树中序遍历
{
    *returnSize = Size(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _inorder(root, arr, &i);      //i需要传指针
    return arr;
}

void _postorder(struct TreeNode* root, int* arr, int* pi)      //不能每次递归都分配新空间，所以再增加一个子函数
{
    if (root == NULL)
    {
        return NULL;
    }

    _postorder(root->left, arr, pi);

    _postorder(root->right, arr, pi);

    arr[(*pi)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)         //二叉树的后序遍历
{
    *returnSize = Size(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _postorder(root, arr, &i);      //i需要传指针
    return arr;
}

int main()
{

}
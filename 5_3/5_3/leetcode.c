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

void _preorder(struct TreeNode* root, int* arr, int* pi)      //����ÿ�εݹ鶼�����¿ռ䣬����������һ���Ӻ���
{
    if (root == NULL)
    {
        return NULL;
    }

    arr[(*pi)++] = root->val;
    _preorder(root->left, arr, pi);
    _preorder(root->right, arr, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) //��������ǰ�����
{
    *returnSize = Size(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _preorder(root, arr, &i);      //i��Ҫ��ָ��
    return arr;
}

void _inorder(struct TreeNode* root, int* arr, int* pi)      //����ÿ�εݹ鶼�����¿ռ䣬����������һ���Ӻ���
{
    if (root == NULL)
    {
        return NULL;
    }

    _inorder(root->left, arr, pi);
    arr[(*pi)++] = root->val;
    _inorder(root->right, arr, pi);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)       //�������������
{
    *returnSize = Size(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _inorder(root, arr, &i);      //i��Ҫ��ָ��
    return arr;
}

void _postorder(struct TreeNode* root, int* arr, int* pi)      //����ÿ�εݹ鶼�����¿ռ䣬����������һ���Ӻ���
{
    if (root == NULL)
    {
        return NULL;
    }

    _postorder(root->left, arr, pi);

    _postorder(root->right, arr, pi);

    arr[(*pi)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)         //�������ĺ������
{
    *returnSize = Size(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _postorder(root, arr, &i);      //i��Ҫ��ָ��
    return arr;
}

int main()
{

}
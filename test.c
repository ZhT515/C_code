#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};

 int maxDepth2(struct TreeNode* root){
     if(root==NULL)
     {
         return 0;
     }
     return fmax(maxDepth(root->left),maxDepth(root->right))+1;
 }

 int maxDepth(struct TreeNode* root){
     if(root==NULL)
     {
         return 0;
     }
     int left = maxDepth2(root->left);
     int right = maxDepth2(root->right);

     return left > right ? left+1:right+1;
 }

 bool isBalanced1(struct TreeNode* root){
     if(root == NULL)
         return true;

     int rightdepth = maxDepth(root->right);
     int leftdepth = maxDepth(root->left);

     return abs(leftdepth - rightdepth) < 2          //������Ȳ����ֵ��ÿ������ҲҪ����
             &&isBalanced(root->left)
             &&isBalanced(root->right);

 }

bool _isBalanced(struct TreeNode* root, int* hp) {
    if (root == NULL)
    {
        *hp = 0;            //Ϊ�����޸����Ϊ0
        return true;
    }

    int lefthp = 0;
    if (_isBalanced(root->left, &lefthp) == false)     //��������Ϊ�٣�ֱ�ӷ���
        return false;

    int righthp = 0;
    if (_isBalanced(root->right, &righthp) == false)
        return false;
    //��ʱ�����Ϣ���Ѹ���
    *hp = fmax(lefthp, righthp) + 1;         //������Ҷ�Ϊ�棬����������Ϣ��ȡ��������������Ǹ���ȣ���Ϊ���ڵ����

    return abs(lefthp - righthp) < 2;

}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;
    int head = 0;
    return _isBalanced(root, &head);
}

int main()
{

}
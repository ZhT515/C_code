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

     return abs(leftdepth - rightdepth) < 2          //左右深度差绝对值，每个子树也要满足
             &&isBalanced(root->left)
             &&isBalanced(root->right);

 }

bool _isBalanced(struct TreeNode* root, int* hp) {
    if (root == NULL)
    {
        *hp = 0;            //为空则修改深度为0
        return true;
    }

    int lefthp = 0;
    if (_isBalanced(root->left, &lefthp) == false)     //如果左或右为假，直接返回
        return false;

    int righthp = 0;
    if (_isBalanced(root->right, &righthp) == false)
        return false;
    //此时深度信息均已更新
    *hp = fmax(lefthp, righthp) + 1;         //如果左右都为真，则更新深度信息，取两个子树更大的那个深度，作为本节点深度

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
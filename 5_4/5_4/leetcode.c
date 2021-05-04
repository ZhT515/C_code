#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};

struct TreeNode* invertTree(struct TreeNode* root)          //翻转二叉树
{
    if (root == NULL)
    {
        return NULL;
    }
    struct TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    invertTree(root->right);
    invertTree(root->left);

    return root;
}

/*************对称二叉树***************/
bool _isSymmetric(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;

    return p->val == q->val
        && _isSymmetric(p->right, q->left)
        && _isSymmetric(p->left, q->right);
}

bool isSymmetric(struct TreeNode* root)     //一个向左，一个向右完全相同就可以
{
    if (root == NULL)
    {
        return true;
    }

    return root->val == root->val                       //两个分别左右进入就可以了
        && _isSymmetric(root->right, root->left)
        && _isSymmetric(root->left, root->right);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) //判断俩树是否相同
{
    if (p == NULL && q == NULL)			//空则返回
    {
        return true;
    }
    else if (p == NULL || q == NULL)
    {
        return false;
    }

    if (p->val != q->val)        //根不同
    {
        return false;
    }
    else {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);  //递归，左右分别相等，根相等
        //递归依然是两个树同时，所以结构一定相同
    }

}

/*****************另一个树的子树******************/
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    // if (root == NULL && subRoot == NULL)			//空则返回
    // {
    // 	return true;
    // }
    // if (root == NULL || subRoot == NULL)            //一个为空另一个不为空就为假
    // {
    //     return false;
    // }

    // if (root->val == subRoot->val)			//根相同
    // {
    //     if(isSameTree(root,subRoot))
    //         return true;
    // }

    // if(root->left != NULL 
    //     && root->left->val == subRoot->val 
    //     && root->right !=NULL)      //子树在左边，要先证明左右不为空，防止野指针
    // {
    //     if(isSameTree(root->left,subRoot))      //为真直接返回，不为真继续向下寻找
    //         return true;

    // }
    // if(root->right != NULL 
    //     && root->right->val == subRoot->val 
    //     && root->left !=NULL)      //右
    // {
    //     if(isSameTree(root->right,subRoot))
    //         return true;
    // }
    if (root == NULL)
    {
        return false;
    }

    if (isSameTree(root, subRoot))       //直接判断每个节点作为跟的子树是否相同，不同向下继续，直到为空返回假
        return true;

    return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);   //左右两边都要看
}

int main()
{

}
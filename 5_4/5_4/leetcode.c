#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};

struct TreeNode* invertTree(struct TreeNode* root)          //��ת������
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

/*************�Գƶ�����***************/
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

bool isSymmetric(struct TreeNode* root)     //һ������һ��������ȫ��ͬ�Ϳ���
{
    if (root == NULL)
    {
        return true;
    }

    return root->val == root->val                       //�����ֱ����ҽ���Ϳ�����
        && _isSymmetric(root->right, root->left)
        && _isSymmetric(root->left, root->right);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) //�ж������Ƿ���ͬ
{
    if (p == NULL && q == NULL)			//���򷵻�
    {
        return true;
    }
    else if (p == NULL || q == NULL)
    {
        return false;
    }

    if (p->val != q->val)        //����ͬ
    {
        return false;
    }
    else {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);  //�ݹ飬���ҷֱ���ȣ������
        //�ݹ���Ȼ��������ͬʱ�����Խṹһ����ͬ
    }

}

/*****************��һ����������******************/
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    // if (root == NULL && subRoot == NULL)			//���򷵻�
    // {
    // 	return true;
    // }
    // if (root == NULL || subRoot == NULL)            //һ��Ϊ����һ����Ϊ�վ�Ϊ��
    // {
    //     return false;
    // }

    // if (root->val == subRoot->val)			//����ͬ
    // {
    //     if(isSameTree(root,subRoot))
    //         return true;
    // }

    // if(root->left != NULL 
    //     && root->left->val == subRoot->val 
    //     && root->right !=NULL)      //��������ߣ�Ҫ��֤�����Ҳ�Ϊ�գ���ֹҰָ��
    // {
    //     if(isSameTree(root->left,subRoot))      //Ϊ��ֱ�ӷ��أ���Ϊ���������Ѱ��
    //         return true;

    // }
    // if(root->right != NULL 
    //     && root->right->val == subRoot->val 
    //     && root->left !=NULL)      //��
    // {
    //     if(isSameTree(root->right,subRoot))
    //         return true;
    // }
    if (root == NULL)
    {
        return false;
    }

    if (isSameTree(root, subRoot))       //ֱ���ж�ÿ���ڵ���Ϊ���������Ƿ���ͬ����ͬ���¼�����ֱ��Ϊ�շ��ؼ�
        return true;

    return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);   //�������߶�Ҫ��
}

int main()
{

}
/*编一个程序，读入用户输入的一串先序遍历字符串，
根据此字符串建立一个二叉树（以指针方式存储）。 
例如如下的先序遍历字符串： ABC##DE#G##F### 
其中“#”表示的是空格，空格字符代表空树。
建立起此二叉树以后，再对二叉树进行中序遍历，
输出遍历结果。*/



#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}TN;

TN* CreateTree(char* str, int* pi)        //建树
{
    if (str[*pi] == '#')
    {
        (*pi)++;                //还是要加一下，数组向后移一位
        return NULL;
    }
    TN* head = (TN*)malloc(sizeof(TN));        //造根
    //先左树，后右树
    head->val = str[(*pi)];                    //建树还是中左右
    (*pi)++;                                    //不用每次都加，自己在递归中就加过了
    head->left = CreateTree(str, pi);
    head->right = CreateTree(str, pi);

    return head;
}

void Print(TN* head)        //中序
{
    if (head == NULL)
        return;
    Print(head->left);
    printf("%c ", head->val);
    Print(head->right);

}

int main()
{
    char str[100];

    scanf("%s", str);            //%s 接受字符串

    int i = 0;
    TN* tree = CreateTree(str, &i);

    Print(tree);

    printf("\n");

    return 0;
}
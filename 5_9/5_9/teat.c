/*��һ�����򣬶����û������һ����������ַ�����
���ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� 
�������µ���������ַ����� ABC##DE#G##F### 
���С�#����ʾ���ǿո񣬿ո��ַ����������
������˶������Ժ��ٶԶ������������������
������������*/



#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}TN;

TN* CreateTree(char* str, int* pi)        //����
{
    if (str[*pi] == '#')
    {
        (*pi)++;                //����Ҫ��һ�£����������һλ
        return NULL;
    }
    TN* head = (TN*)malloc(sizeof(TN));        //���
    //��������������
    head->val = str[(*pi)];                    //��������������
    (*pi)++;                                    //����ÿ�ζ��ӣ��Լ��ڵݹ��оͼӹ���
    head->left = CreateTree(str, pi);
    head->right = CreateTree(str, pi);

    return head;
}

void Print(TN* head)        //����
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

    scanf("%s", str);            //%s �����ַ���

    int i = 0;
    TN* tree = CreateTree(str, &i);

    Print(tree);

    printf("\n");

    return 0;
}
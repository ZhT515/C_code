#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
第一行输入一个整数\mathit nn 表示任务数目。
第二行\mathit nn个以空格分隔的整数，表示不同的任务难度。

输出\mathit nn行，表示牛牛每次收到任务后的完成任务情况。如果牛牛什么也没做，就输出-1，否则的话，输出5个整数，分别表示牛牛完成难度为\text 1,2,3,4,51,2,3,4,5的五个任务编号。
*/


int main()
{
    int n, n1 = 0;
    scanf("%d", &n);
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    int i4 = 0;
    int i5 = 0;
    int count[6] = { 0 };
    int* arr = (int*)malloc(sizeof(int) * n);
    int* arr1 = (int*)malloc(sizeof(int) * n);
    int* arr2 = (int*)malloc(sizeof(int) * n);
    int* arr3 = (int*)malloc(sizeof(int) * n);
    int* arr4 = (int*)malloc(sizeof(int) * n);
    int* arr5 = (int*)malloc(sizeof(int) * n);
    while (n1 < n)                    //输入
    {
        scanf("%d", &arr[n1]);
        n1++;
    }
    int i = 0;
    while (i < n)
    {
        if (arr[i] == 1)
        {
            arr1[i1] = i + 1;
            i1++;
        }
        else if (arr[i] == 2)
        {
            arr2[i2] = i + 1;
            i2++;
        }
        else if (arr[i] == 3)
        {
            arr3[i3] = i + 1;
            i3++;
        }
        else if (arr[i] == 4)
        {
            arr4[i4] = i + 1;
            i4++;
        }
        else
        {
            arr5[i5] = i + 1;
            i5++;
        }
        if (i1 && i2 && i3 && i4 && i5)
        {
            printf("%d %d %d %d %d\n", arr1[i1 - 1], arr2[i2 - 1], arr3[i3 - 1], arr4[i4 - 1], arr5[i5 - 1]);
            i1--;
            i2--;
            i3--;
            i4--;
            i5--;
        }
        else
        {
            printf("-1\n");
        }
        i++;
    }
}
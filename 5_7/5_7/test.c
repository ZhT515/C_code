#include<stdio.h>

/****************ʵ�� int sqrt(int x) ����*******************/
//1.����
//2.����
//3.���ֲ���

int mySqrt(int x)       //1.���������취 ���Ի��ɶ��ֲ���
{
    if (x == 0)
    {
        return 0;
    }

    long long i = 0;
    //if (x >= 1)                           //int �������С��
    //{
    for (i = 0; i > -1; i++)
    {
        if ((i - 1) * (i - 1) <= x && i * i >= x)
        {
            break;
        }
    }
    //}
    //else
    //{
    //    for (i = 0; i > -1; i--)
    //    {
    //        if ((i - 1) * (i - 1) <= x && i * i >= x)
    //        {
    //            break;
    //        }
    //    }
    //}
    if (i * i == x)
        return i;
    else
        return i - 1;

}

int main()
{

}
#include<stdio.h>

/****************实现 int sqrt(int x) 函数*******************/
//1.遍历
//2.对数
//3.二分查找

int mySqrt(int x)       //1.遍历，笨办法 可以换成二分查找
{
    if (x == 0)
    {
        return 0;
    }

    long long i = 0;
    //if (x >= 1)                           //int 不会出现小数
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
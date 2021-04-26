#include<stdio.h>
#include<stdlib.h>

/*
在新的一年，牛牛想跳得更高。牛牛本身可以跳高{h}h米。同时牛牛有{n}n颗跳高弹，使用第{i}i颗跳高弹可以使牛牛跳高高度增加a_ia
i
?
 米，且跳高弹的效果是可以叠加的，也就是说如果牛牛使用多颗跳高弹，那么他的跳高高度将会增加这些跳高弹单个效果的和。

每颗跳高弹只能使用一次。

请问牛牛最少需要使用多少个跳高弹，才能让牛牛的高度至少是{u}u米高呢？

数据保证答案存在。
*/

int main()
{
	int n, h, u, a, n1 = 0;
	scanf("%d %d %d", &n, &h, &u);
	int* arr = (int*)malloc(sizeof(int) * n);;
	while (n1 < n)        //输入
	{
		scanf("%d", &arr[n1]);
		n1++;
	}

	sort(arr, n);
	if (h > u)
	{
		printf("0");
	}
	else
	{
		int n2 = n;
		int hu = h;
		int ret = 0;
		while (n2 > 0)
		{
			n2--;
			hu += arr[n2];
			ret++;
			if (hu >= u)
			{
				printf("%d", ret);
				break;
			}
		}
	}
	return 0;
}
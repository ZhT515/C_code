#include<stdio.h>
#include<stdlib.h>

/*
���µ�һ�꣬ţţ�����ø��ߡ�ţţ�����������{h}h�ס�ͬʱţţ��{n}n�����ߵ���ʹ�õ�{i}i�����ߵ�����ʹţţ���߸߶�����a_ia
i
?
 �ף������ߵ���Ч���ǿ��Ե��ӵģ�Ҳ����˵���ţţʹ�ö�����ߵ�����ô�������߸߶Ƚ���������Щ���ߵ�����Ч���ĺ͡�

ÿ�����ߵ�ֻ��ʹ��һ�Ρ�

����ţţ������Ҫʹ�ö��ٸ����ߵ���������ţţ�ĸ߶�������{u}u�׸��أ�

���ݱ�֤�𰸴��ڡ�
*/

int main()
{
	int n, h, u, a, n1 = 0;
	scanf("%d %d %d", &n, &h, &u);
	int* arr = (int*)malloc(sizeof(int) * n);;
	while (n1 < n)        //����
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
#include<stdio.h>
#include<math.h>
#include<limits.h>		//����INT_MAX

int reverse(int x) 
{
	long count = x;
	long newx = 0;		//��long��
	while (count)
	{
		newx = newx * 10 + count % 10;		//���ظ���
		count /= 10;
	}
	/*count = x;*/
	//while ((--n) >= 0)
	//{
	//	newx += count % 10 * pow(10, n);
	//	count /= 10;
	//}
	return newx > INT_MAX || newx < INT_MIN ? 0 : newx;		//�������С��,�Բ������ʽ�棬�������
}

int main()
{
	int x = -100000000000002;
	printf("%d",reverse(x));
}
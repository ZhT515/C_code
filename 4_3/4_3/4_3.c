#include<stdio.h>
#include<math.h>
#include<limits.h>		//引入INT_MAX

int reverse(int x) 
{
	long count = x;
	long newx = 0;		//用long存
	while (count)
	{
		newx = newx * 10 + count % 10;		//不必复杂
		count /= 10;
	}
	/*count = x;*/
	//while ((--n) >= 0)
	//{
	//	newx += count % 10 * pow(10, n);
	//	count /= 10;
	//}
	return newx > INT_MAX || newx < INT_MIN ? 0 : newx;		//和最大最小比,以补码的形式存，若大则大。
}

int main()
{
	int x = -100000000000002;
	printf("%d",reverse(x));
}
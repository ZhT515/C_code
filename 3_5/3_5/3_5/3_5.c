#include<stdio.h>
#include<math.h>

//Sn=a+aa+aaa+aaaa+aaaaa的前5项之和
void Sn()
{
	int a = 2;
	int n = 10;
	int num;
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		arr[i] = a * pow(n, i);
	}
	num = 5 * arr[0] + 4 * arr[1] + 3 * arr[2] + 2 * arr[3] + arr[4];
	printf("%d", num);

}

void cock()		//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
{
	int n,num;
	int key = 1;
	int RMB = 20;
	int LS = 1;
	int ping = RMB / LS;
	int kping = RMB / LS;;

	while (kping > 1)
	{
		if (kping % 2 == 1)
		{
			ping = kping / 2 + ping;
			kping = kping / 2 + 1;
		}
		else
		{
			ping = kping / 2 + ping;
			kping = kping / 2;
		}
	}
	printf("%d", ping);
}

int main()
{
	//Sn();
	cock();
}
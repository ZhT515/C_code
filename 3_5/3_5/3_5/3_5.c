#include<stdio.h>
#include<math.h>

//Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮��
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

void cock()		//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
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
#include<stdio.h>

int man()
{
	int i;
	int man[4] = { 0 };			//Ĭ�϶��޷���
	for (i = 0; i < 4; i++)
	{
		man[i] = 1;			//���跸��
		if ((man[0] != 1) + 
			(man[2] == 1) + 
			(man[3] == 1) + 
			(man[3] != 1) == 3 )		//�������ǵ����ԣ�����Ϊ�漴��
		{
			break;
		}
		man[i] = 0;
	}
	putchar('A' + i);
}

//void 

int main()
{
	man();
}
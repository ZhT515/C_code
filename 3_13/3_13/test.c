#include<stdio.h>

int man()
{
	int i;
	int man[4] = { 0 };			//默认都无犯罪
	for (i = 0; i < 4; i++)
	{
		man[i] = 1;			//假设犯罪
		if ((man[0] != 1) + 
			(man[2] == 1) + 
			(man[3] == 1) + 
			(man[3] != 1) == 3 )		//翻译他们的语言，三个为真即可
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
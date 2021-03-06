#include<stdio.h>

void Reverse(char *a)
{
	char* left = a;
	char* right = a + strlen(a) - 1;		//ср╤к
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		++left;
		--right;
	}
}

int my_strlen(char * aaa)
{
	char* end = aaa;
	while (*end++);
	return (end - aaa -1);
}

char * my_strcpy(char *a,char*b)
{
	char* cp = b;
	while (*cp++ = *a++);
	return(b);
}

void Sequence()
{
	int arr[10] = {2,1,8,4,6,0,3,7,9,5};
	int left = 0;
	int right = 9;
	int tmp = 0;

	while (left < right)
	{
		while ((left < right) && (arr[left] % 2 == 1))
		{
			left++;
		}

		while ((left < right) && (arr[right] % 2 == 0))
		{
			right--;
		}

		if (left < right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int a = 0;
	char arr[] = "hello CHD";
	char abb[100] = {0};
	Reverse(arr);
	printf("%s\n",arr);
	a = my_strlen(arr);
	printf("%d", a);
	printf("%s\n", my_strcpy(arr, abb));
	Sequence();
	return 0;
}
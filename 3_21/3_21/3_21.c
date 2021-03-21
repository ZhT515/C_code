#include<stdio.h>

void Dogs(int * arr,int n)
{
	int i, j;
	int arr1[2] = { 0 };
	for (i = 0; i < n; i++)
	{
		int count = 0;
		for (j = 0; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count != 2)
			printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[10] = { 1,5,3,9,7,5,9,1,7,2 };
	Dogs(arr, sizeof(arr) / sizeof(arr[0]));
}
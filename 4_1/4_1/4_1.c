#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) //数组形式的整数加法	
{
	int BSize = 0;
	int	K2 = K;
	int a = 0;
	int carry = 0;
	*returnSize = ASize;
	while (K2)          //取K的长度
	{
		BSize++;
		K2 = K2 / 10;
	}
	int i = ASize > BSize ? ASize : BSize;      //判断哪个更长
	if (ASize < BSize)                       //若B大于A 则将A扩容
	{
		int* newB = (int*)realloc(A, sizeof(A[0]) * BSize);  //扩容
		if (newB != NULL)
		{
			A = newB;
			*returnSize = BSize;
			int jj = 1;
			for (int j = ASize - 1; j >= 0; j--)        //将扩容后的内容移到最后，前面补零
			{

				A[BSize - jj] = A[j];
				jj++;
			}
			for (int j = 0; j <= BSize - jj; j++)   //补零
			{
				A[j] = 0;
			}
			ASize = BSize;                              //要将A的长度及时更新，以备后续操作
		}
	}
	for (i -= 1; i >= 0; i--)
	{
		a = K % 10;                         //取个位
		K /= 10;
		A[i] = A[i] + a + carry;            //求自己+个位+进位
		carry = 0;                          //加完进位符号置零
		if (A[i] / 10 != 0)                 //通过取余判断是否产生进位
		{
			carry = 1;                      //进位符号置1
			A[i] %= 10;                     //取余
			if (i == 0)                     //如果为头部，则进行扩容
			{
				int* newA = (int*)realloc(A, sizeof(A[0]) * (ASize + 1));
				if (newA != NULL)
				{
					A = newA;
					for (int j = ASize - 1; j >= 0; j--)
					{
						A[j + 1] = A[j];
					}
					A[0] = 1;
					(*returnSize)++;
				}

			}
		}
	}
	return A;
}

int* addToArrayForm2(int* A, int ASize, int K, int* returnSize)				//16位以内
{
	int BSize = 0;
	long long K2 = 0;
	long long	K1 = 0;
	int a = 0;

	*returnSize = ASize;

	for (int i = 0; i < ASize; i++)
	{
		int n = ASize - 1 - i;
		K1 += A[i] * pow(10, n);
	}

	K2 = K1 + K;

	while (K2)          //取K的长度
	{
		BSize++;
		K2 = K2 / 10;
	}
	K2 = K1 + K;

	if (ASize != BSize)
	{
		int* newA = (int*)realloc(A, sizeof(A[0]) * BSize);
		if (newA != NULL)
		{
			A = newA;
			*returnSize = BSize;
		}
	}
	int j = BSize;
	for (j -= 1; j >= 0; j--)
	{

		a = K2 % 10;                         //取个位
		K2 /= 10;
		A[j] = a;
	}
	return A;
}


int main()
{
	//int nums1[6] = { 4, 5, 6, 0, 0, 0 }, m = 3, nums2[3] = { 1, 2, 3 }, n = 3;
	//merge(nums1, 6, m, nums2, 3, n);
	int nums[2] = { 1,2 }, k = 2;
	rotate2(nums, 2, 2);
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) //������ʽ�������ӷ�	
{
	int BSize = 0;
	int	K2 = K;
	int a = 0;
	int carry = 0;
	*returnSize = ASize;
	while (K2)          //ȡK�ĳ���
	{
		BSize++;
		K2 = K2 / 10;
	}
	int i = ASize > BSize ? ASize : BSize;      //�ж��ĸ�����
	if (ASize < BSize)                       //��B����A ��A����
	{
		int* newB = (int*)realloc(A, sizeof(A[0]) * BSize);  //����
		if (newB != NULL)
		{
			A = newB;
			*returnSize = BSize;
			int jj = 1;
			for (int j = ASize - 1; j >= 0; j--)        //�����ݺ�������Ƶ����ǰ�油��
			{

				A[BSize - jj] = A[j];
				jj++;
			}
			for (int j = 0; j <= BSize - jj; j++)   //����
			{
				A[j] = 0;
			}
			ASize = BSize;                              //Ҫ��A�ĳ��ȼ�ʱ���£��Ա���������
		}
	}
	for (i -= 1; i >= 0; i--)
	{
		a = K % 10;                         //ȡ��λ
		K /= 10;
		A[i] = A[i] + a + carry;            //���Լ�+��λ+��λ
		carry = 0;                          //�����λ��������
		if (A[i] / 10 != 0)                 //ͨ��ȡ���ж��Ƿ������λ
		{
			carry = 1;                      //��λ������1
			A[i] %= 10;                     //ȡ��
			if (i == 0)                     //���Ϊͷ�������������
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

int* addToArrayForm2(int* A, int ASize, int K, int* returnSize)				//16λ����
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

	while (K2)          //ȡK�ĳ���
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

		a = K2 % 10;                         //ȡ��λ
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
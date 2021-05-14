#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 4, 2, 7, 1, 9, 8, 10, 3, 5 ,6};
	InsertSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 4, 2, 7, 1, 9, 8, 10, 3, 5 ,6 };
	ShellSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	int a[] = { 4, 2, 7, 1, 9, 8, 10, 3, 5 ,6 };
	SelectSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestHeapSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	HeapSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestBubbleSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestQuickSortSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	QuickSort(a, 0,sizeof(a) / sizeof(int)-1);
	Print(a, sizeof(a) / sizeof(int));
}

void TestQuickSortNonR()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
	Print(a, sizeof(a) / sizeof(int));
}

void TestMergeSrt()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	MergeSrt(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestMergeSrtNonR()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	MergeSrtNonR(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestCountSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	CountSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestOP()					//时间测试
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

	int begin1 = clock();		//此刻时间
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	QuickSort(a3, 0, N - 1);
	int end3 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("InsertSort:%d\n", end2 - begin2);

}

int main()
{
	TestCountSort();
}
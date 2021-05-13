#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include"Stack.h"

// 排序实现的接口

void Print(int* a, int n);				//打印

void InsertSort(int* a, int n);			//插入排序

void ShellSort(int* a, int n);			// 希尔排序

void SelectSort(int* a, int n);			// 选择排序

void AdjustDown(int* a, int n, int root);	//重建大堆
void HeapSort(int* a, int n);			// 堆排序

// 冒泡排序
void BubbleSort(int* a, int n);

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right);

// 快速排序挖坑法
int PartSort2(int* a, int left, int right);

// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int begin, int end);

//非递归
void QuickSortNonR(int* a, int begin, int end);

//归并
void MergeSrt(int* a, int n);

//归并,非递归
void MergeSrtNonR(int* a, int n);
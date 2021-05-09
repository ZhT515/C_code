#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

// 排序实现的接口

void Print(int* a, int n);				//打印

void InsertSort(int* a, int n);			//插入排序

void ShellSort(int* a, int n);			// 希尔排序

void SelectSort(int* a, int n);			// 选择排序

void AdjustDown(int* a, int n, int root);	//重建大堆
void HeapSort(int* a, int n);			// 堆排序
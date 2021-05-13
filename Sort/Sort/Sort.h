#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include"Stack.h"

// ����ʵ�ֵĽӿ�

void Print(int* a, int n);				//��ӡ

void InsertSort(int* a, int n);			//��������

void ShellSort(int* a, int n);			// ϣ������

void SelectSort(int* a, int n);			// ѡ������

void AdjustDown(int* a, int n, int root);	//�ؽ����
void HeapSort(int* a, int n);			// ������

// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right);

// ���������ڿӷ�
int PartSort2(int* a, int left, int right);

// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int begin, int end);

//�ǵݹ�
void QuickSortNonR(int* a, int begin, int end);

//�鲢
void MergeSrt(int* a, int n);

//�鲢,�ǵݹ�
void MergeSrtNonR(int* a, int n);
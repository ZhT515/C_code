#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

// ����ʵ�ֵĽӿ�

void Print(int* a, int n);				//��ӡ

void InsertSort(int* a, int n);			//��������

void ShellSort(int* a, int n);			// ϣ������

void SelectSort(int* a, int n);			// ѡ������

void AdjustDown(int* a, int n, int root);	//�ؽ����
void HeapSort(int* a, int n);			// ������
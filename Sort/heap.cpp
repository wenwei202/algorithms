#include "Heap.h"
#include "stdafx.h"
#include "common.h"

int inline LeftIdx(int i)
{
 return 2*i+1;
}

int inline RightIdx(int i)
{
 return 2*i+2;
}

void maxHeapify(int *data_in,int length,int idx)//ά�����ѣ�idx��������Ϊ���ѣ���idx�������ά��������Ϊ����
{
	int largestIdx=idx;
	if (LeftIdx(idx)<length && data_in[LeftIdx(idx)]>data_in[idx])
		largestIdx = LeftIdx(idx);

	if (RightIdx(idx)<length && data_in[RightIdx(idx)]>data_in[largestIdx])
		largestIdx = RightIdx(idx);

	if (largestIdx != idx)
	{
		XCHG(data_in[largestIdx],data_in[idx],int);
		maxHeapify(data_in,length,largestIdx);
	}	

}

void buildMaxHeap(int *data_in,int length)//���������г�����
{
	for (int i=length/2-1;i>=0;i--)
	{
		maxHeapify(data_in,length,i);
	}
}

void heapSort(int *data_in,int length)//������
{
	buildMaxHeap(data_in,length);
	for (int i=length-1;i>0;i--)
	{
		XCHG(data_in[0],data_in[i],int);
		maxHeapify(data_in,length-(length-i),0);
	}
}

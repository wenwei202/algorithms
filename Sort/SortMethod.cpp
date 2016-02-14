#include "stdafx.h"
#include "SortMethod.h"
#include "common.h"
#include <stdlib.h>
//int test=0;

//快速排序
void quickSort2(int *array_in,int length)
{
//	int nextIdx;
	int partitionIdx;
//	partitionIdx = -1;
// 	printf("call times:%d\n",++test);
// 	if (test==14481)
// 	{
// 		printf("breakpoint\n");
// 	}
	if (length>1)
	{
// 		for (nextIdx=0;nextIdx<length-1;nextIdx++)
// 		{
// 			if (array_in[nextIdx]<array_in[length-1])
// 			{
// 				partitionIdx++;
// 				XCHG(array_in[nextIdx],array_in[partitionIdx],int);
// 			}
// 		}
// 		XCHG(array_in[partitionIdx+1],array_in[length-1],int);
		partitionIdx = partition(array_in,length);//减少栈占用空间
		quickSort2(array_in,partitionIdx);
		quickSort2(array_in+partitionIdx+1,length-partitionIdx-1);
	}
}

//随机化快速排序
void randQuickSort(int *array_in,int length)
{
	int nextIdx;
	int partitionIdx;
	partitionIdx = -1;
	if (length>1)
	{
		XCHG(array_in[length-1],array_in[rand()%length],int);
		for (nextIdx=0;nextIdx<length-1;nextIdx++)
		{
			if (array_in[nextIdx]<array_in[length-1])
			{
				partitionIdx++;
				XCHG(array_in[nextIdx],array_in[partitionIdx],int);
			}
		}
		XCHG(array_in[partitionIdx+1],array_in[length-1],int);
		randQuickSort(array_in,partitionIdx+1);
		randQuickSort(array_in+partitionIdx+2,length-partitionIdx-2);
	}
}


int partition(int *array_in,int length)
{
	int nextIdx;
	int partitionIdx;
	partitionIdx = -1;
	for (nextIdx=0;nextIdx<length-1;nextIdx++)
	{
		if (array_in[nextIdx]<array_in[length-1])
		{
			partitionIdx++;
			XCHG(array_in[nextIdx],array_in[partitionIdx],int);
		}
	}
	XCHG(array_in[partitionIdx+1],array_in[length-1],int);
	return partitionIdx+1;//分割元素索引
}

//TAIL-RECURSIVE-QUICKSORT
void tailRecurQuickSort(int *array_in,int length)
{
	int partitionIdx=-1;
	int subPartitionIdx;
	if (length>1)
	{
		while (partitionIdx<length-2)
		{
			subPartitionIdx = partition(array_in+partitionIdx+1,length-partitionIdx-1);
			partitionIdx += (subPartitionIdx+1);
			tailRecurQuickSort(array_in+partitionIdx-subPartitionIdx,subPartitionIdx);
		}
		
	}
	
}

//输入为整数，范围为0-k
void countingSort(int *array_in,int length,int k,int *array_out)
{
	int i;
	int *counter = (int *)malloc(sizeof(int)*(k+1));//new int[k+1];
	for (i=0;i<=k;i++)
	{
		counter[i]=0;
	}

	for (i=0;i<length;i++)
	{
		counter[ array_in[i] ]++;
	}

	for (i=1;i<=k;i++)
	{
		counter[i] += counter[i-1];
	}

	for (i=length-1;i>=0;i--)
	{
		array_out[counter[array_in[i]]-1] = array_in[i];
		counter[array_in[i]]--;
	}

	//delete [] counter;
	free(counter);
}

void radixSort(int *array_in,int length,int digit,int *array_out)
{
	int d;
	int i;
	const int radixSize = 16;
	int *counter = (int *)malloc(sizeof(int)*(radixSize));
	for (d=0;d<digit;d++)
	{
		
		for (i=0;i<=radixSize-1;i++)
		{
			counter[i]=0;
		}
		
		for (i=0;i<length;i++)
		{
			counter[ (array_in[i]>>(d<<2))&0xf ]++;
		}
		
		for (i=1;i<=radixSize-1;i++)
		{
			counter[i] += counter[i-1];
		}
		
		for (i=length-1;i>=0;i--)
		{
			array_out[counter[ (array_in[i]>>(d<<2))&0xf ]-1] = array_in[i];
			counter[ (array_in[i]>>(d<<2))&0xf ]--;
		}

		for (i=length-1;i>=0;i--)
		{
			array_in[i]=array_out[i];
		}
		
	}
	free(counter);
}
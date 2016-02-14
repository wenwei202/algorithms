// Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>
#include <stdlib.h>
#include "common.h"
#include "Heap.h"
#include "SortMethod.h"

#define LENGTH 10000
void selectSort(int *array_in,int length_in);
int testSort(int *array_in,int length_in);
void mergeSort(int *array_in,int length_in);
int binarySearch(int *array_in,int length_in,int target);
void quickSort(int *array_in,int length_in);

int main(int argc, char* argv[])
{
	//printf("Hello World!\n");
	int i=0;
	int digit;
	int tmp;
	int *m_array =(int *)malloc(sizeof(int)*LENGTH);
	int *m_array_out =(int *)malloc(sizeof(int)*LENGTH);
	if (m_array==0  || m_array_out==0)
	{
		printf("内存空间不够%d字节\n",LENGTH);
		return 0;	
	} 
	else
	{
		for (i=0;i<LENGTH;i++)
		{
			m_array[i]=rand()%LENGTH;
			//m_array[i]=LENGTH-i;
			//m_array[i]=i;
			//printf("%d ",m_array[i]);

		}

		//selectSort(m_array,LENGTH);
		//mergeSort(m_array,LENGTH);
		//quickSort(m_array,LENGTH);
		//heapSort(m_array,LENGTH);
		//quickSort2(m_array,LENGTH);
		//tailRecurQuickSort(m_array,LENGTH);
		//randQuickSort(m_array,LENGTH);
		//countingSort(m_array,LENGTH,LENGTH-1,m_array_out);
		tmp=LENGTH-1;
		digit=0;
		while (tmp>0)
		{
			tmp=tmp>>4;
			digit++;
		}
		radixSort(m_array,LENGTH,digit,m_array_out);

		
// 		printf("\n");
// 		for (i=0;i<LENGTH;i++)
// 		{
// 			printf("%d ",m_array[i]);
// 		}
// 		printf("\n");
	

		testSort(m_array,LENGTH);
		//testSort(m_array_out,LENGTH);
		
// 		for (i=0;i<LENGTH;i++)
// 		{
// 			printf("binarySearch idx: %d\n",binarySearch(m_array,LENGTH,m_array[i]));
// 		}
// 		printf("binarySearch idx: %d\n",binarySearch(m_array,LENGTH,-11));

		free(m_array);
		free(m_array_out);
		return 0;
	}

}

//直接选择排序
void selectSort(int *array_in,int length_in)
{
	int i=0,j=0;
	int min_idx;
	for (i=0;i<length_in-1;i++)
	{
		min_idx=i;
		for (j=i+1;j<length_in;j++)
		{
			if (array_in[j]<array_in[min_idx])
			{
				min_idx=j;
			}
		}

		if (i!=min_idx)
		{
			array_in[i] += array_in[min_idx];
			array_in[min_idx] = array_in[i] - array_in[min_idx];
			array_in[i] -= array_in[min_idx];

		}

	}
}

//测试排序结果是否为升序
int testSort(int *array_in,int length_in)
{
	for (int i=0;i<length_in-1;i++)
	{
		if (array_in[i]>array_in[i+1])
		{
			printf("fail to sort!\n");
			return 0;
		}
	}
	printf("success to sort!\n");
	return 1;
		
}

//归并排序调用函数：将已升序排列完毕的2个子序列合并为1个升序序列
void merge(int *array_in,int idxStart,int idxMid,int idxEnd)
{
	int i;
	int idxLeft,idxRight;
	int b_leftOverflow,b_rightOverflow;
	int *arrayLeft = (int *)malloc( (idxMid-idxStart+1)*sizeof(int) );
	int *arrayRight = (int *)malloc( (idxEnd-idxMid)*sizeof(int) );
	for (i=0;i<idxMid-idxStart+1;i++)
	{
		arrayLeft[i]=array_in[idxStart+i];
	}
	for (i=0;i<idxEnd-idxMid;i++)
	{
		arrayRight[i]=array_in[idxMid+1+i];
	}

	idxLeft=0;
	idxRight=0;
	b_leftOverflow = 0;
	b_rightOverflow = 0;
	for (i=idxStart;i<=idxEnd;i++)
	{

		if ((b_leftOverflow==0) && (b_rightOverflow == 0))
		{
			if (  (arrayLeft[idxLeft]<arrayRight[idxRight]) )
			{
				array_in[i]=arrayLeft[idxLeft];
				if ( ++idxLeft > (idxMid-idxStart) )
				{
					b_leftOverflow=1;
				}
				
			} 
			else //if(b_rightOverflow == 0)
			{
				array_in[i]=arrayRight[idxRight];
				if(++idxRight >= (idxEnd-idxMid) )
					b_rightOverflow=1;
			}
		} 
		else
		{
			if (b_leftOverflow)
			{
				array_in[i]=arrayRight[idxRight++];
			} 
			else
			{
				array_in[i]=arrayLeft[idxLeft++];
			}
		}
		
		//else 
		//	printf("error!\n\n");
	}


	free(arrayLeft);
	free(arrayRight);
}

//归并排序
void mergeSort(int *array_in,int length_in)
{
	int idxMid=0;
	if (length_in>1)
	{
		idxMid=(length_in-1)/2;
		mergeSort(array_in,idxMid+1);
		mergeSort(array_in+idxMid+1,length_in-idxMid-1);
		merge(array_in,0,idxMid,length_in-1);

	}
	
}

//二分法搜索 递归形式
int binarySearch(int *array_in,int length_in,int target)
{
	int idxMid = (length_in-1)/2;
	int subSearchResult;
	if (array_in[idxMid]==target)
	{
		return idxMid;
	} 
	else if(array_in[idxMid]<target)
	{
		if (length_in-idxMid-2 >= 0)
		{
			subSearchResult = binarySearch(array_in+idxMid+1,length_in-idxMid-2+1,target);			
			return subSearchResult==-1?-1:idxMid+1+subSearchResult;
		} 
		else
		{
			return -1;
		}
	} else	{
				if (idxMid-1 >= 0)
				{
					//subSearchResult = binarySearch(array_in,idxMid,target);
					return binarySearch(array_in,idxMid,target);
				} 
				else
				{
					return -1;
				}
	}
}

//快速排序
void quickSort(int *array_in,int length_in)
{
	int i=0;
	int idxTarget,idxNext;

	if (length_in>=2)
	{
		idxTarget=0;
		idxNext=length_in-1;
		for (i=0;i<length_in-1;i++)
		{
			if (idxNext<idxTarget)
			{
				if (array_in[idxNext]>array_in[idxTarget])
				{
					XCHG(array_in[idxNext],array_in[idxTarget],int);
					XCHG(idxNext,idxTarget,int);
					idxNext--;
				}
				else idxNext++;
			} 
			else if(idxNext>idxTarget)
			{
				if (array_in[idxNext]<array_in[idxTarget])
				{
					XCHG(array_in[idxNext],array_in[idxTarget],int);
					XCHG(idxNext,idxTarget,int);
					idxNext++;
				}
				else idxNext--;
			} else
			{
				printf("error\n");
			}
		}

		quickSort(array_in,idxTarget);
		quickSort(array_in+idxTarget+1,length_in-idxTarget-1);
	} 

}
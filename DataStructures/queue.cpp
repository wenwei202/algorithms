#include "stdafx.h"
#include "queue.h"
#include <stdlib.h>

Queue *creatQueue(int size)
{
	Queue *s;
	s=(Queue *)malloc(sizeof(Queue));
	s->datas=(int *)malloc(sizeof(int)*size);
	s->size=size;
	s->headIdx=0;
	s->tailIdx=0;
	return s;
}

int freeQueue(Queue *s)
{
	free(s->datas);
	free(s);
	return 0;
}

int enQueue(Queue *s,int data)//入队
{
	if (isFull(s))
	{
		printf("full\n");
		return 0;
	} 
	else
	{
		s->datas[s->tailIdx]=data;
		s->tailIdx=(s->tailIdx+1)%s->size;
		return  1;
	}
}

int deQueue(Queue *s)//出队
{
	int result;
	if (isEmpty(s))
	{
		printf("empty\n");
		result=0;
	} 
	else
	{
		result=s->datas[s->headIdx];
		s->headIdx = (s->headIdx+1)%s->size;
	}
	return result;
}

int isEmpty(Queue *s)
{
	return s->headIdx==s->tailIdx;
}

int isFull(Queue *s)
{
	return s->headIdx == ( (s->tailIdx+1)%s->size );
}

// int cycleAdd(int data,int size)
// {
// 	return data==size-1 ? 0 : size+1;
// }
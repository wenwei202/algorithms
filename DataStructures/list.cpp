#include "stdafx.h"
#include "list.h"
#include <stdio.h>

void DoubleList::deleteNode(DoubleNode *x)
{
	if (x!=0)
	{
		if (x->leftNode!=0)
		{
			x->leftNode->rightNode=x->rightNode;
		}else
		{
			DoubleList::head=x->rightNode;
		}
		
		if (x->rightNode!=0)
		{
			x->rightNode->leftNode=x->leftNode;
		}
	}
	
}

void DoubleList::insertNode(DoubleNode *x)
{
	x->leftNode = 0;
	if (head!=0)
	{
		head->leftNode=x;
		x->rightNode = head;
	}else
	{
		x->rightNode=0;
	}
	head=x;
	
	
}

DoubleNode *DoubleList::searchNode(int key)
{
	DoubleNode *matchNode=head;
	while (matchNode!=0 && matchNode->key!=key)
	{
		matchNode = matchNode->rightNode;
	}
	return matchNode;
	
}


void DoubleList::printList()
{
	DoubleNode *node=head;
	while (node!=0)
	{
		printf("=%d=",node->key);
		node=node->rightNode;
	}
	printf("\n");
}
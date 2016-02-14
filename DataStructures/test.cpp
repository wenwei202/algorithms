#include "stdafx.h"
#include "test.h"
#include "queue.h"
#include "list.h"
#include "hash.h"
#include "binSearchTree.h"

#include <stdlib.h>
#include <iostream>
using namespace std;
void testQueue()
{

	int i=0;
	Queue *q=creatQueue(LENGTH);
// 	if (isEmpty(q))
// 		printf("empty\n");
// 	else 
// 		printf("not empty\n");
	
// 	if (isFull(q))
// 		printf("full\n");
// 	else 
// 		printf("not full\n");
	
// 	for (i=0;i<LENGTH+10;i++)
// 	{
// 		enQueue(q,i);
// 
// // 		if (isEmpty(q))
// // 			printf("empty\n");
// // 		else 
// // 			printf("not empty\n");
// // 		
// // 		if (isFull(q))
// // 			printf("full\n");
// // 		else 
// // 			printf("not full\n");
// 	}
// 	for (i=0;i<LENGTH+10;i++)
// 	{
// 		printf("%d is dequeued\n",deQueue(q));
// 
// // 		if (isEmpty(q))
// // 			printf("empty\n");
// // 		else 
// // 			printf("not empty\n");
// // 		
// // 		if (isFull(q))
// // 			printf("full\n");
// // 		else 
// // 			printf("not full\n");
// 	}
	int j=0;
	while (j++<10)
	{
		for (i=0;i<15;i++)
		{
			enQueue(q,i);
		}

		for (i=0;i<rand()%30;i++)
		{
			printf("%d is dequeued\n",deQueue(q));
		}

	}
	freeQueue(q);

}
void testDoubleList()
{
	int i;
	DoubleList m_dblList;
	for (i=0;i<LENGTH;i++)
	{
		m_dblList.insertNode(new DoubleNode(i));//mem bug
		m_dblList.printList();
	}
	//m_dblList.searchNode(10);
	
	for (i=0;i<LENGTH;i++)
	{
		m_dblList.deleteNode(m_dblList.searchNode(i));
		m_dblList.printList();
	}
	
	
}

void testHashTable()
{
	HashTable m_hashTab_mod(10,MOD_HASH);
	HashTable m_hashTab_multi(200,MULTI_HASH);
	int i;
	for (i=0;i<20;i++)
	{
		m_hashTab_mod.insert(new DoubleNode(i));//mem bug		
	}
	m_hashTab_mod.printHashTable();

	for (i=0;i<20;i++)
	{
		m_hashTab_mod.hashDelete(m_hashTab_mod.search(i));		
	}
	m_hashTab_mod.printHashTable();

	


	for (i=0;i<200;i++)
	{
		m_hashTab_multi.insert(new DoubleNode(i));//mem bug		
	}
	m_hashTab_multi.printHashTable();

// 	for (i=0;i<20;i++)
// 	{
// 		m_hashTab_multi.hashDelete(m_hashTab_multi.search(i));
// 		m_hashTab_multi.printHashTable();
// 	}

}

void testBinSearchTree()
{
	int i;
	int tmp;
	BinSearchTree m_binTree(NULL);
	for (i=0;i<20;i++)
	{
		tmp=rand()%20;
		m_binTree.insert(new TreeNode(tmp));
		cout<<tmp<<" ";
	}
	cout<<endl;

	cout<<endl<<"tree is being drawn..."<<endl;
	m_binTree.printTree();
	cout<<"height is "<<m_binTree.height(m_binTree.rootNode)<<endl;
	

	cout<<endl<<endl<<"tree is being walked through..."<<endl;
	cout<<m_binTree.inOrderWalk()<<" element(s) has(ve) been walked through"<<endl;
	cout<<m_binTree.elementsNum<<" element(s) in this tree"<<endl;

	cout<<"min and max key in binary search tree is "
		<<m_binTree.minNode()->key
		<<" and "
		<<m_binTree.maxNode()->key
		<<endl;
// 	TreeNode *tmpNode=m_binTree.search(10);
 	
	const int testKey=7;
	TreeNode *mySuccessor=m_binTree.successor(m_binTree.search(testKey));
	TreeNode *myPredecessor=m_binTree.predecessor(m_binTree.search(testKey));
	if (mySuccessor)
	{
		cout<<"successor of "<<testKey<<" is "<<mySuccessor->key<<endl;
	} 
	else
	{
		cout<<testKey<<" is "<<"the largest or doesn't exsit?"<<endl;
	}

	if (myPredecessor)
	{
		cout<<"Predecessor of "<<testKey<<" is "<<myPredecessor->key<<endl;
	} 
	else
	{
		cout<<testKey<<" is "<<"the smallest or doesn't exsit?"<<endl;
	}


// 	cout<<endl<<"after transplant from 14 to 0:"<<endl;
// 	m_binTree.transplant(m_binTree.search(14),m_binTree.search(0));
// 	m_binTree.printTree();

// 	m_binTree.nodeDelete(m_binTree.search(14));
// 	m_binTree.printTree();
// 	m_binTree.nodeDelete(m_binTree.search(1));
// 	m_binTree.printTree();
	cout<<"-------------------------------------------"
		<<"-------------------------------------------"
		<<"-------------------------------------------"
			<<endl;
	cout<<"deleting root node one by one:"<<endl;
	while(m_binTree.elementsNum)
	{
		m_binTree.nodeDelete(m_binTree.rootNode);
		m_binTree.printTree();
		//m_binTree.inOrderWalk();
		cout<<"-------------------------------------------"
			<<"-------------------------------------------"
			<<"-------------------------------------------"
			<<endl;
	}
	
		

}
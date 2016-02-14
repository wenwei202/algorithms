#include "stdafx.h"
#include "binSearchTree.h"
#include "queue.h"
#include <iostream>
#include <math.h>
using namespace std;

void BinSearchTree::insert(TreeNode *x)//节点插入
{
	TreeNode *targetRoot=rootNode;
	TreeNode *parentRoot=NULL;
	int flags=-1;
	while(targetRoot != NULL)
	{
		parentRoot = targetRoot;
		if (targetRoot->key < x->key)
		{
			targetRoot = targetRoot->rightChild;
			flags=0;
		} 
		else
		{
			targetRoot = targetRoot->leftChild;
			flags=1;
		}
	}
	if (flags==-1)
	{
		rootNode = x;
	} 
	else if(flags == 0)
	{
		parentRoot->rightChild = x;
	}
	else if (flags == 1)
	{
		parentRoot->leftChild = x;
	} 
	else
	{
		cout<<"error during inserting"<<endl;
	}

	x->parent = parentRoot;
	x->leftChild = x->rightChild = NULL;
	elementsNum++;

}

int BinSearchTree::inOrderWalk()//按大小顺序访问 即中序遍历
{
	return inOrderWalk(rootNode);
}

int BinSearchTree::inOrderWalk(TreeNode *rootNode)
{
	int count=0;
	if (rootNode != NULL)
	{
		
		count += inOrderWalk(rootNode->leftChild);
		cout<< (rootNode->key) << endl;
		count++;
		count += inOrderWalk(rootNode->rightChild);
	}
	return count;
}

TreeNode *BinSearchTree::minNode()//key值最小节点
{
	TreeNode *min=rootNode;
	while(min!=NULL && min->leftChild!=NULL)
	{
		min = min->leftChild;
	}
	return min;
	
}
TreeNode *BinSearchTree::maxNode()//key值最大节点
{
	TreeNode *max=rootNode;
	while(max!=NULL && max->rightChild!=NULL)
	{
		max = max->rightChild;
	}
	return max;
}

TreeNode *BinSearchTree::minNode(TreeNode *rootNode)
{
	TreeNode *min=rootNode;
	while(min!=NULL && min->leftChild!=NULL)
	{
		min = min->leftChild;
	}
	return min;
	
}
TreeNode *BinSearchTree::maxNode(TreeNode *rootNode)
{
	TreeNode *max=rootNode;
	while(max!=NULL && max->rightChild!=NULL)
	{
		max = max->rightChild;
	}
	return max;
}

TreeNode *BinSearchTree::search(int key)//搜索key值的节点
{
	TreeNode *result=rootNode;
	while(result!=NULL && result->key!=key)
	{
		if (result->key < key)
		{
			result=result->rightChild;
		} 
		else
		{
			result=result->leftChild;
		}
	}
	return result;
}

TreeNode *BinSearchTree::successor(TreeNode *x)//大或等于x的最小节点
{
	if (x==NULL)
	{
		//cout<<"error: node with this key value does not exsit!"<<endl;
		return NULL;
	}
	if (x->rightChild)
		return minNode(x->rightChild);
	TreeNode *parent=x->parent;
	while(parent && (x->parent->rightChild==x))
	{
		x=parent;
		parent=parent->parent;
	}
	return parent;
}
	
TreeNode *BinSearchTree::predecessor(TreeNode *x)//小或等于x的最大节点
{
	if (x==NULL)
	{
		//cout<<"error: node with this key value does not exsit!"<<endl;
		return NULL;
	}
	if (x->leftChild)
		return maxNode(x->leftChild);
	TreeNode *parent=x->parent;
	while(parent && (x->parent->leftChild==x))
	{
		x=parent;
		parent=parent->parent;
	}
	return parent;
}

void BinSearchTree::printTree()//打印二叉树，注意屏幕宽度
{
	if (elementsNum)
	{
		int h=height(rootNode);
		Queue *q,*qNum;
		int crtNum;
		int deQueueNum,tmp=1;
		int x,xBegin=0,y=0,i;
		q=creatQueue(elementsNum+1);
		qNum=creatQueue(elementsNum+1);
		enQueue(q,(int)rootNode);
		enQueue(qNum,1);
		
		while(isEmpty(q)==0)
		{
			deQueueNum=tmp;
			tmp=0;
			xBegin=0;

			for (i=0;i<deQueueNum;i++)
			{
				crtNum=deQueue(qNum);
				x=(crtNum*2-1)*pow(2,h)-xBegin;
				goToLocation(x,0);
				xBegin+=x;
				int dataDeQueue=deQueue(q);
				
				cout<< ((TreeNode *)dataDeQueue)->key;
				if (   ((TreeNode *)dataDeQueue)->leftChild != NULL )
				{
					enQueue(   q,(int)( ((TreeNode *)dataDeQueue)->leftChild )   );
					enQueue(qNum,crtNum*2-1);
					tmp++;
				}
				if (((TreeNode *)dataDeQueue)->rightChild != NULL)
				{
					enQueue(   q,(int)( ((TreeNode *)dataDeQueue)->rightChild )   );
					enQueue(qNum,crtNum*2);
					tmp++;
				}
			}

			h--;
			y++;
			goToLocation(0,1);
		}

		freeQueue(q);
		freeQueue(qNum);
	}
	
		
}

void BinSearchTree::goToLocation(int x,int y)//光标偏移
{
	int i;

	for (i=0;i<y;i++)
	{
		cout<<endl;
	}	

	for (i=0;i<x;i++)
	{
		cout<<" ";
	}


}

int BinSearchTree::height(TreeNode *rootNode)//树高度
{
	int h1,h2;
	if (rootNode==NULL)
	{
		return -1;
	} 
	else
	{
		//if(rootNode->leftChild)
			h1 = 1+height(rootNode->leftChild);
		//if(rootNode->rightChild)
			h2=1+height(rootNode->rightChild);
		return (h1>h2 ? h1 : h2);
	}
}

void BinSearchTree::nodeDelete(TreeNode *x)//节点删除
{
	if(x==NULL)
		cout<<"error during deleting: no such node to be deleted"<<endl;
	else
	{
		if (x->leftChild==NULL)
			transplant(x->rightChild,x);
		else if(x->rightChild==NULL)
			transplant(x->leftChild,x);
		else
		{
			TreeNode *xSuccessor=successor(x);
			if (xSuccessor!=x->rightChild)
			{
				transplant(xSuccessor->rightChild,xSuccessor);
				xSuccessor->rightChild=x->rightChild;
				x->rightChild->parent=xSuccessor;
			}

			xSuccessor->leftChild=x->leftChild;
			x->leftChild->parent=xSuccessor;
			transplant(xSuccessor,x);
		}
		elementsNum--;
	}
}

void BinSearchTree::transplant(TreeNode *srcTree,TreeNode *dstNode)//用srcTree树替代dstNode为根节点的子树
{
	if (dstNode==NULL)
	{
		cout<<"error:no such Node";
	} 
	else
	{
		if (dstNode->parent)
		{
			if(dstNode->parent->leftChild==dstNode)
				dstNode->parent->leftChild=srcTree;
			else //(dstNode->parent->rightChild==dstNode)
				dstNode->parent->rightChild=srcTree;
		}
		else
			rootNode=srcTree;

		if(srcTree)
			srcTree->parent=dstNode->parent;
	}
}
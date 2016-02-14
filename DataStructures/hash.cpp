#include "stdafx.h"
#include "hash.h"
#include <iostream>
#include <math.h>

using namespace std;
HashTable::HashTable(int tabSize,HashFuncType funcType)
{
	int i;
	this->tabSize=tabSize;
	this->funcType=funcType;
	table=new DoubleList *[tabSize];
	for (i=0;i<tabSize;i++)
	{
		*(table+i)=new DoubleList();//指向空双向列表
	}
}

void HashTable::insert(DoubleNode *x)
{
	(*(table+getTableIdx(x->key)))->insertNode(x);
}

void HashTable::hashDelete(DoubleNode *x)
{
	if (x!=0)
	{
		(*(table+getTableIdx(x->key)))->deleteNode(x);
	}
	
}

DoubleNode *HashTable::search(int key)
{
	return (*(table+getTableIdx(key)))->searchNode(key);
}

void HashTable::printHashTable()
{
	int i;
	for (i=0;i<tabSize;i++)
	{
		(*(table+i))->printList();
		cout<<"|"<<endl;
	}
	cout<<"***********************************"<<endl;
}

int HashTable::getTableIdx(int key)//获取元素在哈希表中存放位置的索引
{
	if (funcType==MOD_HASH)
		return key%tabSize;
	else if(funcType==MULTI_HASH)
		return floor( tabSize*(0.6180339887*key-floor(0.6180339887*key)) );
	else 
	{
		cout<<"error: an unknown hash function"<<endl;
		return -1;
	}
}

HashTable::~HashTable()
{

	delete [] table;
}
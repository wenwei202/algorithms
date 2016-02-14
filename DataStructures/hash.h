#ifndef _HASHTAB_HEAD_FILE_WENWEI_BUAA____
#define _HASHTAB_HEAD_FILE_WENWEI_BUAA____

#include "list.h"
typedef enum
{
	MOD_HASH,
	MULTI_HASH
} HashFuncType; 

class HashTable
{
public:
	HashTable(int tabSize,HashFuncType funcType);
	~HashTable();
	void insert(DoubleNode *x);
	void hashDelete(DoubleNode *x);
	DoubleNode *search(int key);
	void printHashTable();
	int getTabSize()
		{
			return tabSize;
		}
private:
	int tabSize;
	HashFuncType funcType;
	DoubleList **table;
	int getTableIdx(int key);
};

#endif
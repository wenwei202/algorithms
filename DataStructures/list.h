// typedef struct  
// {
// 	DoubleNode *left;
// 	DoubleNode *right;
// 	int key;
// } DoubleNode;
// typedef DoubleNode *DoubleListHead;
// int DoubleListDelete(DoubleNode x,);
#ifndef _LIST_HEAD_FILE_WENWEI_BUAA____
#define _LIST_HEAD_FILE_WENWEI_BUAA____

class DoubleNode
{
public:
	DoubleNode(int key){
		this->key=key;
		leftNode=0;
		rightNode=0;
	};
	
	int key;
	DoubleNode *leftNode;
	DoubleNode *rightNode;

//protected:
//private:
};

class DoubleList
{
public:
	DoubleNode *head;
	DoubleList(){
		head = 0;
	};
	void deleteNode(DoubleNode *x);
	void insertNode(DoubleNode *x);
	DoubleNode *searchNode(int key);
	void printList();
//protected:
//private:
};

#endif
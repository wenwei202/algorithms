typedef struct  
{
	int *datas;
	int size;
	int headIdx;
	int tailIdx;
} Queue;

Queue *creatQueue(int size);
int freeQueue(Queue *s);
int enQueue(Queue *s,int data);//���
int deQueue(Queue *s);//����
int isEmpty(Queue *s);
int isFull(Queue *s);
//int cycleAdd(int data,int size);
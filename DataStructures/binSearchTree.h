class TreeNode
{
public:
	TreeNode *parent;
	TreeNode *leftChild;
	TreeNode *rightChild;
	int key;
	TreeNode(int key)
	{
		this->key=key;
		parent=NULL;
		leftChild=NULL;
		rightChild=NULL;
	}

};

class BinSearchTree
{
public:
	TreeNode *rootNode;
	BinSearchTree(TreeNode *rootNode)
	{
		this->rootNode=rootNode;
		elementsNum=0;
	}
	void insert(TreeNode *x);
	void nodeDelete(TreeNode *x);
	TreeNode *search(int key);
	TreeNode *minNode();
	TreeNode *maxNode();
	TreeNode *successor(TreeNode *x);
	TreeNode *predecessor(TreeNode *x);
	int height(TreeNode *rootNode);
	int inOrderWalk();
	int elementsNum;
	void printTree();
	void transplant(TreeNode *srcTree,TreeNode *dstNode);
private:
	int inOrderWalk(TreeNode *rootNode);
	TreeNode *minNode(TreeNode *rootNode);
	TreeNode *maxNode(TreeNode *rootNode);
	void goToLocation(int x,int y);
	
	

};
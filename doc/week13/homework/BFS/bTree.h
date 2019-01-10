
/* -----------declaration ---------------------------- */
/*
typedef struct {
	char name[100];
} dataTypeTree;					  */

typedef int dataTypeTree;

typedef struct treeNode {

	dataTypeTree data;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

/*---------------------------------------------------- */

void displayTreeNode(treeNode *root) {

	printf("%d", root->data);
	return;
}

/*---------------------------------------------------- */

void tree_init(treeNode **root) {

	*root = NULL;
	return;
}

treeNode *makeNewTreeNode(dataTypeTree data) {

	treeNode *newNode = (treeNode *) malloc(sizeof(treeNode));

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return(newNode);
}

treeNode *createTreeFrom2(treeNode *left, treeNode *right, dataTypeTree rootData) {

	treeNode *root = makeNewTreeNode(rootData);
	root->left = left;
	root->right = right;
	
	return(root);
}

/*--------tree traversal-------------- */

void inOrder(treeNode *root) {

	if (root == NULL) return;

	inOrder(root->left);
	displayTreeNode(root);
	inOrder(root->right);
	return;
}

void postOrder(treeNode *root) {
	
	if (root == NULL) return;

	postOrder(root->left);
	postOrder(root->right);
	displayTreeNode(root);
}

void preOrder(treeNode *root) {

	if (root == NULL) return;

	displayTreeNode(root);
	preOrder(root->left);
	preOrder(root->right);
}

/*--------------------------------------- */

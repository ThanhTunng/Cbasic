#include <stdlib.h>

typedef enum { false, true } bool;

typedef struct {
	char name[50];
	char tel[50];
	char email[50];
} dataType;

typedef struct treeNode {

	dataType data;
	struct treeNode *parent;
	struct treeNode *left;
	struct treeNode *right;
} treeNode; 

void tree_init(treeNode **root) {
	*root = NULL;
	return;
}

treeNode *makeTreeNode(dataType data) {

	treeNode *newnode = (treeNode *)malloc(sizeof(treeNode));
	newnode->data = data;
	
	newnode->parent = NULL;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return(newnode);
}

void insertTree(treeNode **root, treeNode *parent, dataType data) {
   
	if (*root == NULL) {

		treeNode *newnode = makeTreeNode(data);
		newnode->parent = parent;
		*root = newnode;

		return;
	}

	if (strcmp((*root)->data.email, data.email) > 0) {
		insertTree( &((*root)->left), *root, data);
	}
	else {
		insertTree( &((*root)->right), *root, data);
	}
	
}

treeNode *findMax(treeNode *root)
{
    if (root == NULL) return(NULL);

    treeNode *max = root;
    while (max->right != NULL)
        max = max->right;

    return(max);
}

treeNode *findMin(treeNode *root)
{
    if (root == NULL) return(NULL);

    treeNode *min = root;
    while (min->left != NULL)
        min = min->left;

    return(min);
}

treeNode *search(treeNode *root, char *email) {
	if (root == NULL) {
		return(NULL);
	}

	if (strcmp(root->data.email, email) == 0) return(root);

	if (strcmp(root->data.email, email) > 0 )
		return( search(root->left, email) );
	else
		return( search(root->right, email) );
}

void inorder(treeNode *root) {

	if (root == NULL) return;

	inorder(root->left);
	printf("%s", root->data.email);
	inorder(root->right);
}

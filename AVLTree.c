#include<stdio.h>
#include<stdlib.h>


//----------Create Node--------//
struct Node{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};


//----------Sub-Function to Calculate Max--------------

int max(int a, int b){
	return (a > b)?a:b;
}

//----------Sub-Function to Create a Node--------------

struct Node* newNode(int key){
	struct Node *node = (struct Node*)malloc(size(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	
	return (node);
}

//-------Sub-Function to Calculate height--------

int height(struct Node *N){
	if(N == NULL)
		return 0;
	
	return N->height;
}

//---------Get the Balance Factor--------

int getBalance(struct Node *N){
	if(N==NULL)
		return 0;
		
	return height(N->left) - height(N->right);
}

//----------Left Rotate---------

struct Node *leftRotate(struct Node *x){
	struct Node *y = x->right;
	struct Node *T2 = y->left;
	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
}

//----------Right Rotate---------

struct Node *rightRotate(struct Node *y){
	struct Node *x = x->left;
	struct Node *T2 = x->right;
	x->right = y;
	x->left = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
}


//----------Insert a Node--------

struct Node *insertNode(struct Node *node, int key){
	if(node == NULL)
		return (newNode(key));
	if(key < node->key){
		node->left = insertNode(node->left, key);
	}
	
	else if(key > node->key){
		node->right = insertNode(node->right, key);
	}
	
	else{
		node;
	}
	
	//----Update the balance factor of each node and balance the tree---
	
	node->height = 1 + max(height(node->left), height(node->right));
	
	int balance = getBalance(node);
	
	//Rotation
	
	if(balance >1 && key < node->left->key) //RR Rotation
		return rightRotate(node);
		
	if(balance < -1 && key > node->right->key) //LL Rotation
		return leftRotate(node);
		
	if(balance > 1 && key > node->left->key){ // LR Rotation
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	
	if(balance < -1 && key < node->right->key){ //RL Rotation
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}


//--------Print THe Tree----------

void preOrder(struct Node *root){
	if(root!= NULL){
		printf("%d->",root->key);
		prePrder(root->left);
		preOrder(root->right);
	}
}

//---------PostOrder-------------
void postOrder(struct Node *root){
	if(root!=NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d->", root->key);
	}
}

//---------Inorder------------

void inOrder(struct Node *root){
	if(root!= NULL){
		inOrder(root->left);
		printf("%d->",root->key);
		inOrder(root->right);
	}
}


int main(){
	struct Node *root = NULL;
	int val, ch;
	while(1){
		printf("\n1. Insert \n2. Display \n");
		printf("Enter your Choice: ");
		
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter value : ");
				scanf("%d", &val);
				root = insertNode(root, val);
				break;
			case 2:
				printf("\nPreOrder : ");
				preOrder(root);
				printf("PostOrder : ");
				postOrder(root);
				printf("InOrder : ");
				inOrder(root);
				break;
		}
	}
	return 0;
}

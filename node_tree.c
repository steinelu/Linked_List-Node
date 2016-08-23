#include <stdio.h>
#include <stdlib.h> // für malloc()
#include <stdbool.h>

#include "node_tree.h"

node* createNode()
{
	struct nodeStruct* temp = malloc(sizeof(struct nodeStruct));
	temp->left = NULL;
	temp->right = NULL;
	temp->ptr = NULL;
	temp->zahl = 0;
	return temp;
}

node* createTree(int cnt ) // evt anzahl an level des Baums
{
	return NULL;
}

void addTreeNodeSort(node *now, node *pre)
{
	
}

void addTreeNode(node *parent, node *rightChild, node *leftChild )
{
	
}

void deleteTreeNode(node *now)
{
	
}

void deleteTree(node *now)
{
	
}

void ausgabeTree(node *now)
{
	
}
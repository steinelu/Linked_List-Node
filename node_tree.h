// Funktionen für Baumstrukturen
#ifndef NODE_TREE_H
#define NODE_TREE_H
#include "node.h"
// Insert		Search		
//(Preorder Inorder Postorder) Traversal Ausgabe
// left und right rotation
// heap / binary
node*	createNode			(void);
node*	createTree				(int);
void	addTreeNodeSort	(node*, node* );
void	addTreeNode		(node*, node* ,node* );
void	deleteTreeNode	(node* );
void	deleteTree				(node* );
void	ausgabeTree			(node* );
// find/ get 	ChildNode / LeafNode

static const struct 
{
	node*	(*create)		(int cnt); // erstellt einen Tree mit cnt an Nodes
	void	(*addSort)	(node*, node* ); // sortiert einen node in einen Tree ein
	void	(*delet)		(node* ); // löscht den ganzen Tree
	void	(*print)		(node* );
	
	struct 
	{
		node*	(*create)	(void); // erstellt einen Node
		void	(*add)		(node*, node* ,node* ); // child 1 und 2 zu parent hizufügen
		void	(*delet)	(node* ); // löscht einen Node heraus
	}Node ;//= {createNode, addTreeNode, deleteTreeNode};
}Tree ={
	createTree, 
	addTreeNodeSort, 
	deleteTree, 
	ausgabeTree, 
	{
		createNode, 
		addTreeNode, 
		deleteTreeNode
	}
};

#endif
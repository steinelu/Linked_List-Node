// Funktionen für die doppelt verkettete Listen
#ifndef NODE_LIST_H
#define NODE_LIST_H
#include "node.h"

// stack LIFO /  Queue FIFO

node*	createDynArrNull(void);
node*	createDynArr		(int);
node*	createList			(int);
void	addDynArrSort	(node *now, node *pre);
void	addDynArr			(node *now, node *pre);
void	deleteDynArr		(node *now);
void	swapDynArr		(node *one, node *two);
void	startDynArr		(node **tmp);
void	endDynArr			(node **tmp);
void	increase				(node **tmp);
void	ausgabeDynArr	(node *now);

#ifdef NODE_STACK
void	pushStack	(node* ,node* );
node*	popStack	(node* );
node*	peekStack	(node* );
// isFull // isEmty
#endif

// Funktionszeigerstruct für die Listenfunktionen
static const struct 
{
	node*	(*create)			(int);
	node*	(*createList)	(int );
	void	(*add)				(node*, node *);
	void	(*addSort)		(node*, node *);
	void	(*delet)			(node*);
	void	(*swap)			(node*, node *);
	void	(*start)			(node**);
	void	(*end)				(node**);
	void	(*increase)		(node**);
	void	(*print)			(node*);
	
	#ifdef NODE_STACK
	struct 
	{
		void	(*push)	(node* ,node* );
		node*	(*pop)		(node* );
		node*	(*peek)	(node* );
		// isFull // isEmty
	}Stack;
	#endif
	
}List =  // erstellen und zuweisen eines structs List
{ 
	createDynArr, 
	createList,
	addDynArrSort, 
	addDynArr, 
	deleteDynArr, 
	swapDynArr, 
	startDynArr, 
	endDynArr, 
	increase,
	ausgabeDynArr
	#ifdef NODE_STACK
	,{
		pushStack,
		popStack,
		peekStack
	}
	#endif
} ;


#endif
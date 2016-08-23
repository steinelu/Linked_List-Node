
#ifndef NODE_H
#define NODE_H
/*
typedef struct nodeStruct
{
	void *ptr;
	union 
	{
		int zahl;
		char text[256]; 
	};
	struct nodeStruct *next;
	struct nodeStruct *prev;
}node;
*/

typedef struct nodeStruct
{
	void *ptr;
	union 
	{
		int zahl;
		char text[256]; 
	};
	union
	{
		struct nodeStruct *next;
		struct nodeStruct *left;
	};
	union
	{
		struct nodeStruct *prev;
		struct nodeStruct *right;
	};
}node;
#endif

#if defined(NODE_LIST ) || defined(NODE_STACK ) 
#include "node_list.h"
#endif

#ifdef NODE_TREE
#include "node_tree.h"
#endif

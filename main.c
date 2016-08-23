#include <stdio.h>
#include <stdlib.h> // für malloc()

//#define NDEBUG
#include <assert.h>

#define NODE_LIST
#define NODE_STACK
#define NODE_TREE
#include "node.h"
//#include "DynArr.h"



int main(int argc, char **argv)
{
    node *now = createList(3);
    node *one = NULL;
    node *two = NULL;
    
    startDynArr(&now);
    //endDynArr(&now);
    one = now;
    
    //endDynArr(&now);
    //now = now->next->next;
    two = now->next;
    
    printf("struct:\t%d\t%d\n\n", one->zahl, two->zahl);
    
    ausgabeDynArr(now);
    swapDynArr(one, two);
    
    
    //deleteDynArr(two);
    
    //assert(0 && "ERROR");
    
    ausgabeDynArr(now);
    printf("\n\n");
    
    /*
    DynArr *my = createDynArr();
    my->ptr =  my;
    my->zahl = 12;*/
    
    system("PAUSE");
    return 0;
}

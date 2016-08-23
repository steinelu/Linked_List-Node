#include <stdio.h>
#include <stdlib.h> // für malloc()
#include <stdbool.h>

#include "node_list.h"

//#define hilsstruct true

node*	createDynArrNull(void)
{
    node *temp = malloc(sizeof(node));
    temp->zahl = 0;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

node*	createDynArr(int i)
{
    node *temp = malloc(sizeof(node));
    temp->zahl = i;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

node*	createList(int cnt)
{
    node*	tmp = createDynArr(0);
    int i = 0;
    for( i = 1 ; i < cnt ; i++ )
    {
        addDynArr(createDynArr(i), tmp);
        tmp = tmp->next;
    }
    return tmp;
}

//now = wird hinzugefügt
//pre = zu dem es hinzugefügt wird

//noch sehr simpel
// funktionszeiger  zum sortieren eines void structs zeugs
void addDynArrSort(node *now, node *pre)
{
    node *list = pre;
    
    bool ok = true;
    
    for( startDynArr(&list) ; (list->next != NULL)&&(ok) ; increase(&list))
    {
        if(list->next->zahl > now->zahl)
        {
            addDynArr(now, list);
            ok = false;
        }
    }
}

void addDynArr(node *now, node *pre)
{
    if(pre->next == NULL) // wenn ganz hinten (letztes  )
    {
        now->prev = pre;
        pre->next = now;
    }
    else // mitten im array
    {
        now->next = pre->next;
        pre->next->prev = now;
        pre->next = now;
        now->prev = pre;
    }
}

void deleteDynArr(node *now)
{
    if(!now->next ) // ganz hinten
    {
        now->prev->next = NULL;
        now->prev = NULL;
    }
    else if(!now->prev) // ganz vorn
    {
        now->next->prev = NULL;
        now->next = NULL;
    }
    else // mitten drin
    {
        now->prev->next = now->next;
        now->next->prev = now->prev;
        now->next = NULL;
        now->prev = NULL;
    }
    free(now);
}

/*tausche struct one mit struct two*/
//TODO liste aus zwei structs, structs vertauschen
void swapDynArr(node *one, node *two)
{
    if(!one || !two || one == two)
    {
        // TODO Fehler ausgeben
        return;
    }
    
    // am Anfang oder ende  (vertauscht)
    if((!two->prev && one->next) || (!one->next && two->prev)) 
    {
        //printf("wechsel");
        node *tmp = one;
        one = two;
        two = tmp;
    }
    
    if(one->next == two || two->next == one) //nebeneinander
    {
        if((!one->prev && two->next)) // am Anfang
        {
            one->next = two->next;
            two->next->prev = one;
            two->prev = one->prev;
            one->prev = two;
            two->next = one;
        }
        else if(one->prev || !two->next) // am Ende
        {
            one->next = two->next;
            one->prev->next = two;
            two->prev = one->prev;
            two->next = one;
            one->prev = two;
        }
        else // mitten drin 
        {
            one->prev->next =  two;
            two->next->prev = one;
            one->next = two->next;
            two->prev = one->prev;
            two->next = one;
            one->prev = two;
        }
    }
    else//nicht nebeneinander
    {
        if (!one->prev && !two->next) // beide am Anfang / Ende
        {
            one->prev = two->prev;
            two->next = one->next;
            two->next->prev = two;
            one->prev->next = one;
            one->next = NULL;
            two->prev = NULL;
        }
        else if((!one->prev && two->next)) // am Anfang
        {
            one->prev = two->prev;
            two->prev = two->next;
            two->next = one->next;
            one->next = two->prev;
            one->next->prev = one;
            one->prev->next = one;
            two->next->prev = two;
            two->prev = NULL;
        }
        else if(one->prev || !two->next) // am Ende
        {
            two->next = one->next;
            one->next = one->prev;
            one->prev =two->prev;
            two->prev = one->next;
            two->prev->next = two;
            two->next->prev = two;
            one->prev->next = one;
            one->next = NULL;
        }
        else
        {
            one->prev->next = two;
            two->next->prev = one;
            one->next->prev = one->prev;
            two->prev->next = two->next;
            one->prev = two->prev;
            two->next = one->next;
            two->prev = one->next->prev;
            one->next = one->prev->next;
            two->next->prev = two;
            one->prev->next = one;
        }
    }
}

// gehe an den Anfang der Liste
void startDynArr(node **tmp)
{
    while((*tmp)->prev != NULL)
    {
        (*tmp) = (*tmp)->prev;
    }
}

// gehe ans Ende der Liste
void endDynArr(node **tmp)
{
    while((*tmp)->next)
    {
        (*tmp) = (*tmp)->next;
    }
}

node *getDynArr(node *list, int zahl)
{
    startDynArr(&list);
    
    node *tmp = NULL;
    while(list != NULL)
    {
        if(list->zahl < zahl)
        {
            tmp = list;
            return tmp;
        }
        
        list = list->next;
    }
    return list;
}

void increase(node **tmp)
{
    if((*tmp)->next != NULL)
    {
        (*tmp) = (*tmp)->next;
    }
}

void ausgabeDynArr(node *now)
{
    node *tmp = now;
    startDynArr(&tmp);
    
    while(tmp != NULL)
    {
        printf("%d\t", tmp->zahl);
        tmp = tmp->next;
    }
    printf("\n");
}


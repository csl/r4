#include "global.h"

/* TO BE COMPLETED: implement backpatch operations on lists */

int BACKPATCH_LIST_SIZE = 20;

Backpatchlist *makelist(int location)
{
    Backpatchlist * templist = (int *)malloc(sizeof(int) *  BACKPATCH_LIST_SIZE);
    templist[0] = location;
    templist[1] = 0;
    return templist;
}

void backpatchlist(Backpatchlist *list, int location)
{
    int i=0;
    for(i=0; list[i]!=0; ++i)
        {
            //printf("backpatchlist->(%d)<===>%d<<\n", i, location);
            backpatch(list[i], location);
        }
    
}

Backpatchlist *mergelist(Backpatchlist *list1, Backpatchlist *list2)
{
    Backpatchlist * templist = (int *)malloc(sizeof(int)*BACKPATCH_LIST_SIZE);

    int i=0;
    for(i=0;list1[i]!=0;++i)
        templist[i] = list1[i];
    int j=0;
    for(j=0;list2[j]!=0;++i,++j)
        templist[i] = list2[j];
    templist[i] = 0;
    
    return templist;
}

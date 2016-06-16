//
//  dArray.h
//  Darray
//
//  Created by Francesco  on 16/06/16.
//  Copyright © 2016 Francesco Saverio Zuppichini. All rights reserved.
//

#ifndef dArray_h
#define dArray_h
#define EXPLICIT_CAST(pointer,type)((type *)(pointer))
#define dArrayGetData(node,type)((type*)(EXPLICIT_CAST(node,dArrayNode))->data)

#define BASIC_SIZE 4
#define DEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    /* element. */
    void * data;
}dArrayNode;

typedef struct{
    /* numbers of elements .*/
    unsigned int len;
    /* size of the array. */
    unsigned int size;
    /* size of the stored element. */
    size_t dataSize;
    /* this will holds the data. */
    dArrayNode ** innerArray;
} dArray;


dArray * dArrayInit(size_t);
/* add an element. */
dArrayNode * dArrayAdd(dArray *, void *);
/* remove an element at specific index. 
 Other elements will be shifted. */
dArrayNode * dArrayRemove(dArray *, const unsigned int * idx);
/* pop an element. */
dArrayNode * dArrayPop(dArray *);
/* return a element at specific index. */
dArrayNode * dArrayGet(dArray *self,const unsigned int idx);
/* remove and free al memory. */
void dArrayDestroy(dArray *);


#endif /* dArray_h */

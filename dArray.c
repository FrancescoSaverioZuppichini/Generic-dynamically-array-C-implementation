//
//  dArray.c
//  Darray
//
//  Created by Francesco  on 16/06/16.
//  Copyright © 2016 Francesco Saverio Zuppichini. All rights reserved.
//

#include "dArray.h"
#define BASIC_SIZE 4
#define MemoryAllocationError "Could not allocate new memory. "
#define IndexOutOfRange "Index out of range. "

dArray * dArrayInit(size_t size){
    dArray * myDArray;
    
    myDArray = malloc(sizeof(dArray));
    if(!myDArray)
        return NULL;
    
    myDArray->innerArray = malloc(sizeof(dArrayNode) * size *  BASIC_SIZE);
    if(!myDArray->innerArray)
        return NULL;
    
    myDArray->len = 0;
    myDArray->size = BASIC_SIZE;
    myDArray->dataSize = size;
    
    
    return myDArray;
}

dArrayNode * dArrayAdd(dArray *self, void * el){
    dArrayNode *toAdd;
    
    toAdd = malloc(sizeof(dArrayNode));
    if(!toAdd)
        return NULL;
    
    toAdd->data = malloc(self->dataSize);
    memcpy(toAdd->data, el, self->dataSize);
    if(DEBUG)
        printf("Copied %i len %u\n", *(int *) toAdd->data, self->len);
    /* check for memory re-allocation. */
    if(self->len == self->size){
        if(DEBUG)
            printf("Size before, len %u, %u\n", self->size, self->len);
        self->size *= 2;
        /* need to allocate more. */
        self->innerArray = realloc(self->innerArray, self->size);
        
        if(DEBUG)
            printf("Size after re-allocation, len %u, %u\n", self->size, self->len);
        if(!self->innerArray)
            puts(MemoryAllocationError);
    }
    if(!toAdd->data)
        return NULL;
    
    self->innerArray[self->len] = toAdd;
    
    self->len++;
    
    
    return toAdd;
}

dArrayNode * dArrayPop(dArray *self){
    dArrayNode * toPop;
    
    /* array is empty. */
    if(self->len <= 0)
        return NULL;
    /* decrement len. */
    self->len--;
    
    toPop = self->innerArray[self->len ];
    
    if(!toPop)
        return NULL;
    
    /* decrement the size. */
    
    return toPop;
}



dArrayNode * dArrayGet(dArray *self, const unsigned int idx){
    dArrayNode * toGet;
    
    if(idx >= self->len){
        puts(IndexOutOfRange);
        return NULL;
    }
    
    toGet = self->innerArray[idx];
    return toGet;
}

void dArrayDestroy(dArray * self){
//    for(int i = 0; i < self->len; i++){
//
//        free(self->innerArray[i]->data);
//        free(self->innerArray[i]);
//        
//    }
    free(self->innerArray);
    free(self);
}

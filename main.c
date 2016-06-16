//
//  main.c
//  Darray
//
//  Created by Francesco  on 16/06/16.
//  Copyright © 2016 Francesco Saverio Zuppichini. All rights reserved.
//

#include <stdio.h>
#include "dArray.h"

int main(int argc, const char * argv[]) {
    int i;
    dArray * myDArray;
    myDArray = dArrayInit(sizeof(int));
    if(!myDArray)
        return 0;
    
    for(i = 0; i < 6; i++){
        dArrayAdd(myDArray,&i);
    }
    printf("len: %i\n", myDArray->len);
    for(; i > 0; i--){
        dArrayNode * tempNode = dArrayPop(myDArray);
        printf("%i\n",*dArrayGetData(tempNode, int));
    }
    
    for(i = 0; i < 6; i++){
        dArrayAdd(myDArray,&i);
    }
    
    printf("get at 1: %i\n",*dArrayGetData(dArrayGet(myDArray,1), int));
    
    for(; i > 0; i--){
        dArrayNode * tempNode = dArrayGet(myDArray, i - 1);
        printf("get at %i, %i\n",i - 1, *dArrayGetData(tempNode, int));
    }
    for(i = 0; i < myDArray->len; i++){
        dArrayNode * tempNode = dArrayGet(myDArray, i);
        printf("get at %i, %i\n",i , *dArrayGetData(tempNode, int));
    }

    dArrayDestroy(myDArray);
    return 0;
}

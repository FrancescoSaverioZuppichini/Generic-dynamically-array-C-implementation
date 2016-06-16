#Generic dynamically Array 
##A easy array-object Array implemenent in c

### *Implemented by Francesco Saverio Zuppichini*

###How to use it
```
#include "dArray.h" 
```
In your source file 
####Create a new array
```
dArray * myDArray;
myDArray = dArrayInit(sizeof(<yourElement>));;
```
You need to pass the size of the elements that you want to store

####Use the API method 
All the API method are defined in *variabile_Int_Array.h*

####Add an element:

```
dArrayAdd(myDArray,&<yourElement>);
```

####Pop an element:

```
dArrayNode * tempNode = dArrayPop(myDArray);
printf("%i\n",*dArrayGetData(tempNode, <yourElementType (e.g int)>));
```
It returns the popped element

####Get an element:

```
dArrayNode * tempNode = dArrayGet(myDArray, <index>);
printf("get at %i, %i\n",i - 1, *dArrayGetData(tempNode, <yourElementType (e.g int)>));
```
It returns the getted element


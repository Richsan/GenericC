/*
   Author: Henrique Manoel (Rich-San) - Brazilian from São Paulo-SP
   Creation Date: 12/02/2015
   Github: https://github.com/Richsan

*/
#ifndef GENERICCBHEAP_H
#define GENERICCBHEAP_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../VoidFunctions/VoidFunctions.h"

#define BHEAP_ROOT 1
#define BHEAP_PARENT(n) (n/2)
#define BHEAP_LEFTCHILD(n) (2*n)
#define BHEAP_RIGHTCHILD(n) (2*n + 1)

//Macro functions definitions

#define pushBHeap(heap, value) (_getPTR_PushBHeap()(heap, value, sizeof(*value)))
#define pushLiteralBHeap(heap, literal, type) {type heap##1 = literal; _getPTR_PushBHeap()(heap,& heap##1, sizeof(heap##1)); }
#define popBHeap(heap, type) (*(type *)_getPTR_PopBHeap()(heap)) 
#define popBHeapGet(heap, guardVar) (_getPTR_PopBHeapGet()(heap, guardVar, sizeof(* guardVar)))

// parent pointer function definition
typedef bool (* conditionFunction)(void *elem1, void *elem2);

//BHeap structure
typedef struct _heap
{
      void ** data;
      unsigned int maxSize;
      unsigned int currentSize;
      conditionFunction isParent;
    
}_heap;

typedef  _heap * bHeap;

//public accessible functions
void createBHeap(bHeap * const h,const unsigned int maxSize, conditionFunction func);
void destroyBHeap(bHeap h);
bool bHeapIsEmpty(bHeap h);
bool bHeapIsFull(bHeap h);
bool isBHeapLeaf(bHeap h, const unsigned int index);
void setBHeapLength(bHeap h,unsigned int length);

//macro only access functions
static void _pushBHeap(bHeap h, void * const value,const unsigned int size);//use macro to access
static void * _popBHeap(bHeap h);//use macro to access
static void  _popBHeapGet(bHeap h, void * const guardVar, const unsigned int size);//use macro to access

//non-accessible functions
static void swapBHeap(bHeap h, const unsigned int index1,const unsigned int index2);
static void upBHeap(bHeap h, unsigned int indexNode);
static void downBHeap(bHeap h,  unsigned int indexNode);
static unsigned int maxNodeBHeap(bHeap h,const unsigned int index1,const unsigned int index2,const unsigned int index3);

//static access definition
typedef void(* _FUNC_PTRPUSHBHEAP)(bHeap h, void * const value,const unsigned int size);
typedef void *(* _FUNC_PTRPOPBHEAP)(bHeap h);
typedef void (* _FUNC_PTRPOPBHEAPGET)(bHeap h, void * const guardVar, const unsigned int size);

_FUNC_PTRPUSHBHEAP _getPTR_PushBHeap();
_FUNC_PTRPOPBHEAP _getPTR_PopBHeap();
_FUNC_PTRPOPBHEAPGET _getPTR_PopBHeapGet();

#endif

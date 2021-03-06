/*
	Author: Henrique Manoel (Rich-San) - Brazilian from São Paulo-SP
	Creation Date: 14/01/2015
	Github: https://github.com/Richsan

*/

#ifndef GENERICCSTATICQUEUE_H
#define GENERICCSTATICQUEUE_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../VoidFunctions/VoidFunctions.h"

//enStaticQueue = enter static queue (insert)
//deStaticQueue = delete static queue (remove)

//macro functions
#define enStaticQueue(Queue, elem) (_getPTR_EnStaticQueue()(Queue, elem, sizeof(*elem)))
#define deStaticQueue(Queue, type) (*(type *)(_getPTR_DeStaticQueue()(Queue)))
#define deStaticQueueGet(Queue, elem) (_getPTR_DeStaticQueueGet(Queue,elem,sizeof(*elem)))
#define enStaticQueueLiteral(Queue, literal,type) { type Queue##1 = literal; _getPTR_EnStaticQueue()(Queue,& Queue##1,sizeof( Queue##1)); }

//Queue structure
struct Staticqueue{

	int qtElements;
	void ** elem;
	int front, rear;
	int currentSize;
	
};

typedef struct Staticqueue * staticQueue;


//accessible functions
void createStaticQueue(staticQueue * const q, const int nElem);
void destroyStaticQueue(staticQueue q);
bool staticQueueIsEmpty(staticQueue const q);
bool staticQueueIsFull(staticQueue const q);
void setStaticQueueLength(staticQueue q, int length);

//macro only access functions
static void _enStaticQueue(staticQueue q,void * const elem, const unsigned int size);
static void * _deStaticQueue(staticQueue q);
static void _deStaticQueueGet(staticQueue q, void * const elem, const unsigned int size);

//static access definitions
typedef void   (* _FUNC_PTRENSTATICQUEUE)(staticQueue q,void * const elem, const unsigned int size);
typedef void * (* _FUNC_PTRDESTATICQUEUE)(staticQueue q);
typedef void   (*_FUNC_PTRDESTATICQUEUEGET)(staticQueue q, void * const elem, const unsigned int size);

_FUNC_PTRENSTATICQUEUE _getPTR_EnStaticQueue();
_FUNC_PTRDESTATICQUEUE _getPTR_DeStaticQueue();
_FUNC_PTRDESTATICQUEUEGET _getPTR_DeStaticQueueGet();

#endif

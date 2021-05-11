#pragma once
#include "heads.h"
using namespace std;
#define OK 1
#define ERROR 0
template <typename ElemType>
// Circular queue
class sqQueue
{
private:
    const static int MAXSIZE = 20;
    ElemType data[MAXSIZE];
    int size;
    int front;
    int rear;

public:
    sqQueue();
    ~sqQueue();
    bool isFull();
    bool isEmpty();
    int getLength();
    static bool setElem(sqQueue *Q, ElemType &e);
    static bool getElem(sqQueue *Q, ElemType *e);
};

template <typename ElemType>
bool sqQueue<ElemType>::getElem(sqQueue *Q, ElemType *e)
{
    if (Q->isEmpty())
    {
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % Q->size;
    return OK;
}

template <typename ElemType>
bool sqQueue<ElemType>::setElem(sqQueue *Q, ElemType &e)
{
    if (Q->isFull())
    {
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % Q->size;
    return OK;
}

template <typename ElemType>
int sqQueue<ElemType>::getLength()
{
    return (rear - front + size) % size;
}

template <typename ElemType>
bool sqQueue<ElemType>::isFull()
{
    return (rear + 1) % size == front;
}

template <typename ElemType>
bool sqQueue<ElemType>::isEmpty()
{
    return rear == front;
}

template <typename ElemType>
sqQueue<ElemType>::sqQueue()
{
    front = 0;
    rear = 0;
    size = MAXSIZE;
}

template <typename ElemType>
sqQueue<ElemType>::~sqQueue()
{
}
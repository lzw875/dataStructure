#pragma once
#include "heads.h"
#include "linkList.hpp"
using namespace std;
#define OK 1
#define ERROR 0
template <typename ElemType>
class linkQueue
{
private:
    linkList<ElemType> *front;
    linkList<ElemType> *rear;

public:
    linkQueue();
    ~linkQueue();
    bool isEmpty();
    bool showElems();
    static bool setElem(linkQueue *p, ElemType e);
    static bool getElem(linkQueue *p, ElemType* e);
};

template <typename ElemType>
bool linkQueue<ElemType>::showElems()
{
    if(this->isEmpty())
    {
        cout << "Warning, the queue is empty!" << endl;
        return ERROR;
    }
    linkList<ElemType> *q = this->front->next;
    while(q)
    {
        cout << q->data << ' ';
        q = q->next;
    }
    cout << endl;
    return OK;
}

template <typename ElemType>
bool linkQueue<ElemType>::getElem(linkQueue *p, ElemType* e)
{
    if(p->isEmpty())
    {
        cout << "Warning, the queue is empty!" << endl;
        return ERROR;
    }
    linkList<ElemType> *q = p->front->next;
    p->front->next = q->next;
    // Warning!
    if(q == p->rear)
    {
        p->rear = p->front;
    }
    *e = q->data;
    delete q;
    return OK;
}

template <typename ElemType>
bool linkQueue<ElemType>::setElem(linkQueue *p, ElemType e)
{
    try
    {
        p->rear->next = new linkList<ElemType>(e);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(0);
    }
    p->rear = p->front->next;
    return OK;
}

template <typename ElemType>
bool linkQueue<ElemType>::isEmpty()
{
    return front == rear;
}

template <typename ElemType>
linkQueue<ElemType>::linkQueue()
{
    front = new linkList<ElemType>();
    rear = front;
}

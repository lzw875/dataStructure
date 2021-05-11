#ifndef LINKSTACK_H
#define LINKSTACK_H
#define ERROR 0
#define OK 1
#include "heads.h"
#include "linkLIst.hpp"
using namespace std;
template <typename ElemType>
class linkStack
{
private:
    linkList<ElemType> *top = nullptr;

public:
    int count = 0;
    linkStack();
    ~linkStack();
    static bool pushElem(linkStack *p, ElemType e);
    static bool popElem(linkStack *p, ElemType *e);
    void showElems();
    bool isEmpty();
};

template <typename ElemType>
bool linkStack<ElemType>::isEmpty()
{
    return this->count == 0 ? true : false;
}

template <typename ElemType>
void linkStack<ElemType>::showElems()
{
    if (!this->top)
    {
        cout << "Warning, the stack is empty!" << endl;
    }
    linkList<ElemType> *q = this->top;
    while (q)
    {
        cout << q->data << " ";
        q = q->next;
    }
    cout << endl;
}

template <typename ElemType>
bool linkStack<ElemType>::popElem(linkStack *p, ElemType *e)
{
    if (!p->top)
    {
        return ERROR;
    }
    linkList<ElemType> *q = p->top;
    p->top = q->next;
    *e = q->data;
    delete q;
    p->count--;
    return OK;
}

template <typename ElemType>
bool linkStack<ElemType>::pushElem(linkStack *p, ElemType e)
{
    linkList<ElemType> *q = new linkList<ElemType>(e);
    if (p->top)
    {
        q->next = p->top;
    }
    p->top = q;
    p->count++;
    return OK;
}

template <typename ElemType>
linkStack<ElemType>::linkStack()
{
}
template <typename ElemType>
linkStack<ElemType>::~linkStack()
{
}

#endif
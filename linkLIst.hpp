#ifndef LINKLIST_H
#define LINKLIST_H
#include "heads.h"
#define ERROR 0
#define OK 1
template <typename ElemType>
class linkList
{
private:
    ElemType data;

public:
    linkList *next = nullptr;
    linkList(/* args */);
    linkList(ElemType e);
    linkList(ElemType e, linkList *nxt);
    ~linkList();
    static bool getElem(linkList *L, int ind, ElemType *e);
};

template <typename ElemType>
linkList<ElemType>::linkList(/* args */)
{
}

template <typename ElemType>
linkList<ElemType>::linkList(ElemType e)
{
    this->data = e;
}

template <typename ElemType>
linkList<ElemType>::linkList(ElemType e, linkList *nxt)
{
    this->data = e;
    this->next = nxt;
}

template <typename ElemType>
linkList<ElemType>::~linkList()
{
}

template <typename ElemType>
bool linkList<ElemType>::getElem(linkList *L, int ind, ElemType *e)
{
    linkList *p = L->next;
    int j = 1;
    while (p && j < ind)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > ind)
    {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

#endif
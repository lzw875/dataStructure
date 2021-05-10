#ifndef LINKLIST_H
#define LINKLIST_H
#include "heads.h"
#define ERROR 0
#define OK 1
using namespace std;
template <typename ElemType>
class linkList
{
private:

public:
    ElemType data;
    linkList *next = nullptr;
    linkList(/* args */);
    linkList(ElemType e);
    linkList(ElemType e, linkList *nxt);
    ~linkList();
    static void showElems(linkList *L);
    static bool getElem(linkList *L, int ind, ElemType *e);
    static bool inserElem(linkList *L, int ind, ElemType *e);
    static bool deleteElem(linkList *L, int ind, ElemType *e);
    static bool creatListHead(linkList *L, int len);
    static bool clearListHead(linkList *L);
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
void linkList<ElemType>::showElems(linkList *L)
{
    while (L->next != nullptr)
    {
        cout << L->next->data << " ";
        L = L->next;
    }
    cout << endl;
}

template <typename ElemType>
bool linkList<ElemType>::getElem(linkList *L, int ind, ElemType *e)
{
    if (ind < 1)
    {
        cout << "Warning: ind needs to be greater than 0." << endl;
        return ERROR;
    }
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

template <typename ElemType>
bool linkList<ElemType>::inserElem(linkList *L, int ind, ElemType *e)
{
    if (ind < 1)
    {
        cout << "Warning: ind needs to be greater than 0." << endl;
        return ERROR;
    }
    linkList *p = L;
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
    linkList *tmpNode = new linkList(*e);
    tmpNode->next = p->next;
    p->next = tmpNode;
    return OK;
}

template <typename ElemType>
bool linkList<ElemType>::deleteElem(linkList *L, int ind, ElemType *e)
{
    if (ind < 1)
    {
        cout << "Warning: ind needs to be greater than 0." << endl;
        return ERROR;
    }
    linkList *p = L;
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
    linkList *q = p->next;
    *e = q->data;
    p->next = p->next->next;
    delete q;
    return OK;
}

template <typename ElemType>
bool linkList<ElemType>::creatListHead(linkList *L, int len)
{
    *L = *(new linkList(len));
    linkList *p = L;
    srand(time(0));
    for (int i = 0; i < len; ++i)
    {
        p->next = new linkList(rand() % 100 + 1);
        p = p->next;
    }
    return OK;
}

template <typename ElemType>
bool linkList<ElemType>::clearListHead(linkList *L)
{
    linkList *p, *q;
    p = L->next;
    while (p)
    {
        q = p;
        p = p->next;
        delete q;
    }
    L->next = nullptr;
    return OK;
}

#endif
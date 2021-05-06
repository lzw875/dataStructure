#ifndef myList_H
#define myList_H
#include "heads.h"
#define OK 1
#define ERROR 0

template <typename ElemType>
class myList
{
private:
    static const int MAXSIZE = 20;
    ElemType data[MAXSIZE];
    int length;
    int size;

public:
    myList(/* args */);
    static bool listInsert(myList *lst, int ind, ElemType *e);
    static bool listDelete(myList *lst, int ind, ElemType *e);
    void showElems();
    static bool getElem(myList *lst, int ind, ElemType *e);
    int getLength();
    int getSize();
    bool setElem(int ind, ElemType e);
    ~myList();
};

template <typename ElemType>
myList<ElemType>::myList(/* args */)
{
    this->size = MAXSIZE;
    this->length = 0;
};

template <typename ElemType>
bool myList<ElemType>::listDelete(myList *lst, int ind, ElemType *e)
{
    if (lst->length == 0)
    {
        return ERROR;
    }
    if (ind < 0 || ind >= lst->length)
    {
        return ERROR;
    }
    *e = lst->data[ind];
    for(int i = ind; i+1 < lst->length; ++i)
    {
        lst->data[i] = lst->data[i+1];
    }
    lst->length--;
    return OK;
}

template <typename ElemType>
bool myList<ElemType>::listInsert(myList *lst, int ind, ElemType *e)
{
    if (lst->length >= lst->size)
    {
        return ERROR;
    }
    if (ind >= lst->size || ind < 0)
    {
        return ERROR;
    }
    if (ind < lst->length)
    {
        for (int i = lst->length - 1; i >= ind; --i)
        {
            lst->data[i+1] = lst->data[i];
        }
    }
    lst->data[ind] = *e;
    lst->length++;
    return OK;
}

template <typename ElemType>
void myList<ElemType>::showElems()
{
    for (int i = 0; i < this->length; ++i)
    {
        std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * Return 1 means getted element, otherwise return 0. 
*/
template <typename ElemType>
bool myList<ElemType>::getElem(myList *lst, int ind, ElemType *e)
{
    if (lst->length <= 0 || ind >= lst->length || ind < 0)
    {
        return ERROR;
    }
    *e = lst->data[ind];
    return OK;
}
template <typename ElemType>
int myList<ElemType>::getLength()
{
    return this->length;
}

template <typename ElemType>
int myList<ElemType>::getSize()
{
    return this->size;
}

template <typename ElemType>
bool myList<ElemType>::setElem(int ind, ElemType e)
{
    if (ind >= this->size || ind < 0)
    {
        return ERROR;
    }
    this->data[ind] = e;
    this->length += 1;
    return OK;
}

template <typename ElemType>
myList<ElemType>::~myList()
{
}

#endif
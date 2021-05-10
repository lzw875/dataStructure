#ifndef SQList_H
#define SQList_H
#include "heads.h"
#define OK 1
#define ERROR 0

template <typename ElemType>
class sqList
{
private:
    static const int MAXSIZE = 20;
    ElemType data[MAXSIZE];
    int length;
    int size;

public:
    sqList(/* args */);
    static bool listInsert(sqList *lst, int ind, ElemType *e);
    static bool listDelete(sqList *lst, int ind, ElemType *e);
    void showElems();
    static bool getElem(sqList *lst, int ind, ElemType *e);
    int getLength();
    int getSize();
    bool setElem(int ind, ElemType e);
    ~sqList();
};

template <typename ElemType>
sqList<ElemType>::sqList(/* args */)
{
    this->size = MAXSIZE;
    this->length = 0;
};

template <typename ElemType>
bool sqList<ElemType>::listDelete(sqList *lst, int ind, ElemType *e)
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
    for (int i = ind; i + 1 < lst->length; ++i)
    {
        lst->data[i] = lst->data[i + 1];
    }
    lst->length--;
    return OK;
}

template <typename ElemType>
bool sqList<ElemType>::listInsert(sqList *lst, int ind, ElemType *e)
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
            lst->data[i + 1] = lst->data[i];
        }
    }
    lst->data[ind] = *e;
    lst->length++;
    return OK;
}

template <typename ElemType>
void sqList<ElemType>::showElems()
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
bool sqList<ElemType>::getElem(sqList *lst, int ind, ElemType *e)
{
    if (lst->length <= 0 || ind >= lst->length || ind < 0)
    {
        return ERROR;
    }
    *e = lst->data[ind];
    return OK;
}
template <typename ElemType>
int sqList<ElemType>::getLength()
{
    return this->length;
}

template <typename ElemType>
int sqList<ElemType>::getSize()
{
    return this->size;
}

template <typename ElemType>
bool sqList<ElemType>::setElem(int ind, ElemType e)
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
sqList<ElemType>::~sqList()
{
}

#endif
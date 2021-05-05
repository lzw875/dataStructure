#ifndef myList_H
#define myList_H
#include"heads.h"
#define OK 1
#define ERROR 0

template<typename ElemType>
class myList
{
private:
    static const int MAXSIZE = 20;
    
public:
    ElemType* data;
    int length;
    int size;
    myList(/* args */);
    static bool getElem(myList* lst, int ind, ElemType* e);
    ~myList();
};

template<typename ElemType>
myList<ElemType>::myList(/* args */)
{
    ElemType arr[MAXSIZE];
    this->size = MAXSIZE;
    this->data = arr;
    this->length = 0;
};

/**
 * Return 1 means getted element, otherwise return 0. 
*/
template<typename ElemType>
bool myList<ElemType>::getElem(myList* lst, int ind, ElemType* e)
{
    if(lst->length <= 0 || ind >= lst->length || ind < 0) {return ERROR;}
    *e = lst->data[ind];
    return OK;
}

template<typename ElemType>
myList<ElemType>::~myList()
{
}

#endif
#ifndef SQSTACK_H
#define SQSTACK_H
#include "heads.h"
#define ERROR 0
#define OK 1
using namespace std;
template <typename ElemType>
class sqStack
{
private:
    const static int MAXSIZE = 20;
    ElemType data[MAXSIZE];
    int top = -1;

public:
    sqStack();
    ~sqStack();
    void showElems();
    static bool pushElem(sqStack *s, ElemType e);
    static bool popElem(sqStack *s, ElemType *e);
};

template <typename ElemType>
bool sqStack<ElemType>::popElem(sqStack *s, ElemType* e)
{
    if (s->top < 0)
    {
        return ERROR;
    }
    *e = s->data[s->top--];
    return OK;
}

template <typename ElemType>
bool sqStack<ElemType>::pushElem(sqStack *s, ElemType e)
{
    if (s->top >= MAXSIZE - 1)
    {
        return ERROR;
    }
    s->data[++s->top] = e;
    return OK;
}

template <typename ElemType>
void sqStack<ElemType>::showElems()
{
    int j = this->top;
    for (int i = 0; i <= j; ++i)
    {
        cout << this->data[i] << " ";
    }
    cout << endl;
}

template <typename ElemType>
sqStack<ElemType>::sqStack()
{
}

template <typename ElemType>
sqStack<ElemType>::~sqStack()
{
}

#endif
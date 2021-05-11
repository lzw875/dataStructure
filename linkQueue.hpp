#pragma once
#include "heads.h"
#include "linkList.hpp"
using namespace std;
#define OK 1
#define ERROR 0
template<typename ElemType>
class linkQueue
{
private:
    linkList *front;
    linkList *rear;
public:
    linkQueue();
    ~linkQueue();
};

template<typename ElemType>
linkQueue<ElemType>::linkQueue()
{
    front = new linkList();
    rear = front;
}

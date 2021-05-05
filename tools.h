#ifndef TOOLS_H
#define TOOLS_H
#include"heads.h"
using namespace std;

template<typename T>
void dispList(T *lst, int len)
{
    for(int i = 0; i < len; ++i)
    {
        cout << *lst << " ";
        ++lst;
    }
    cout << endl;
}

#endif
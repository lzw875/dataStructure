#ifndef TOOLS_H
#define TOOLS_H
#include"heads.h"
using namespace std;

template<class T>
void displArray(T *lst, int len)
{
    for(int i = 0; i < len; ++i)
    {
        cout << lst[i] << " ";
        ++lst;
    }
    cout << endl;
}

#endif
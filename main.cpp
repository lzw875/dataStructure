#include "heads.h"
#include "sqList.hpp"
#include "linkLIst.hpp"
#include "sqStack.hpp"
#include "tools.h"
using namespace std;
int main()
{
    sqStack<int> *p = new sqStack<int>();
    for(int i = 0; i <10; ++i)
    {
        sqStack<int>::pushElem(p, i);
    }
    p->showElems();
    int e = 0;
    sqStack<int>::popElem(p, &e);
    cout << e << endl;
    p->showElems();
}
#include "heads.h"
#include "sqList.hpp"
#include "linkList.hpp"
#include "sqStack.hpp"
#include "linkStack.hpp"
#include "tools.h"
using namespace std;
int main()
{
    linkStack<int> *p = new linkStack<int>();
    for(int i = 0; i < 10; ++i)
    {
        p->pushElem(p, i);
    }
    p->showElems();
    cout << p->count << endl;
    int e = 99;
    linkStack<int>::popElem(p, &e);
    cout << e << endl;
    p->showElems();
}
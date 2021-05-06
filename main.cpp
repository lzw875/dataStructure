#include "heads.h"
#include "myList.hpp"
#include "tools.h"
using namespace std;

int main()
{
    // initial a myList class
    myList<int> *p = new myList<int>();
    // test setElem()
    int pSize = p->getSize();
    cout << p->getLength() << endl;
    for (int i = 0; i < p->getSize()-1; i++)
    {
        p->setElem(i, i);
    }
    p->showElems();
    // // test getElem()
    cout << p->getLength() << endl;
    int e;
    for (int i = 0; i < p->getLength(); ++i)
    {
        myList<int>::getElem(p, i, &e);
        cout << e << " ";
    }
    cout << endl;
    // // test listInsert()
    e = 9;
    myList<int>::listInsert(p, 3, &e);
    myList<int>::getElem(p, 0, &e);
    cout << e << endl;
    p->showElems();
    // // test listDelete()
    myList<int>::listDelete(p, 3, &e);
    cout << e << endl;
    p->showElems();
}
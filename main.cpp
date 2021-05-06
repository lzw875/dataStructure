#include"heads.h"
#include"myList.hpp"
#include"tools.h"
using namespace std;

int main()
{
    myList<int>* p = new myList<int>();
    cout << p->length << endl;
    dispList(p->data, p->size);
    // myList::getElem
    int* a = 0;
    cout << myList<int>::getElem(p, 0, a) << endl;
    int val[5] = {0};
    dispList(val, 5);
}
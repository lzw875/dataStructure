#include "heads.h"
#include "myList.hpp"
#include "linkLIst.hpp"
#include "tools.h"
using namespace std;

int main()
{
    // init a linkList
    linkList<int> *linkHeadNode = new linkList<int>(0);
    linkList<int> *l1 = new linkList<int>(0);
    linkList<int> *l2 = new linkList<int>(1);
    linkHeadNode->next = l1;
    l1->next = l2;
    int e = 9;
    linkList<int>::getElem(linkHeadNode, 1, &e);
    cout << e << endl;
    linkList<int>::showElems(linkHeadNode);
    e = 9;
    linkList<int>::inserElem(linkHeadNode, 2, &e);
    linkList<int>::showElems(linkHeadNode);
    e = 0;
    linkList<int>::deleteElem(linkHeadNode, 2, &e);
    linkList<int>::showElems(linkHeadNode);
    cout << e << endl;
}
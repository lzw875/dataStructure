#include "heads.h"
#include "myList.hpp"
#include "linkLIst.hpp"
#include "tools.h"
using namespace std;

int main()
{
    // init a linkList
    linkList<int> headNode;
    linkList<int>::creatListHead(&headNode, 20);
    linkList<int>::showElems(&headNode);
    linkList<int> *p = &headNode;
    linkList<int>::showElems(p);
    linkList<int>::clearListHead(p);
    linkList<int>::showElems(p);

}
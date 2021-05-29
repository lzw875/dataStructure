#include "heads.h"
#include "tools.h"
#include "sorted.hpp"
#include "biTree.hpp"
#include "searchAlgorithms.hpp"
using namespace std;


int main(int argc, char const *argv[])
{
    // int a[] = {0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
    int a[] = {9, 1, 5, 8, 3, 7, 4, 6, 2, 0};
    int len = end(a) - begin(a);
    sorted<int>::insertAscSort(a, len);
    displArray<int>(a, len);
}

#include "heads.h"
#include "tools.h"
#include "sorted.hpp"
#include "biTree.hpp"
#include "searchAlgorithms.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    int a[] = {0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
    int endIndex = end(a) - begin(a) - 1;
    cout << binarySearch<int>(a, endIndex, 99) << endl;
}

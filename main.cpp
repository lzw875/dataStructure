#include "heads.h"
#include "tools.h"
#include "sorted.hpp"
#include "biTree.hpp"
#include "searchAlgorithms.hpp"
using namespace std;


int main(int argc, char const *argv[])
{
    biTree<int> *root = new biTree<int>(0);
    int arr[] = {1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
    // int arr[] = {0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
    for (int e : arr)
    {
        cout << biTree<int>::insertBST(root, e) << ' ';
    }
    cout << endl;
}

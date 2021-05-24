#include "heads.h"
#include "tools.h"
#include "sorted.hpp"
#include "biTree.hpp"
using namespace std;
void testAddress(int *a)
{
    cout << "address: " << a << "  value: " << *a << endl;
    ++*a;
}
int main(int argc, char const *argv[])
{
    biTree<char> root;
    char str[] = "AB#D##C##";
    int end = sizeof(str) - 2;
    int ptr = 0;
    biTree<char>::creatBiTree(&root, str, &ptr, end);
    biTree<char>::preOrderTraverse(&root);
    return 0;
}

#include "heads.h"
#include "tools.h"
#include "sorted.hpp"
#include "biTree.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    biTree<char> root;
    char str[] = "AB#D##C##";
    int end = sizeof(str) - 2;
    int ptr = 0;
    biTree<char>::creatBiTree(&root, str, &ptr, end);
    // cout << root.data << endl;
    biTree<char>::preOrderTraverse(&root);
    return 0;
}

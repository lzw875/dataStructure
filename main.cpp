#include "heads.h"
#include "tools.h"
#include "sorted.hpp"
using namespace std;

int main()
{
    char *p = nullptr;
    cout << sizeof(p) << endl;
    cout << sizeof(*p) << endl;
    char str[16] = {0};
    cout << sizeof(str) << endl;
    cout << sizeof(&str[0]) << endl;
}
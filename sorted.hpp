#include "heads.h"
using namespace std;
template <typename ElemType>
class sorted
{
private:
public:
    const static int MAXSIZE = 10;
    ElemType data[MAXSIZE] = {9, 1, 5, 8, 3, 7, 4, 6, 2, 0};
    // ElemType data[MAXSIZE] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
    sorted(/* args */);
    ~sorted();
    static void swp(ElemType *e1, ElemType *e2);
    static void showElems(ElemType *arr, const int len);
    // Ascending sequence
    static void selectionSort(ElemType *arr, const int len);
    static void bubbleAscSort0(ElemType *arr, const int len);
    static void bubbleAscSort(ElemType *arr, const int len);
    static void bubbleAscSort2(ElemType *arr, const int len);

    // Descending sequence
    static void bubbleDesSort0(ElemType *arr, const int len);
    static void bubbleDesSort(ElemType *arr, const int len);
    static void bubbleDesSort2(ElemType *arr, const int len);
};

template <typename ElemType>
void sorted<ElemType>::selectionSort(ElemType *arr, const int len)
{
    for(int i = 0; i < len; ++i)
    {
        int ind = i;
        for (int j = i+1; j < len; j++)
        {
            if(arr[i] > arr[j])
                ind = j;
        }
        swp(&arr[i], &arr[ind]);
    }
}

template <typename ElemType>
void sorted<ElemType>::bubbleDesSort2(ElemType *arr, const int len)
{
    // 改进版冒泡排序算法
    // 通过设置flag使得，提前获知已经排序结束。
    bool breakFlag = false;
    for (int i = 0; i < len && !breakFlag; ++i)
    {
        cout << i << endl;
        breakFlag = true;
        for (int j = len - 1; j > i; --j)
        {
            if(arr[j-1] < arr[j])
            {
                breakFlag = false;
                swp(&arr[j-1], &arr[j]);
            }
        }
    }
}

template <typename ElemType>
void sorted<ElemType>::bubbleAscSort2(ElemType *arr, const int len)
{
    // 改进版冒泡排序算法
    bool breakFlag = false;
    for (int i = 0; i < len && !breakFlag; ++i)
    {
        breakFlag = true;
        for (int j = len - 1; j > i; --j)
        {
            if(arr[j-1] > arr[j])
            {
                breakFlag = false;
                swp(&arr[j-1], &arr[j]);
            }
        }
    }
}

template <typename ElemType>
void sorted<ElemType>::bubbleDesSort(ElemType *arr, const int len)
{
    // 真冒泡排序算法
    // 较小的数字如气泡一般慢慢浮出水面
    for (int i = 0; i < len; ++i)
    {
        for (int j = len - 1; j > i; --j)
        {
            if(arr[j-1] < arr[j])
            {
                swp(&arr[j-1], &arr[j]);
            }
        }
    }
}

template <typename ElemType>
void sorted<ElemType>::bubbleAscSort(ElemType *arr, const int len)
{
    for (int i = 0; i < len; ++i)
    {
        for (int j = len - 1; j > i; --j)
        {
            if(arr[j-1] > arr[j])
            {
                swp(&arr[j-1], &arr[j]);
            }
        }
    }
}

template <typename ElemType>
void sorted<ElemType>::bubbleDesSort0(ElemType *arr, const int len)
{
    // 初级的冒泡降序排序算法；
    // 从第1位开始，与剩余位逐位比较，比发现比当前第一位大的则交换。
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[i] < arr[j])
            {
                swp(&arr[i], &arr[j]);
            }
        }
    }
}

template <typename ElemType>
void sorted<ElemType>::bubbleAscSort0(ElemType *arr, const int len)
{
    // 初级的冒泡升序排序算法；
    // 同理降序
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[i] > arr[j])
            {
                swp(&arr[i], &arr[j]);
            }
        }
    }
}
template <typename ElemType>
void sorted<ElemType>::showElems(ElemType *arr, const int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

template <typename ElemType>
void sorted<ElemType>::swp(ElemType *e1, ElemType *e2)
{
    ElemType tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}

template <typename ElemType>
sorted<ElemType>::sorted(/* args */)
{
    // this->data = ;
}

template <typename ElemType>
sorted<ElemType>::~sorted()
{
}

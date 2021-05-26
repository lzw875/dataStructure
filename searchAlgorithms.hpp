#pragma once
#include "heads.h"
using namespace std;

// Declare Func
template <typename ElemType>
int sequentialSearch(ElemType *a, int endIndex, ElemType key);
template <typename ElemType>
int binarySearch(ElemType *a, int endIndex, ElemType key);

template <typename ElemType>
int binarySearch(ElemType *a, int endIndex, ElemType key)
{
    int low, hight, mid;
    low = 0;
    hight = endIndex;
    while (hight <= low)
    {
        mid = (hight + low) / 2;
        if (a[mid] > key)
        {
            hight = mid - 1;
        }
        else if (a[mid] < key)
        {
            low = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return NO_KEY;
};
// Define Func
/**
 * @brief 顺序搜索算法（哨兵版）
 * 
 * @tparam ElemType 
 * @param a 数组地址
 * @param endIndex 数组最后一个元素的索引
 * @param key 需要查找的键值
 * @return int 返回key在数组中的索引，若查找失败，则返回-1。
 */
template <typename ElemType>
int sequentialSearch(ElemType *a, int endIndex, ElemType key)
{
    // 如果首元素恰好为键值则返回0
    if (a[0] == key)
        return 0;

    // 改变a[0]的键值并设为哨兵
    ElemType e = a[0];
    a[0] = key;
    int i = endIndex;
    while (a[i] != key)
    {
        --i;
    }
    // 查找完毕
    // a[0]还原
    a[0] = e;
    // 若i=0，表示查找失败，返回-1.
    if (i == 0)
        return -1;
    return i;
};

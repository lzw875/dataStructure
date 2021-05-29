#include "heads.h"
using namespace std;
template <typename ElemType>
class sorted
{
private:
    static void merge(ElemType *arr0, ElemType *arr1, int fst, int m, int lst);
    static int partition(ElemType *arr, int fst, int lst);

public:
    const static int MAXSIZE = 10;
    ElemType data[MAXSIZE] = {9, 1, 5, 8, 3, 7, 4, 6, 2, 0};
    // ElemType data[MAXSIZE] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
    sorted(/* args */);
    ~sorted();
    static void swp(ElemType *e1, ElemType *e2);
    static void showElems(ElemType *arr, const int len);
    // Ascending sequence
    static void quickAscSort(ElemType *arr, const int &fst, const int &lst);
    static void mergeAscSort(ElemType *arrSrc, ElemType *arr1, const int fst, const int lst);
    static void shellAscSort(ElemType *arr, const int len);
    static void insertAscSort(ElemType *arr, const int len);
    static void selectionAscSort(ElemType *arr, const int len);
    static void bubbleAscSort0(ElemType *arr, const int len);
    static void bubbleAscSort(ElemType *arr, const int len);
    static void bubbleAscSort2(ElemType *arr, const int len);

    // Descending sequence
    static void bubbleDesSort0(ElemType *arr, const int len);
    static void bubbleDesSort(ElemType *arr, const int len);
    static void bubbleDesSort2(ElemType *arr, const int len);
};

template <typename ElemType>
int sorted<ElemType>::partition(ElemType *arr, int fst, int lst)
{
    ElemType pivotValue = arr[fst];
    while (fst < lst)
    {
        while (fst < lst && arr[lst] > pivotValue)
            lst--;
        swp(&arr[fst], &arr[lst]);
        while (fst < lst && arr[fst] < pivotValue)
            fst++;
        swp(&arr[fst], &arr[lst]);
    }
    return fst;
}

/**
 * @brief 快速排序算法
 * 
 * @tparam ElemType 
 * @param arr array
 * @param fst index of the first element from arr
 * @param lst index of the last
 */
template <typename ElemType>
void sorted<ElemType>::quickAscSort(ElemType *arr, const int &fst, const int &lst)
{
    int pivot; /*pivot: 枢轴*/
    if (fst < lst)
    {
        pivot = partition(arr, fst, lst);
        quickAscSort(arr, fst, pivot - 1);
        quickAscSort(arr, pivot + 1, lst);
    }
}

/**
 * @brief 数组归并，将arr0[fst, ..., m]和arr0[m+1, ..., lst]，合并到arr1中。
 * 
 * @tparam ElemType 
 * @param arr0
 * @param arr1 
 * @param fst 
 * @param m 
 * @param lst 
 */
template <typename ElemType>
void sorted<ElemType>::merge(ElemType *arr0, ElemType *arr1, int fst, int m, int lst)
{
    int j, k;
    for (j = m + 1, k = fst; fst <= m && j <= lst; ++k) // 将arr0中记录由小到大归并到arr1
    {
        if (arr0[fst] < arr0[j])
            arr1[k] = arr0[fst++];
        else
            arr1[k] = arr0[j++];
    }
    if (fst <= m) // 将剩余的arr0[fst, ..., m]复制到arr1
    {
        for (int l = 0; l <= m - fst; ++l)
            arr1[k + l] = arr0[fst + l];
    }
    if (j <= lst) // 将剩余的arr0[j, ..., lst]复制到arr1
    {
        for (int l = 0; l <= lst - j; ++l)
            arr1[k + l] = arr0[j + l];
    }
}

/**
 * @brief 归并排序算法
 * 
 * @tparam ElemType 
 * @param arrSource 
 * @param arr1 
 * @param fst 首元素的索引
 * @param lst 末尾元素索引
 */
template <typename ElemType>
void sorted<ElemType>::mergeAscSort(ElemType *arrSrc, ElemType *arr1, const int fst, const int lst)
{
    int m;
    ElemType arr2[lst + 1];
    // base case
    if (fst == lst)
        arr1[fst] = arrSrc[fst];
    else
    {
        m = (fst + lst) / 2;
        mergeAscSort(arrSrc, arr2, fst, m);
        mergeAscSort(arrSrc, arr2, m + 1, lst);
        merge(arr2, arr1, fst, m, lst);
    }
}

/**
 * @brief gap指两个数据的间隔，以gap为间隔遍历数组，对于违反顺序的两个数据将互换位置。
 * gap 会逐渐减小，继续遍历，直到gap=1。
 */
template <typename ElemType>
void sorted<ElemType>::shellAscSort(ElemType *arr, const int len)
{
    int gap = len;
    while (gap > 1)
    {
        gap = gap / 3 + 1;
        cout << "gap: " << gap << endl;
        for (int i = gap; i < len; i++)
        {
            if (arr[i] < arr[i - gap])
            {
                for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
                    swp(&arr[j], &arr[j + gap]);
            }
        }
    }
}

template <typename ElemType>
void sorted<ElemType>::insertAscSort(ElemType *arr, const int len)
{
    for (int i = 0; i + 1 < len; i++)
    {
        // 从未排序区域[i+1, len)，取第一个数 arr[i + 1]
        // 插入到已排序区域[0, i]，
        for (int j = 0; j <= i; j++)
        {
            // 轮训到比arr[i+1]更大的数后，两者交换位置，
            // 然后继续轮训，直到原已排区域全部轮训完。
            if (arr[i + 1] < arr[j])
                swp(&arr[i + 1], &arr[j]);
        }
    }
}

template <typename ElemType>
void sorted<ElemType>::selectionAscSort(ElemType *arr, const int len)
{
    for (int i = 0; i < len; ++i)
    {
        int ind = i;
        // 从未排序区域[i+1,len)，选择出最小值
        for (int j = i + 1; j < len; j++)
        {
            if (arr[ind] > arr[j])
                ind = j;
        }
        // 插入到已排序区域0到i
        if (ind != i)
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
            if (arr[j - 1] < arr[j])
            {
                breakFlag = false;
                swp(&arr[j - 1], &arr[j]);
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
            if (arr[j - 1] > arr[j])
            {
                breakFlag = false;
                swp(&arr[j - 1], &arr[j]);
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
            if (arr[j - 1] < arr[j])
            {
                swp(&arr[j - 1], &arr[j]);
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
            if (arr[j - 1] > arr[j])
            {
                swp(&arr[j - 1], &arr[j]);
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

#pragma once
#define OK 1
#define ERROR 0
#define NO_KEY 0
template <typename ElemType>
class biTree
{
private:
    /* data */
public:
    ElemType data;
    biTree<ElemType> *left = nullptr;
    biTree<ElemType> *right = nullptr;
    biTree(/* args */);
    ~biTree();
    biTree(const ElemType &e);
    static biTree<ElemType> *creatBiTree(biTree<ElemType> *root, char *str, int *ptr, int end);
    static void preOrderTraverse(biTree<ElemType> *root);
    static bool searchBST(biTree *root, ElemType key, biTree **retTree);
    static bool insertBST(biTree *root, ElemType key);
};

/**
 * @brief 向二插排序树插入节点
 * 
 * @tparam ElemType 
 * @param root 二插排序树的根节点
 * @param key 待插入的键值
 * @return true 插入成功
 * @return false 插入失败，键值已在树中
 */
template <typename ElemType>
bool biTree<ElemType>::insertBST(biTree *root, ElemType key)
{
    biTree<ElemType> *p = new biTree<ElemType>();
    if (!searchBST(root, key, &p))
    {

        p->data = key;
        // if (key > p->data)
            // p->right->data = key;
        // else
            // p->left->data = key;
        return OK;
    }
    else
        return ERROR;
}

/**
 * @brief 查找二叉排序树
 * 
 * @tparam ElemType 
 * @param root 二叉排序树的根节点
 * @param key 需要被查找的键值
 * @param retTree 查找成功则返回对应节点的地址，否则，二叉排序树的最末未节点
 * @return true 表示查找成功
 * @return false 表示没有查找到键值
 */
template <typename ElemType>
bool biTree<ElemType>::searchBST(biTree *root, ElemType key, biTree **retTree)
{
    // base case
    if (!root)
    {
        *retTree = root;
        return NO_KEY;
    }

    if (root->data == key)
    {
        *retTree = root;
        return OK;
    }
    else if (root->data > key)
        return searchBST(root->left, key, retTree);
    else
        return searchBST(root->right, key, retTree);
}

/**
 * @brief preOrderTraverse binary tree
 * 
 * @tparam ElemType 
 * @param root Address of binary tree
 */
template <typename ElemType>
void biTree<ElemType>::preOrderTraverse(biTree<ElemType> *root)
{
    if (root == nullptr)
        return;
    cout << root->data << endl;
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

/**
 * @brief Creat a binary tree by string(preorder)
 * 
 * @tparam ElemType 
 * @param root Address of binary tree
 * @param str String e.g. "AB#D##C##"
 * @param ptr Points to the character in the string
 * @param end The last index of string
 */
template <typename ElemType>
biTree<ElemType> *biTree<ElemType>::creatBiTree(biTree<ElemType> *root, char *str, int *ptr, int end)
{
    // base case
    if (str[*ptr] == '#' || *ptr > end)
    {
        delete root;
        return nullptr;
    }

    ElemType e = (ElemType)str[*ptr];
    root->data = e;
    root->left = new biTree<ElemType>();
    root->right = new biTree<ElemType>();
    ++*ptr;
    root->left = creatBiTree(root->left, str, ptr, end);
    ++*ptr;
    root->right = creatBiTree(root->right, str, ptr, end);
    return root;
}

template <typename ElemType>
biTree<ElemType>::biTree(const ElemType &e)
{
    data = e;
}

template <typename ElemType>
biTree<ElemType>::biTree(/* args */)
{
}

template <typename ElemType>
biTree<ElemType>::~biTree()
{
}

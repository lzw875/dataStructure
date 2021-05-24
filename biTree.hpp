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
};
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

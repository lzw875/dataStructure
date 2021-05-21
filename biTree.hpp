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
    static void creatBiTree(biTree<ElemType> *root, char *str, int *ptr, int end);
    static void preOrderTraverse(biTree<ElemType> *root);
};
/**
 * @brief 
 * 
 * @tparam ElemType 
 * @param root 
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
 * @brief 
 * 
 * @tparam ElemType 
 * @param root 
 * @param str 
 * @param ptr 
 * @param end 
 */
template <typename ElemType>
void biTree<ElemType>::creatBiTree(biTree<ElemType> *root, char *str, int *ptr, int end)
{
    // base case
    if (str[*ptr] == '#' || *ptr > end)
    {
        delete root;
        root = nullptr;
        return;
    }

    ElemType e = (ElemType)str[*ptr];
    root->data = e;
    root->left = new biTree<ElemType>();
    root->right = new biTree<ElemType>();
    ++*ptr;
    creatBiTree(root->left, str, ptr, end);
    ++*ptr;
    creatBiTree(root->right, str, ptr, end);
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
    delete this->left;
    delete this->right;
    delete &data;
}

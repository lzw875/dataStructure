template<typename ElemType>
class biTree
{
private:
    /* data */
public:
    ElemType data;
    biTree<ElemType>* left = nullptr;
    biTree<ElemType>* right = nullptr;
    biTree(/* args */);
    ~biTree();
    biTree(const ElemType &e);
    static void creatBiTree(biTree<ElemType>* root, char *str, int begin, int end);
};
template<typename ElemType>
void biTree<ElemType>::creatBiTree(biTree<ElemType>* root, char *str, int begin, int end)
{
    if(str[begin] == '#')
    {
        root = nullptr;
        return;
    }
    root->data = (ElemType)str[begin];
    creatBiTree(root->left, str, begin+1, end);
    // TODO
}

template<typename ElemType>
biTree<ElemType>::biTree(const ElemType &e)
{
    data = e;
}

template<typename ElemType>
biTree<ElemType>::biTree(/* args */)
{
}

template<typename ElemType>
biTree<ElemType>::~biTree()
{
}

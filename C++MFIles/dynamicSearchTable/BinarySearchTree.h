template <class KEY,class OTHER>
struct SET
{
    KEY key;
    OTHER other;
};
template <class KEY,class OTHER>
class BinarySearchTree:public dynamicSearchTable<KEY,OTHER>
{private:
struct BinaryNode
{
    SET<KEY,OTHER>data;
    BinaryNode *left,*right;
    BinaryNode(const SET<KEY,OTHER>&x,BinaryNode *lt=nullptr,BinaryNode *rt=nullptr)
    {
        data=x;
        left=lt;
        right=rt;
    }
    BinaryNode():left(nullptr),right(nullptr){};
    ~BinaryNode(){};
};
public:
BinarySearchTree();
~BinarySearchTree();
SET<KEY,OTHER>*find(const KEY &x)const;
void insert(const SET<KEY,OTHER>&x);
void remove(const KEY &x);
private:
void insert(const SET<KEY,OTHER>&x,BinaryNode *&t);
void remove(const KEY &x,BinaryNode *&t);
SET<KEY,OTHER>*find(const KEY &x,BinaryNode *t)const;
void makeEmpty(BinaryNode *&t);
BinaryNode *root;
};
template <class KEY,class OTHER>
BinarySearchTree<KEY,OTHER>::BinarySearchTree()
{
    root=nullptr;
}
template <class KEY,class OTHER>
BinarySearchTree<KEY,OTHER>::~BinarySearchTree()
{
    makeEmpty(root);
}

template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::makeEmpty(BinaryNode *&t)
{
    if(t==nullptr)
    return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
    t=nullptr;
}
template <class KEY,class OTHER>
SET<KEY,OTHER>*BinarySearchTree<KEY,OTHER>::find(const KEY &x)const
{
    return find(x,root);
}
template <class KEY,class OTHER>
SET<KEY,OTHER>*BinarySearchTree<KEY,OTHER>::find(const KEY &x,BinaryNode *t)const
{
    if(t==nullptr)
    return nullptr;
    if(x<t->data.key)
    return find(x,t->left);
    else if(x>t->data.key)
    return find(x,t->right);
    else
    return &(t->data);
}
template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::insert(const SET<KEY,OTHER>&x)
{
    insert(x,root);
}
template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::insert(const SET<KEY,OTHER>&x,BinaryNode *&t)
{
    if(t==nullptr)
    t=new BinaryNode(x);
    else if(x.key<t->data.key)
    insert(x,t->left);
    else if(x.key>t->data.key)
    insert(x,t->right);
    else
    t->data.other=x.other;
}
template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::remove(const KEY &x)
{
    remove(x,root);
}
template <class KEY,class OTHER>
void BinarySearchTree<KEY,OTHER>::remove(const KEY &x,BinaryNode *&t)
{
    if(t==nullptr)
    return;
    if(x<t->data.key)
    remove(x,t->left);
    else if(x>t->data.key)
    remove(x,t->right);
    else if(t->left!=nullptr&&t->right!=nullptr)
    {
        BinaryNode *tmp=t->right;
        while(tmp->left!=nullptr)
        tmp=tmp->left;
        t->data=tmp->data;
        remove(t->data.key,t->right);
    }
    else
    {
        BinaryNode *oldNode=t;
        t=(t->left!=nullptr)?t->left:t->right;
        delete oldNode;
    }
}
// Path: dynamicSearchTable\dynamicSearchTable.h
// Compare this snippet from dynamicSearchTable\dynamicSearchTable.h:
// template <class KEY, class OTHER>
// struct SET//集合元素的类型
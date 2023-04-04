#include "dynamicSearchTable.h"
template <class KEY, class OTHER>
class AvlTree : public dynamicSearchTable<KEY, OTHER>
{
private:
    struct AvlNode
    {
        AvlNode *left;
        AvlNode *right;
        int height;
        SET<KEY, OTHER> data;
        AvlNode(const SET<KEY, OTHER> &element, AvlNode *lt, AvlNode *rt, int h = 1) : data(element), left(lt), right(rt), height(h) {}
    };
    AvlNode *root; // 用一个指向根节点的指针来保存avl树
public:            // 一些向用户开放的公有函数
    AvlTree() { root = nullptr; }
    ~AvlTree() { makeEmpty(root); }
    SET<KEY, OTHER> *find(const KEY &x) const;
    void insert(const SET<KEY, OTHER> &x);
    void remove(const KEY &x);
private:
    void insert(const SET<KEY, OTHER> &x, AvlNode *&t); // 这里的AvlNode*&t的写法是为了将插入节点与其父节点相连接，下面的函数同理
    bool remove(const KEY &x, AvlNode *&t);
    void makeEmpty(AvlNode *t);
    int height(AvlNode *t) const { return t == nullptr ? 0 : t->height; }
    void LL(AvlNode *&t);
    void LR(AvlNode *&t);
    void RR(AvlNode *&t);
    void RL(AvlNode *&t);
    int max(int a, int b){return (a > b) ? a : b};
    bool adjust(AvlNode *&t, int subTree);
};
template <class KEY, class OTHER>
SET<KEY, OTHER> *AvlTree<KEY, OTHER>::find(const KEY &x) const
{
    AvlNode *t = root;
    while (t != nullptr && t->data.key != x)
    {
        if (t->data.key > x)
            t = t->left;
        else
            t = t->right;
    }
    if (t == nullptr)
        return nullptr;
    else
        return (SET<KEY, OTHER> *)t; // 强制类型转换，AvlNode结构体中包含SET<KEY,OTHER>
}

// LL单旋转，失去平衡的节点记为A，他的左儿子记为B，B的右子树变成A的左子树，A成为B的右儿子。
template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::LL(AvlNode *&t)
{
    AvlNode *t1 = t->left;
    t->left = t1->right;
    t1->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    t1->height = max(height(t1->left), height(t)) + 1;
    t = t1;
}

// RR单旋转，失去平衡的节点记为A，他的右儿子记为B，B的左子树变成A的右子树，A成为B的左儿子。
template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::RR(AvlNode *&t)
{
    AvlNode *t1 = t->right;
    t->right = t1->left;
    t1->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    t1->height = max(height(t1->right), height(t)) + 1;
    t = t1;
}

// LR双旋转，看作先对失去平衡的节点的左节点做RR旋转，再对失去平衡的节点做LL旋转
template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::LR(AvlNode *&t)
{
    RR(t->left);
    LL(t);
}

// RL双旋转，看作先对失去平衡的节点的右节点做LL旋转，再对失去平衡的节点做RR旋转
template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::RL(AvlNode *&t)
{
    LL(t->right);
    RR(t);
}
template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x)
{
    insert(x, root);
}
template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x, AvlNode *&t)
{
    if (t == nullptr) // 在空树上插入
        t = new AvlNode(x, nullptr, nullptr);
    else if (x.key < t->data.key) // 在左子树上插入
    {
        insert(x, t->left);
        if (height(t->left) - height(t->right) == 2)
            if (t->left->data.key < x.key)
                LL(t);
            else
                LR(t);
    }
    else if (x.key > t->data.key)
    {
        insert(x, t->right);
        if (height(t->right) - height(t->left) == 2)
            if (t->right->data.key > x.key)
                RR(t);
            else
                RL(t);
    }
    t->height = max(height(t->left), height(t->right)) + 1;
}
template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::remove(const KEY &x)
{
    remove(x->root);
}
template <class KEY, class OTHER>
bool AvlTree<KEY, OTHER>::remove(const KEY &x, AvlNode *&t)
{
    if (t == nullptr)
        return true;
    if (x == t->data.key)
    {
        if (t->left == nullptr || t->right == nullptr)
        {
            AvlNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
            return false;
        }
        else
        {
            AvlNode *tmp = t->right;
            while (tmp->left != nullptr)
            {
                tmp = tmp->left;
            }
            t->data = tmp->data;
            if (remove(tmp->data.key, t->right))
                return true;
            return adjust(t, 1);
        }
    }
    if (x < t->data.key) // delete from left child
    {
        if (remove(x, t->left))
            return true; // if the height of the left child remains
        return adjust(t, 0);
    }
    else // delete from right child
    {
        if (remove(x, t->right))
            return true; // if the height of the right child remains
        return adjust(t, 1);
    }
}

template <class KEY,class OTHER>
bool AvlTree<KEY,OTHER>::adjust(AvlNode*&t,int subTree)
{
    if(subTree)
    {
        if(height(t->left)-height(t->right)==1)return true;
        if(height(t->right)==height(t->left)){--t->height;return false;}
        if(height(t->left->right)>height(t->left->left))
        {
            LR(t);
            return false;
        }
        LL(t);
        if(height(t->right)==height(t->left))return false;else return true;
    }
    else
    {
        if(height(t->right)-height(t->left)==1)return true;
        if(height(t->right)==height(t->left)){--t->height;return false;}
        if(height(t->right->left)>height(t->right->right))
        {
            RL(t);
            return false;
        }
        RR(t);
        if(height(t->right)==height(t->left))return false;else return true;
    }
}

template<class KEY,class OTHER>
void AvlTree<KEY,OTHER>::makeEmpty(AvlNode*t)
{
    if(t==nullptr)return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
    t=nullptr;
}
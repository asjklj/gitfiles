#pragma once
#include "bTree.h"
#include "linkQueue.h"
#include <iostream>
using namespace std;
template <class T>
class binaryTree : public bTree<T>
{
 template <class T1> friend void printTree(const binaryTree<T1> &t, T1 flag);
private:
    struct Node
    {
        Node *left, *right;
        T data;
        Node() : left(nullptr), right(nullptr){};
        Node(T item, Node *ll = nullptr, Node *rr = nullptr) : data(item), left(ll), right(rr){};
        ~Node(){};
        /* data */
    };
    Node *root;
public:
    binaryTree() : root(nullptr){};
    binaryTree(T x) { root=new Node(x); }
    ~binaryTree();
    void clear();
    bool isEmpty() const;
    T Root(T flag) const;
    T lchild(T x, T flag) const;
    T rchild(T x, T flag) const;
    void delLeft(T x);
    void delRight(T x);
    void preOrder() const;
    void midOrder() const;
    void postOrder() const;
    void levelOrder() const;
    void createTree(T flag);
    T parent(T x, T flag) const { return flag; };
    void exchange();
private:
    // 因二叉树实现中包括递归操作，需要一个递归终止条件-根节点，但用户不需要知道，故使用包裹函数方便用户使用
    Node *find(T x, Node *t) const;
    void clear(Node *&t);
    void preOrder(Node *t) const;
    void midOrder(Node *t) const;
    void postOrder(Node *t) const;
    void exchange(Node*t);
};

template <class T>
bool binaryTree<T>::isEmpty() const
{
    return (root == nullptr);
}
template <class T>
T binaryTree<T>::Root(T flag) const
{
    if (root == nullptr)
        return flag;
    else
        return (root->data);
}
template <class T>
void binaryTree<T>::clear(binaryTree<T>::Node *&t)
{
    if (t == nullptr)
        return; // 递归条件写在函数开头
    clear(t->left);
    clear(t->right);
    delete t;
    t = nullptr;
}
template <class T>
void binaryTree<T>::clear()
{
    clear(root);
}
template <class T>
binaryTree<T>::~binaryTree()
{
    clear(root);
}
template <class T>
void binaryTree<T>::preOrder(binaryTree<T>::Node *t) const
{
    if (t == nullptr)
        return;
    cout << t->data << " ";
    preOrder(t->left);
    preOrder(t->right);
}
template <class T>
void binaryTree<T>::preOrder()const
{
    cout <<"\n前序遍历:";
    preOrder(root);
}
template <class T>
void binaryTree<T>::midOrder(binaryTree<T>::Node *t) const
{
    if (t == nullptr)
        return;
    midOrder(t->left);
    cout << t->data << " ";
    midOrder(t->right);
}
template<class T>
void binaryTree<T>::midOrder()const
{
    cout <<"\n中序遍历:";
    midOrder(root);
}
template <class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node *t) const
{
    if (t == nullptr)
        return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << " ";
}
template <class T>
void binaryTree<T>::postOrder()const
{
    cout <<"\n后序遍历:";
    postOrder(root);
}
template <class T>
void binaryTree<T>::levelOrder() const
{
    cout <<"\n层次遍历:";
    linkQueue <Node *> que;
    que.enQueue(root);
    Node *tmp;
    while (!que.isEmpty())
    {
        tmp = que.deQueue();
        cout << tmp->data<<" ";
        if (tmp->left)
            que.enQueue(tmp->left);
        if (tmp->right)
            que.enQueue(tmp->right);
    }
}
template <class T>
struct binaryTree<T>::Node *binaryTree<T>::find(T x, binaryTree<T>::Node *t) const
{
    Node *tmp;
    if (t == nullptr)
        return nullptr;
    if (t->data == x)
        return t;
    if (tmp = find(x, t->left))
        return tmp;
    else
        return find(x, t->right);
}
template <class T>
void binaryTree<T>::delLeft(T x)
{
    Node *tmp = find(x, root);
    if (tmp == nullptr)
        return;
    clear(tmp->left);
}
template <class T>
void binaryTree<T>::delRight(T x)
{
    Node *tmp = find(x, root);
    if (tmp == nullptr)
        return;
    clear(tmp->right);
}
template <class T>
T binaryTree<T>::lchild(T x, T flag) const
{
    Node *tmp = find(x, root);
    if (tmp == nullptr || tmp->left == nullptr)
        return flag;
    return tmp->left->data;
}
template <class T>
T binaryTree<T>::rchild(T x, T flag) const
{
    Node *tmp = find(x, root);
    if (tmp == nullptr || tmp->right == nullptr)
        return flag;
    return tmp->right->data;
}
template <class T>
void binaryTree<T>::createTree(T flag)
{
    linkQueue<Node *> que;
    Node *tmp;
    T x, lData, rData;
    cout << "输入根节点" << endl;
    cin >> x;
    root = new Node(x);
    que.enQueue(root);
    while (!que.isEmpty())
    {
        tmp = que.deQueue();
        cout << "输入" << tmp->data << "的两个儿子" << endl;
        cin >> lData >> rData;
        if (lData != flag)
            que.enQueue(tmp->left = new Node(lData));
        if (rData != flag)
            que.enQueue(tmp->right = new Node(rData));
    }
    cout << "创建树完成" << endl;
}
template <class T>
void printTree(const binaryTree<T> &t, T flag)
{
    linkQueue<T> q;
    q.enQueue(t.root->data);
    cout << endl;
    while ((!q.isEmpty()))
    {
        char p, l, r;
        p=q.deQueue();
        l = t.lchild(p, flag);
        r = t.rchild(p, flag);
        cout << p << " " << l << " " << r << endl;
        if (l != '@')
            q.enQueue(l);
        if (r != '@')
            q.enQueue(r);
    }
}
template <class T>
void binaryTree<T>::exchange(Node *t)
{  
    if(t==nullptr||(t->left==nullptr&&t->right==nullptr))return;
    else if(t->right!=nullptr&&t->left!=nullptr)
    {
        Node*tmp1=t->right;
        t->right=t->left;
        t->left=tmp1;
    }
    else if(t->right!=nullptr)
    {
        Node*tmp1=t->right;
        t->right=nullptr;
        t->left=tmp1;
    }
    else
    {
        Node*tmp2=t->left;
        t->left=nullptr;
        t->right=tmp2;
    }
    exchange(t->left);
    exchange(t->right);
}
template <class T>
void binaryTree<T>::exchange()
{
    exchange(root);
}
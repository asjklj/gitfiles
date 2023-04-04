#include "list.h"
template <class elemType>
class sLinkList : public list<elemType>
{
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *n = NULL)
        {
            data = x;
            next = n;
        };
        node() : next(NULL) {}
        ~node() {}
        /* data */
    };

    node *head;
    int currentLength;
    node *move(int i) const;

public:
    sLinkList();
    ~sLinkList()
    {
        clear();
        delete head;
    }
    void clear();
    int length() const { return currentLength; }
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
    void reverse();
};

template <class elemType>
sLinkList<elemType>::sLinkList()
{
    head = new node;
    currentLength = 0;
}

template <class elemType>
void sLinkList<elemType>::clear()
{
    node *p = head->next;
    node *q;
    head->next = nullptr;
    while (p != nullptr)
    {
        q = p->next;
        delete p;
        p = q;
    }
    currentLength = 0;
}

template <class elemType>
struct sLinkList<elemType>::node * sLinkList<elemType>::move(int i) const
{
    node *p = head;
    while (i-- >= 0 && p)
        p = p->next;
    return p;
}

template <class elemType>
void sLinkList<elemType>::insert(int i, const elemType &x)
{
    node *pos;
    if (i < 0)
        return;
    pos = move(i - 1);
    if (pos)
    {
        pos->next = new node(x, pos->next);
        currentLength++;
    }
}

template <class elemType>
void sLinkList<elemType>::remove(int i)
{
    if (i < 0)
        return;
    node *pos = move(i - 1);
    if (!pos || !pos->next)
        return;
    node *p = pos->next;
    pos->next = p->next;
    delete p;
    --currentLength;
}

template <class elemType>
int sLinkList<elemType>::search(const elemType &x) const
{
    node *p = head->next;
    int i = 0;
    while (p != nullptr && p->data != x)
    {
        p = p->next;
        i++;
    }
    if (p == nullptr)
        return (-1);
    else
        return (i);
}

template <class elemType>
elemType sLinkList<elemType>::visit(int i) const
{
    return (move(i)->data);
}

template <class elemType>
void sLinkList<elemType>::traverse() const
{
    node *p = head->next;
    while (p != nullptr)
    {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}


// 第一种思路，交换值而不改变方向（换汤不换药）
// template <class elemType>
// void sLinkList<elemType>::reverse()
// {
//     int i = 0;
//     if (currentLength == 0 || currentLength == 1)
//         return;
//     while (i < (currentLength - 1) / 2)
//     {
//         node *s1 = move(i);
//         node *s2 = move(currentLength - 1 - i);
//         elemType tmp;
//         tmp = s1->data;
//         s1->data = s2->data;
//         s2->data = tmp;
//         ++i;
//     }
// }

//第二种思路，只改变方向而不改变值
template <class elemType>
void sLinkList<elemType>::reverse()
{
    node*tmp;
    node*prev=NULL;
    node*cur=head;
    while(cur){
        tmp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=tmp;
    }
    cur=new node();
    cur->next=prev;
    head=cur;
}
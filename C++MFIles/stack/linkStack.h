#include "stack.h"
template <class elemType>
class linkStack:public stack<elemType>
{
    private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x,node*N=nullptr)
        {
            data=x;
            next=N;
        }
        node()
        {
            next=nullptr;
        }
        ~node(){}
        /* data */
    };
    node*top_p;
    public:
    linkStack( );
    ~linkStack();
    bool isEmpty()const;
    void push(const elemType&x);
    elemType pop();
    elemType top()const;
};

template <class elemType>
linkStack<elemType>::linkStack()
{
    top_p=nullptr;
}

template <class elemType>
linkStack<elemType>::~linkStack()
{
    node*tmp;
    while(top_p!=nullptr)
    {
        tmp=top_p;
        top_p=top_p->next;
        delete tmp;
    }
}

template <class elemType>
bool linkStack<elemType>::isEmpty()const
{
    return(top_p==nullptr);
}
template<class elemType>
void linkStack<elemType>::push(const elemType&x)
{
    top_p=new node(x,top_p);
}
template<class elemType>
elemType linkStack<elemType>::pop()
{
    node*tmp=top_p;
    top_p=top_p->next;
    elemType m=tmp->data; 
    delete tmp;
    return m;
}
template<class elemType>
elemType linkStack<elemType>::top()const
{
    return(top_p->data);
}

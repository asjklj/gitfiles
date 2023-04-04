//队列的单链表实现
//使用头尾指针
#pragma once
#include "queue.h"
template <class elemType>
class linkQueue:public queue<elemType>
{
private:
struct node
{
    elemType data;
    node*next;
    node(const elemType &x,node* p=nullptr)
    {
        data=x;
        next=p;
    }
    node():next(nullptr){};
    ~node(){};
    /* data */
};
node*front,*rear;
public:
elemType flag;
linkQueue();
~linkQueue();
bool isEmpty()const;
void enQueue(const elemType &x);
elemType deQueue();
elemType getHead()const;
};
template <class elemType>
linkQueue<elemType>::linkQueue()
{
    front=rear=nullptr;
}

template <class elemType>
linkQueue<elemType>::~linkQueue()
{
    node*tmp;
    while(front!=rear)
    {
        tmp=front;
        front=front->next;
        delete tmp;
    }
}
template <class elemType>
bool linkQueue<elemType>::isEmpty()const
{
    return(front==nullptr);
}

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x)
{
if(rear==nullptr)
front=rear=new node(x);
else 
rear=rear->next=new node(x);
}

template <class elemType>
elemType linkQueue<elemType>::deQueue()
{ 
    node*tmp=front;
   elemType m=tmp->data;
    front=front->next;
    if(front==nullptr)rear=nullptr;    
    delete tmp;
    return m;
}

template <class elemType>
elemType linkQueue<elemType>::getHead()const
{
    return(front->data);
}
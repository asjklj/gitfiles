#include "queue.h"
template <class elemType>
class seqQueue:public queue
{
    private:
    int maxSize;
    int front,rear;
    elemType*elem;
    void doubleSpace();
    public:
    seqQueue(int initSize=10);
    ~seqQueue();
    void enQueue(const elemType &x);
    bool isEmpty()const;
    elemType deQueue();
    elemType getHead();
};

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType&x)
{
    if((rear+1)%maxSize==front)doubleSpace();
    rear=(rear+1)%maxSize;
    elem[rear]=x;
}
template<class elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType*tmp=elem;
    elem=new int [2*maxSize];
    for(int i=1;i<=maxSize;i++)
    {
        elem[i]=tmp[(front+i)%maxSize];
    }
    front=0;
    rear=maxSize;
    maxSize*=2;
    delete tmp;
}
template <class elemType>
seqQueue<elemType>::seqQueue(int initSize)
{
    elem=new elemType(initSize);
    maxSize=initSize;
    front=rear=0;
}
template <class elemType>
seqQueue<elemType>::~seqQueue()
{
    delete [] elem;
    maxSize=0;
    front=rear=0;
}
template <class elemType>
bool seqQueue<elemType>::isEmpty()const
{
    return(front==rear);
}
template <class elemType>
elemType seqQueue<elemType>::deQueue()
{
    front=(front+1)%maxSize;
    return(elem[front]);
}
template <class elemType>
elemType seqQueue<elemType>::getHead()
{
    return(elem[(front+1)%maxSize]);
}
#pragma once
template <class elemType>
class queue
{
    public:
    virtual ~queue()=0;
    virtual bool isEmpty()const=0;
    virtual void enQueue(const elemType&x)=0;
    virtual elemType deQueue()=0;
    virtual elemType getHead()const=0;
};
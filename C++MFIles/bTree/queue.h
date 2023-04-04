#pragma once
template <class elemType>
class queue
{
    public:
    virtual bool isEmpty()const=0;
    virtual void enQueue(const elemType&x)=0;
    virtual elemType deQueue()=0;
    virtual elemType getHead()const=0;
    virtual ~queue(){};
};
#include "stack.h"
template <class elemType>
class seqStack:public stack<elemType>
{
private:
elemType*elem;
int top_p;
int maxSize;
void doubleSpace();

public:
seqStack(int initSize=10);
~seqStack();
bool isEmpty()const;
void push(elemType&x);
elemType pop();
elemType top_pop()const;
};

template <class elemType>
seqStack<elemType>::seqStack(int initSize)
{
elem=new elemType[initSize];
top_p=-1;
int maxSize=initSize;
}

template <class elemType>
void seqStack<elemType>::doubleSpace(){
    elemType*tmp=elem;
    elem=new elemType[2*maxSize];
    for(int i=0;i<maxSize;i++){
        elem[i]=tmp[i];
    }
    maxSize*=2;
    delete [] tmp;
}

template<class elemType>
bool seqStack<elemType>::isEmpty()const
{
if(top_p=-1)return 1;
else return 0;
}

template <class elemType>
void seqStack<elemType>::push(elemType&x)
{
    if(top_p=maxSize-1)
    {
        doubleSpace();
    }
    ++top_p;
    elem[top_p]=x;
}

template <class elemType>
elemType seqStack<elemType>::pop()
{        
    if(isEmpty)return;
    
    else 
    {
    elemType m=top_pop()
    --top_p;
    return m;
    }
}

template <class elemType>
elemType seqStack<elemType>::top_pop()const{
    return (elemType[top_p]);
}

template <class elemType>
seqStack<elemType>::~seqStack(){
    delete []elem;
    top_p=-1;
}
#include "queue.h"
template <class Type>
class priorityQueue:public queue<Type>
{
    public:
    priorityQueue(int capacity=100);
    priorityQueue(const Type data[],int size);
    ~priorityQueue();
    bool isEmpty()const;
    void enQueue(const Type&x);
    Type deQueue();
    Type getHead()const;
    private:
    int currentSize;
    Type*array;
    int maxSize;
    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);
};
template <class Type>
priorityQueue<Type>::priorityQueue(int capacity=100)
{
    array=new Type[capacity];
    maxSize=capacity;
    currentSize=0;
}
template <class Type>
priorityQueue<Type>::~priorityQueue()
{
    delete []array;
}
template <class Type>
bool priorityQueue<Type>::isEmpty()const
{
    return currentSize==0;
}
template <class Type>
Type priorityQueue<Type>::getHead()const
{
    return array[1];
}
template <class Type>
void priorityQueue<Type>::doubleSpace()
{
    Type *tmp=array;
    array=new Type[maxSize*2];
    for (int i=0;i<maxSize;i++)
    {
        array[i]=tmp[i];
    }
    delete []tmp;
}
template <class Type>
void priorityQueue<Type>::enQueue(const Type&x)
{
    if(currentSize==maxSize-1)doubleSpace();
    currentSize++;
    int hole=currentSize;
    for(;hole>1&&x<array[hole/2];hole/=2)
    {
        array[hole]=array[hole/2];
    }
    array[hole]=x;
}
template <class Type>
void priorityQueue<Type>::percolateDown(int hole)
{
    int child;
    Type tmp=array[hole];
    for(;hole*2<currentSize;hole=child)
    {
        child=hole*2;
        if(child!=currentSize&&array[child+1]<array[child])
        {
            child++;
        }
        if(array[child]<tmp)array[hole]=array[child];
        else break;
    }
    array[hole]=tmp;
}
template <class Type>
Type priorityQueue<Type>::deQueue()
{
    Type minItem;
    minItem=array[1];
    array[1]=array[currentSize--];
    percolateDown(1);
    return minItem;
}
template <class Type>
void priorityQueue<Type>::buildHeap()
{
    for(int i=currentSize/2;i>=1;i--)
    {
        percolateDown(i);
    }
}
template <class Type>
priorityQueue<Type>::priorityQueue(const Type data[],int size)
{
    maxSize=size+10;
    array= new Type[maxSize];
    currentSize=size;
    for(int i=0;i<size;i++)
    {
        array[1+i]=data[i];
    }
    buildHeap();
}
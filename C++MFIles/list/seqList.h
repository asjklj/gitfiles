#include "list.h"
#include <iostream>
using namespace std;
template <class elemType>
class seqList : public list<elemType>
{
private:
    elemType *data;
    int currentLength;
    int maxSize;
    void doubleSpace();

public:
    seqList(int initSize = 10);
    ~seqList() { delete[] data; };
    void clear(){currentLength = 0;};
    int length() const { return currentLength; };
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
};

// 构造
template <class elemType>
seqList<elemType>::seqList(int initSize)
{
    data = new elemType[initSize];
    currentLength = 0;
    maxSize = initSize;
}

// 扩容（私有）
template <class elemType>
void seqList<elemType>::doubleSpace()
{
    elemType *temp = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for (int i = 0; i < currentLength; ++i)
    {
        data[i] = temp[i];
    }
    delete[] temp;
}
// 插入
template <class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
    if (i > (currentLength) || i < 0)
        throw OutOfBound();
    if (currentLength == maxSize)
        doubleSpace();
    for (int j = currentLength; j >i; j--)
        data[j] = data[j - 1];
    data[i] = x;
    currentLength++;
}
//删除
template <class elemType>
void seqList<elemType>::remove(int i)
{
    if (i < 0 || i > currentLength - 1)
        throw OutOfBound();
    for (int j = i; j < currentLength; j++)
        data[j] = data[j + 1];
    currentLength--;
}
//查找
template <class elemType>
int seqList<elemType>::search(const elemType &x) const
{
    int i = 0;
    for (i = 0; i < currentLength && data[i] != x; i++)
        ;
    if (i == currentLength)
        return (-1);
    else
        return (i);
}
//访问
template <class elemType>
elemType seqList<elemType>::visit(int i) const
{
    if (i < 0 || i > currentLength - 1)
        throw OutOfBound();
    return (data[i]);
}
//遍历
template <class elemType>
void seqList<elemType>::traverse() const
{
    for (int i = 0; i < currentLength; i++)
    {
        cout << data[i] ;
    }
    cout <<endl;
}
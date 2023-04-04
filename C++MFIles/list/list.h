#ifndef List_H
#define List_H
template <class elemType>
class list{
    public:
    virtual void clear()=0;//to clear all the items in the list
    virtual int length() const=0;//return the length(the number of the items) of the list
    virtual void insert(int i,const elemType&x)=0;//insert x into the location i in the list
    virtual void remove(int i)=0;//remove the item in the location i
    virtual int search(const elemType&x)const =0;//to look for x in the list and return the position
    virtual elemType visit(int i)const =0;//return the item in the location i in the list
    virtual ~list(){};//to free the space of the list
};

class OutOfBound{

};

#endif
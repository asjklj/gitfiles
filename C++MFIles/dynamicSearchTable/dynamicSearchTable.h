template <class KEY, class OTHER>
struct SET//集合元素的类型
{
    KEY key;
    OTHER other;
    /* data */
};

template <class KEY, class OTHER>
class dynamicSearchTable//动态查找表抽象类
{
public:
    virtual SET<KEY, OTHER> *find(const KEY &x) const = 0;
    virtual void insert(const SET<KEY, OTHER> &x) = 0;
    virtual void remove(const KEY &x) = 0;
    virtual ~dynamicSearchTable(){};
};

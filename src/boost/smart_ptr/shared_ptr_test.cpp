#include <boost/shared_ptr.hpp>
#include <cassert>
#include <iostream>

class A
{
    boost::shared_ptr<int> no_;

  public:
    A(boost::shared_ptr<int> no) : no_(no) {}

    void value(int i)
    {
        *no_ = i;
    }
};

class B
{
    boost::shared_ptr<int> no_;

  public:
    B(boost::shared_ptr<int> no) : no_(no) {}
    int value() const
    {
        return *no_;
    }
};

int main()
{
    boost::shared_ptr<int> temp(new int(4));
    A a(temp);
    B b(temp);

    assert(temp.use_count() == 3);

    std::cout << b.value() << std::endl;
    assert(b.value() == 4);

    a.value(28);
    assert(b.value() == 28);

    return 0;
}